#include "codeeditor.h"
#include "ui_codeeditor.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QScrollBar>
#include <QTabWidget>
#include <unistd.h>
#include "QDebug"
#include "interpretercore.h"

#include "widgets/geisttextedit.h"

GeistTextEdit *currentEditorWidget = NULL;

CodeEditor::CodeEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CodeEditor)
{
    numBlocks = 1;
    newNumBlocks = 0;
    outputMode = 0;
    foundPosElement = 0;
    searchTermLen = 0;

    outputModeP = &outputMode;  //  0 = ascii, 1 = hex, 2 = strings

    filename = "";              // Name Of File In Current Tab
    lineColor = QColor(7, 54, 66);

    // UI Setup
    ui->setupUi(this);

    // Style Sheet
    this->setWindowTitle("Geist");
    ui->menuBar->setStyleSheet("color:white; background-color:#262626; QMenuBar::item {background:black;}");
    ui->centralWidget->layout()->setContentsMargins(0,0,0,0);

    // Disbale manual scrolling for line numbers
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Hide Search Bar By Default
    ui->findReplaceBar->hide();
    ui->replaceLineEdit->hide();
    ui->replaceButton->hide();
    ui->replaceAllButton->hide();
    ui->replaceLabel->hide();

    // Create And Setup Initial Tab
    newTab();

    completer=new QCompleter(this);
//    QFile data(":/file.xml");
    completer->setModel(modelFromFile(":/WordList/wordlist.txt"));
    completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setWrapAround(false);
    currentEditorWidget->setCompleter(completer);

    // Set Theme From Settings
    theme = settings.value("theme", "monokai").toString();
    if (theme == "monokai"){
        on_actionDark_triggered();
    } else if (theme == "solarized"){
        on_actionSolarized_triggered();
    } else if (theme == "solarizedDark"){
        on_actionSolarized_Dark_triggered();
    } else if (theme == "tomorrow"){
        on_actionTommorrow_triggered();
    } else if (theme == "tomorrowNight"){
        on_actionTommorrow_Night_triggered();
    }


    connect(currentEditorWidget, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
    currentEditorWidget->setFocus();
    highlightCurrentLine();

    ui->listWidget->addItem("1");
    QListWidgetItem *item = ui->listWidget->item(numBlocks-1);
    item->setSizeHint(QSize(item->sizeHint().height(), 14));

    // Setup Window Based On User's Settings

    // Set Window Size
    int windowWidth = settings.value("windowWidth", 1000).toInt();
    int windowHeight = settings.value("windowHeight", 600).toInt();
    CodeEditor::resize(windowWidth, windowHeight);

    // Show/Hide Overview
    if (!settings.value("showOverview", true).toBool()){
        ui->fileOverview->hide();
    }

    currentDirectory = files.getHomeDir();

    // Open Files From List Saved In Settings
    QStringList openFiles;
    openFiles = settings.value("openFilesList").toStringList();

    if (!openFiles.isEmpty()){
        for (int i = 0; i < openFiles.length(); i++){
            open(openFiles.at(i));
        }
    }

}

CodeEditor::~CodeEditor()
{
    QRect windowRect = CodeEditor::normalGeometry();
    settings.setValue("windowWidth", windowRect.width());
    settings.setValue("windowHeight", windowRect.height());


    // Save List Of Files Open In Editor
    QStringList fileList;
    int numOpenFiles = ui->tabWidget->count();

    for (int i = 0; i < numOpenFiles; i++){
        ui->tabWidget->setCurrentIndex(i);
        fileList.append(currentEditorWidget->getFilepath());
    }
    settings.setValue("openFilesList", fileList);

    delete ui;
}

/*
 *****************************
 *         Tabs              *
 *****************************
*/

// Switch Tab
void CodeEditor::on_tabWidget_currentChanged(int index)
{
    if (currentEditorWidget != 0){
        disconnect(currentEditorWidget, SIGNAL(blockCountChanged(int)), this, SLOT(onBlockCountChanged(int)));
        disconnect(currentEditorWidget, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
    }

    currentEditorWidget = qobject_cast<GeistTextEdit *>(ui->tabWidget->widget(index));
    newNumBlocks = currentEditorWidget->document()->blockCount();

    QObject::connect(currentEditorWidget->verticalScrollBar(), SIGNAL(valueChanged(int)), ui->listWidget->verticalScrollBar(), SLOT(setValue(int)));
    QObject::connect(currentEditorWidget->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(scrollOverview(int)));
    connect(currentEditorWidget, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
    updateLineNums(newNumBlocks);
    connect(currentEditorWidget, SIGNAL(blockCountChanged(int)), this, SLOT(onBlockCountChanged(int)));
    connect(currentEditorWidget, SIGNAL(textChanged()), this, SLOT(onTextChanged()));
    ui->fileOverview->setPlainText(currentEditorWidget->toPlainText());

    filename = currentEditorWidget->getFilepath();

    ui->labelFileType->setText(currentEditorWidget->getFileType().toUpper());
    foundPositions.clear();

    foundPosElement = 0;

    highlightCurrentLine();

}

// Close Tab
void CodeEditor::on_tabWidget_tabCloseRequested(int index)
{
    if (ui->tabWidget->count() < 2){
        newTab();
    }

    // delete highlighter
    ui->tabWidget->setCurrentIndex(index);
    currentEditorWidget->setHighlighter(NULL);

        // Set the new current tab
        if (index > 0){
            ui->tabWidget->setCurrentWidget(ui->tabWidget->widget(index - 1));
        } else {
            ui->tabWidget->setCurrentWidget(ui->tabWidget->widget(index + 1));
        }


        // Delete the tab
        delete ui->tabWidget->widget(index);

        // Update filename to correspond to new current tab
        filename = currentEditorWidget->getFilepath();

}

// Create New Tab
void CodeEditor::newTab(){
    if (ui->tabWidget->count() < 50){
        ui->tabWidget->addTab(new GeistTextEdit, "New File");
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
        ui->tabWidget->setTabToolTip(ui->tabWidget->currentIndex(), "");
        filename = "";

        setTabWidth(settings.value("tabWidth", 4).toInt());
        currentEditorWidget->setWordWrapMode(QTextOption::NoWrap);
    }
}

void CodeEditor::on_actionNew_triggered()
{
    CodeEditor::newTab();
}

/*
 *****************************
 *         Files             *
 *****************************
*/

QString CodeEditor::getFileType(QString file){
    QStringList dotSplit = file.split(".");
    if (dotSplit.length() > 1)
        return dotSplit.last();
    else
        return "";
}

/*
 *  Open file
 *  Opens in new tab unless current tab is empty
 *  If file does not exist it will be created on save
*/
void CodeEditor::open(QString file){

    if (file != ""){

        if (filename != "" || currentEditorWidget->toPlainText() != ""){
            newTab();
        }

        filename = file;
        QString filetype = getFileType(file);
        currentEditorWidget->setPlainText(files.read(filename));

        currentEditorWidget->setFilePath(filename);
        currentEditorWidget->setFileType(filetype);
        currentEditorWidget->setHighlighter(new Highlighter(filetype, theme, currentEditorWidget->document() ));

        if (filename.length() >= 21){
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), filename.right(21));
        } else {
            ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), filename);
        }

        ui->tabWidget->setTabToolTip(ui->tabWidget->currentIndex(), filename);
        ui->labelFileType->setText(filetype.toUpper());

        ui->textBrowser->setText("");
        *outputModeP = 0;
        currentDirectory = files.getDirectory(filename);
    }
}

void CodeEditor::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), currentDirectory, tr("All (*)"));
    open(file);
}

// Save File
void CodeEditor::save(){
    if (filename == "" || *outputModeP != 0){
        on_actionSave_as_triggered();
    } else {
        files.write(filename, currentEditorWidget->toPlainText());
        ui->textBrowser->setText("Saved");
    }
}

void CodeEditor::on_actionSave_triggered()
{
    CodeEditor::save();
}

void CodeEditor::on_actionSave_as_triggered()
{
    filename = QFileDialog::getSaveFileName(this, tr("Save As"), currentDirectory, tr("All (*)"));
    QString filetype = getFileType(filename);

    if (filename != ""){
        files.write(filename, currentEditorWidget->toPlainText());

        currentEditorWidget->setFilePath(filename);
        currentEditorWidget->setFileType(filetype);
        currentEditorWidget->setHighlighter(new Highlighter(filetype, theme, currentEditorWidget->document() ));

        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), filename.right(21));
        ui->tabWidget->setTabToolTip(ui->tabWidget->currentIndex(), filename);
        ui->labelFileType->setText(filetype.toUpper());

        ui->textBrowser->setText("Saved");
       }
}

/*
 *****************************
 *         Searching         *
 *****************************
*/

// Toggle Find Bar
void CodeEditor::on_actionFind_triggered()
{
    if (ui->findReplaceBar->isHidden()){
        ui->findReplaceBar->show();
        ui->findLineEdit->setFocus();
    } else {
        if (ui->replaceLineEdit->isHidden()){
            ui->findReplaceBar->hide();
            currentEditorWidget->setFocus();
        } else {
            ui->replaceLineEdit->hide();
            ui->replaceButton->hide();
            ui->replaceAllButton->hide();
            ui->replaceLabel->hide();
        }

    }
}

// Find All Instances Of Search Term And Cycles Through Them
void CodeEditor::on_findLineEdit_returnPressed()
{
    if (ui->findLineEdit->text() == currentSearchTerm){
            findNext();

    } else {
        QString searchTerm = ui->findLineEdit->text();
        currentSearchTerm = searchTerm;
        searchTermLen = searchTerm.length();

        if (searchTermLen > 0){
            QString found = QString::fromStdString(searcher.findAll(searchTerm.toStdString(), currentEditorWidget->toPlainText().toStdString()));
            foundPositions = found.split(" ");
            foundPosElement = 0;
            selectText(foundPositions[foundPosElement].toInt(), searchTermLen);
        }
    }
}
void CodeEditor::on_findLineEdit_textChanged(const QString &arg1)
{
    on_findLineEdit_returnPressed();
}

// Selects Text Given the Position Of the First Char And It's Length
void CodeEditor::selectText(int pos, int len){
    if (foundPositions.length() > 1){
        QTextCursor cur = currentEditorWidget->textCursor();
        cur.setPosition(pos , QTextCursor::MoveAnchor);
        cur.setPosition(pos + len, QTextCursor::KeepAnchor);
        currentEditorWidget->setTextCursor(cur);
        ui->listWidget->verticalScrollBar()->setValue(currentEditorWidget->verticalScrollBar()->value());
    }
}

//  Find Next Instance Of Search Term
void CodeEditor::findNext(){
    if (ui->findLineEdit->text() == currentSearchTerm){

        if (foundPositions.length() > 1){

            if (foundPosElement < foundPositions.length() - 2){
                foundPosElement++;
            } else {
                foundPosElement = 0;
            }

            selectText(foundPositions[foundPosElement].toInt(), searchTermLen);
        }

    } else {
        on_findLineEdit_returnPressed();
    }
}

// Find Previous Instance Of Search Term
void CodeEditor::findPrev(){

    if (foundPositions.length() > 1){

        if (foundPosElement > 0){
            foundPosElement--;
        } else {
            foundPosElement = foundPositions.length() - 2;
        }

        selectText(foundPositions[foundPosElement].toInt(), searchTermLen);
    }
}

void CodeEditor::on_findButton_clicked()
{
    findNext();
    currentEditorWidget->setFocus();
}

void CodeEditor::on_actionFind_Next_triggered()
{
    findNext();
}

void CodeEditor::on_findPrevButton_clicked()
{
    findPrev();
    currentEditorWidget->setFocus();
}

void CodeEditor::on_actionFind_Previous_triggered()
{
    findPrev();
}

//  Toggle Replace Bar
void CodeEditor::on_actionReplace_triggered()
{
    if (ui->findReplaceBar->isHidden()){
        ui->findReplaceBar->show();
        ui->findLineEdit->setFocus();
        if (ui->replaceLineEdit->isHidden()){
            ui->replaceLineEdit->show();
            ui->replaceButton->show();
            ui->replaceAllButton->show();
            ui->replaceLabel->show();
        }
    } else {

        if (ui->replaceLineEdit->isHidden()){
            ui->replaceLineEdit->show();
            ui->replaceButton->show();
            ui->replaceAllButton->show();
            ui->replaceLabel->show();
        } else {
            ui->replaceLineEdit->hide();
            ui->replaceButton->hide();
            ui->replaceAllButton->hide();
            ui->findReplaceBar->hide();
            ui->replaceLabel->hide();
            currentEditorWidget->setFocus();
        }

    }
}

// Replace Currently Selected Found Instance Of Text To Be Replaced
void CodeEditor::on_replaceButton_clicked()
{
    QTextCursor cur = currentEditorWidget->textCursor();

    if (cur.selectedText() != ""){
        cur.removeSelectedText();
        cur.insertText(ui->replaceLineEdit->text());
    }

    currentEditorWidget->setTextCursor(cur);
    QString searchTerm = ui->findLineEdit->text();
    currentSearchTerm = searchTerm;
    searchTermLen = searchTerm.length();

    if (searchTermLen > 0){
        QString found = QString::fromStdString(searcher.findAll(searchTerm.toStdString(), currentEditorWidget->toPlainText().toStdString()));
        foundPositions = found.split(" ");
        foundPosElement = 0;
        selectText(foundPositions[foundPosElement].toInt(), searchTermLen);
    }
}
void CodeEditor::on_replaceLineEdit_returnPressed()
{
    CodeEditor::on_replaceButton_clicked();
}

//  Replace All Found Instances Of Text To Be Replaced
void CodeEditor::on_replaceAllButton_clicked()
{
    QString searchTerm = ui->findLineEdit->text();
    currentSearchTerm = searchTerm;
    do {
        searchTermLen = searchTerm.length();

        if (searchTermLen > 0){
            QString found = QString::fromStdString(searcher.findAll(searchTerm.toStdString(), currentEditorWidget->toPlainText().toStdString()));
            foundPositions = found.split(" ");
            foundPosElement = 0;
            selectText(foundPositions[foundPosElement].toInt(), searchTermLen);
        }

        QTextCursor cur = currentEditorWidget->textCursor();

        if (cur.selectedText() != ""){
            cur.removeSelectedText();
            cur.insertText(ui->replaceLineEdit->text());
        }

        currentEditorWidget->setTextCursor(cur);

    } while (foundPositions.length() > 1);
}

// Go To Line Number
void CodeEditor::on_actionGoTo_triggered()
{
    bool ok = 0;

    if (int line = QInputDialog::getText(this, tr("Enter"),tr("Go to:"), QLineEdit::Normal,"", &ok).toInt()){
        QTextCursor cur = currentEditorWidget->textCursor();
        cur.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
        cur.movePosition(QTextCursor::Down, QTextCursor::MoveAnchor, line-1);
        currentEditorWidget->setTextCursor(cur);
        ui->listWidget->verticalScrollBar()->setValue(currentEditorWidget->verticalScrollBar()->value());
    }
}

/*
 *****************************
 *         Editing           *
 *****************************
*/

//  Undo/Redo
void CodeEditor::on_actionUndo_triggered()
{
    currentEditorWidget->undo();
}
void CodeEditor::on_actionRedo_triggered()
{
    currentEditorWidget->redo();
}

//  Delete Line Where Cusor Currently Resides
void CodeEditor::on_actionDelete_line_triggered()
{
    currentEditorWidget->deleteLine();
}

//  Delete Word Where Cusor Currently Resides
void CodeEditor::on_actionRemove_word_triggered()
{
    currentEditorWidget->deleteWord();
}

/*
 *  Toggles currently selected line(s) between commented out and uncommented
 *  If no text is selected then it selects the current line
*/
void CodeEditor::on_actionToggle_comment_triggered()
{
    currentEditorWidget->toggleComment();
}

// Join Lines
void CodeEditor::on_actionJoin_Lines_triggered()
{
    currentEditorWidget->joinLines();
}

// Swap Line Up
void CodeEditor::on_actionMove_Line_Up_triggered()
{
    currentEditorWidget->swapLineUp();
}

// Swap Line Down
void CodeEditor::on_actionSwap_line_down_triggered()
{
    currentEditorWidget->swapLineDown();
}

/*
 *****************************
 *         Tools             *
 *****************************
*/

// Strips All Nonprintable ascii Characters From Contents Of Current Tab
void CodeEditor::on_actionStrings_triggered()
{
    if (*outputModeP != 1){
        *outputModeP = 2;
        currentEditorWidget->setPlainText( QString::fromStdString(conversion.getStrings(currentEditorWidget->toPlainText().toStdString())) );
    }
}

//  Converts ascii Values Of Content Of Current Tab Into Hexidecimal
void CodeEditor::on_actionHex_triggered()
{
    if (*outputModeP == 0 || *outputModeP == 2){
        *outputModeP = 1;
        currentEditorWidget->setPlainText( QString::fromStdString( conversion.hex(currentEditorWidget->toPlainText().toStdString() ) ) );
    }
}

//  Converts Hexidecimal Values Of Content Of Current Tab Into ascii
void CodeEditor::on_actionAscii_triggered()
{
    if (*outputModeP == 1){
        *outputModeP = 0;
        currentEditorWidget->setPlainText( QString::fromStdString( conversion.ascii(currentEditorWidget->toPlainText().toStdString() ) ) );
    }
}

/*
 *****************************
 *         Templates         *
 *****************************
*/

bool CodeEditor::confirmApplyTemplate(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Template", "Are you sure you want to apply a template?\nAll unsaved work will be lost.", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes){
        return true;
    } else {
        return false;
    }
}

// If current tab contents are not empty, prompt user for confirmation to apply template

void CodeEditor::on_actionAsm_triggered(){
    if (currentEditorWidget->toPlainText() == ""){
        currentEditorWidget->setPlainText(templates.getAsmTemplate());
    } else {
        if (confirmApplyTemplate()){
            currentEditorWidget->setPlainText(templates.getAsmTemplate());
        }
    }
}

void CodeEditor::on_actionC_triggered(){
    if (currentEditorWidget->toPlainText() == ""){
        currentEditorWidget->setPlainText(templates.getCTemplate());
    } else {
        if (confirmApplyTemplate()){
            currentEditorWidget->setPlainText(templates.getCTemplate());
        }
    }
}

void CodeEditor::on_actionCpluspluss_triggered(){
    if (currentEditorWidget->toPlainText() == ""){
        currentEditorWidget->setPlainText(templates.getCPPTemplate());
    } else {
        if (confirmApplyTemplate()){
            currentEditorWidget->setPlainText(templates.getCPPTemplate());
        }
    }
}

void CodeEditor::on_actionHtml_triggered(){
    if (currentEditorWidget->toPlainText() == ""){
        currentEditorWidget->setPlainText(templates.getHtmlTemplate());
    } else {
        if (confirmApplyTemplate()){
            currentEditorWidget->setPlainText(templates.getHtmlTemplate());
        }
    }
}

void CodeEditor::on_actionJava_triggered(){
    if (currentEditorWidget->toPlainText() == ""){
        currentEditorWidget->setPlainText(templates.getJavaTemplate());
    } else {
        if (confirmApplyTemplate()){
            currentEditorWidget->setPlainText(templates.getJavaTemplate());
        }
    }
}

void CodeEditor::on_actionCss_triggered(){
    if (currentEditorWidget->toPlainText() == ""){
        currentEditorWidget->setPlainText(templates.getCSSTemplate());
    } else {
        if (confirmApplyTemplate()){
            currentEditorWidget->setPlainText(templates.getCSSTemplate());
        }
    }
}
void CodeEditor::on_actionRl_triggered(){
    if (currentEditorWidget->toPlainText() == ""){
        currentEditorWidget->setPlainText(templates.getRoboticLanguageTemplate());
    } else {
        if (confirmApplyTemplate()){
            currentEditorWidget->setPlainText(templates.getRoboticLanguageTemplate());
        }
    }
}

void CodeEditor::on_actionRoboticLanguage_triggered()
{
    if (currentEditorWidget->toPlainText() == ""){
        currentEditorWidget->setPlainText(templates.getRoboticLanguageTemplate());
    } else {
        if (confirmApplyTemplate()){
            currentEditorWidget->setPlainText(templates.getRoboticLanguageTemplate());
        }
    }
}

void CodeEditor::on_actionRun_triggered()
{
    qDebug("run triggered");
    qDebug(currentEditorWidget->toPlainText().toLatin1());
    highlightRunningLine(QColor(249,166,2));
    // in here start interpreter
    InterpreterCore* core=new InterpreterCore();
    core->parsText(currentEditorWidget->toPlainText());
    highlightRunningLine(lineColor);
}

/*
 *****************************
 *         View              *
 *****************************
*/

// Toggle FullScreen
void CodeEditor::on_actionFullScreen_triggered()
{
    if (CodeEditor::isFullScreen())
    {
        CodeEditor::showNormal();
    } else {
        CodeEditor::showFullScreen();
    }
}

// Toggle File Overview
void CodeEditor::on_actionOverview_triggered()
{
    if (ui->fileOverview->isHidden()){
        ui->fileOverview->show();
        settings.setValue("showOverview", true);
    } else {
        ui->fileOverview->hide();
        settings.setValue("showOverview", false);
    }
}

// Toggle Menubar
void CodeEditor::on_actionMenubar_triggered()
{
    if (ui->menuBar->height() > 0){
        ui->menuBar->setMaximumHeight(0);
    } else {
        ui->menuBar->setMaximumHeight(100);
    }
}

/*
 *****************************
 *         Themes            *
 *****************************
*/

void CodeEditor::setCodeEditorStyle(QString backgroundColor, QString lineColor){
    QString stylesheet = "QMenu {"
                "background-color: rgb(48, 47, 54);"
                "color:white;"
                "selection-background-color: #404f4f;"
                "border: 1px solid #404f4f;"
                "border-radius: 3px 3px 3px 3px;"
             "}"
             "QMenuBar::item {"
                "background:#262626;"
             "}"
             "QMenuBar::item:selected {"
                "background: #232629;"
             "}"
             "QMessageBox {"
                "color:white;"
             "}"
             "QLineEdit {"
                "border: 1px solid #676767;"
                "border-radius: 5px 5px 5px 5px;"
             "}"
             "QScrollBar::sub-page:vertical {"
                "background: " +  backgroundColor + ";"
             "}"
             "QScrollBar::add-page:vertical {"
                "background: " +  backgroundColor + ";"
             "}"
             "QScrollBar::sub-page:horizonal {"
                "background: " +  backgroundColor +";"
             "}"
             "QScrollBar::add-page:horizontal {"
                "background: " +  backgroundColor +";"
             "}"
             "QScrollBar:vertical{"
                "background: white;"
                "width:12px;margin: 0px 0px 0px 0px;"
             "}"
             "QScrollBar::handle:vertical {"
                "background:" + lineColor  +";"
                "border: 2px solid " +  backgroundColor  +";"
                "border-radius: 5px 5px 5px 5px;"
                "min-height: 30px;"
             "}"
             "QScrollBar:horizontal{"
                "background: white;"
                "height:12px;"
                "margin: 0px 0px 0px 0px;"
             "}"
             "QScrollBar::handle:horizontal {"
                "background:" + lineColor  +";"
             "border: 2px solid " +  backgroundColor  +";"
             "border-radius: 5px 5px 5px 5px;"
             "min-height: 30px;"
             "}";

    CodeEditor::setStyleSheet(stylesheet);

}

void CodeEditor::setTabWidgetStyle(QString foregroundColor, QString backgroundColor){
    QString stylesheet = "QPlainTextEdit {"
                "background-color: " +  backgroundColor  +";"
                "color:" + foregroundColor  +";"
                "border: 0px;"
                "padding-left: 1px;"
                "selection-background-color: #404f4f;"
                "font-family: \"Anonymous Pro\";"
                "font-size:11pt;"
             "}"
             "QScrollBar:vertical{"
                "background: " +  backgroundColor  +";"
             "}"
             "QScrollBar:horizontal{"
                "background: " +  backgroundColor  +";"
             "}"
             "QTabBar::tab:selected{"
                "color: white;"
                "border-bottom: 3px solid #2F4F4F;"
             "}"
             "QTabBar::tab {"
                "height: 22px; width: 160px;"
                "color: #676767;"
                "font-size:9pt;"
                "margin: 0 -2px;"
                "padding: 1px 5px;"
                "background-color: #262626;"
                "border-bottom: 3px solid #212121;"
             "}";
   ui->tabWidget->setStyleSheet(stylesheet);

}

void CodeEditor::setLineNumStyle(QString lineColor, QString foregroundColor){
    QString stylesheet = "background-color: " + lineColor  +";"
            "margin-top: 30px;"
            "padding-left: 5px;"
            "padding-right: 1px;"
            "color: " + foregroundColor  +";"
            "border: none;"
            "font: 11pt \"Anonymous Pro\";";
    ui->listWidget->setStyleSheet(stylesheet);
}

void CodeEditor::setOverViewStyle(QString lineColor, QString foregroundColor){
    QString stylesheet = "font-family: \"Anonymous Pro\";"
            "font-size: 1pt;"
            "color:" + foregroundColor  +";"
            "margin-top: 28px;"
            "background-color:" + lineColor  +";"
            "border: 0px;";
    ui->fileOverview->setStyleSheet(stylesheet);
}

void CodeEditor::updateHighlighterTheme(){
    int current = ui->tabWidget->currentIndex();
    int numOpenTabs = ui->tabWidget->count();
    for(int i = 0; i < numOpenTabs; i++){
        ui->tabWidget->setCurrentIndex(i);
        currentEditorWidget->setHighlighterTheme(theme);
    }
    ui->tabWidget->setCurrentIndex(current);
}

void CodeEditor::on_actionDark_triggered()
{
    theme = "monokai";
    settings.setValue("theme", "monokai");
    QString fgc = "#e0e0e0";
    QString bgc = "#272822";
    QString lc = "#32332c";

    setCodeEditorStyle(bgc, lc);
    setTabWidgetStyle(fgc, bgc);
    setLineNumStyle(lc, fgc);
    setOverViewStyle(lc, fgc);
    currentEditorWidget->setStyle("#c4c8ab","#5D5D5D","#2d2e25");

    updateHighlighterTheme();

    lineColor = QColor(50, 51, 44);
    highlightCurrentLine();

}

void CodeEditor::on_actionSolarized_triggered()
{
    theme = "solarized";
    settings.setValue("theme", "solarized");

    QString fgc = "#839496";
    QString bgc = "#fdf6e3";
    QString lc = "#eee7d5";

    setCodeEditorStyle(bgc, lc);
    setTabWidgetStyle(fgc, bgc);
    setLineNumStyle(lc, fgc);
    setOverViewStyle(lc, fgc);
    currentEditorWidget->setStyle(lc,"#8f8b80","#35342f");
    updateHighlighterTheme();

    lineColor = QColor(238, 232, 213);
    highlightCurrentLine();
}

void CodeEditor::on_actionSolarized_Dark_triggered()
{
    theme = "solarizedDark";
    settings.setValue("theme", "solarizedDark");
    QString fgc = "#839496";
    QString bgc = "#002b36";
    QString lc = "#073642";

    setCodeEditorStyle(bgc, lc);
    setTabWidgetStyle(fgc, bgc);
    setLineNumStyle(lc, fgc);
    setOverViewStyle(lc, fgc);
    currentEditorWidget->setStyle("#14a4c9","#004b5f","#03181e");

    updateHighlighterTheme();

    lineColor = QColor(7, 54, 66);
    highlightCurrentLine();
}

void CodeEditor::on_actionTommorrow_triggered()
{
    theme = "tomorrow";
    settings.setValue("theme", "tomorrow");
    QString fgc = "#4d4d4c";
    QString bgc = "#ffffff";
    QString lc = "#efefef";

    setCodeEditorStyle(bgc, lc);
    setTabWidgetStyle(fgc, bgc);
    setLineNumStyle(lc, fgc);
    setOverViewStyle(lc, fgc);
    currentEditorWidget->setStyle("#efefef","#6b5a5a","#362d2d");

    updateHighlighterTheme();

    lineColor = QColor(237, 237, 237);
    highlightCurrentLine();
}

void CodeEditor::on_actionTommorrow_Night_triggered()
{
    theme = "tomorrowNight";
    settings.setValue("theme", "tomorrowNight");
    QString fgc = "#c5c8c6";
    QString bgc = "#1d1f21";
    QString lc = "#282a2e";

    setCodeEditorStyle(bgc, lc);
    setTabWidgetStyle(fgc, bgc);
    setLineNumStyle(lc, fgc);
    setOverViewStyle(lc, fgc);
    currentEditorWidget->setStyle("#c5c8c6","#3a434b","#1d1f21");

    updateHighlighterTheme();

    lineColor = QColor(40, 42, 46);
    highlightCurrentLine();
}

/*
 *****************************
 *         Window            *
 *****************************
*/

//  Highlight Current Line
void CodeEditor::highlightCurrentLine(){
   if (currentEditorWidget != NULL){
       QList<QTextEdit::ExtraSelection> extraSelections;

       QTextEdit::ExtraSelection selections;
       selections.format.setBackground(lineColor);
       selections.format.setProperty(QTextFormat::FullWidthSelection, true);
       selections.cursor = currentEditorWidget->textCursor();
       selections.cursor.clearSelection();
       extraSelections.append(selections);

       currentEditorWidget->setExtraSelections(extraSelections);
       ui->listWidget->verticalScrollBar()->setValue(currentEditorWidget->verticalScrollBar()->value());
   }

}
void CodeEditor::highlightRunningLine(QColor highlight_color){
    if (currentEditorWidget != NULL){
        QList<QTextEdit::ExtraSelection> extraSelections;

        QTextEdit::ExtraSelection selections;
        selections.format.setBackground(highlight_color);
        selections.format.setProperty(QTextFormat::FullWidthSelection, true);
        QTextCursor highlight_cursor=currentEditorWidget->textCursor();
        qDebug("position before moving:%d",highlight_cursor.position());
        //highlight_cursor.movePosition(QTextCursor::Start);
        highlight_cursor.movePosition(QTextCursor::Down);


        qDebug("position after moving:%d",highlight_cursor.position());
        selections.cursor = highlight_cursor;
        selections.cursor.clearSelection();
        extraSelections.append(selections);

        currentEditorWidget->setExtraSelections(extraSelections);
        ui->listWidget->verticalScrollBar()->setValue(currentEditorWidget->verticalScrollBar()->value());

    }

}
//  Update Line Numbers
void CodeEditor::updateLineNums(int newBlockCount){

    if (newBlockCount > numBlocks){
        //  Add Line Numbers
        while (numBlocks < newBlockCount){
            numBlocks++;
            QString lineNum = QString::number(numBlocks);
            ui->listWidget->addItem(lineNum);
            QListWidgetItem *item = ui->listWidget->item(numBlocks-1);
            item->setSizeHint(QSize(item->sizeHint().height(), 14));
        }

    } else {
        //  Remove Line Numbers
        while (numBlocks > newBlockCount){
            ui->listWidget->takeItem(numBlocks - 1);
            numBlocks--;
        }
    }

    QString numLinesText = QString::number(newBlockCount) + " Lines";
    ui->statusMsgLabel->setText(numLinesText);
}
void CodeEditor::onBlockCountChanged(int newBlockCount)
{
    /*  Auto-Indent New Lines   */

    //  If Block Count Only Increased By One
    if (newBlockCount == numBlocks + 1){

        QString data = currentEditorWidget->toPlainText();
        int cursorPosition = currentEditorWidget->textCursor().position();

        // If Beginning Cursor At Beginning Of New Line
        if (data.mid(cursorPosition-1, 1) == "\n"){
            int pos;

            // Get Position Of Start Of New Line
            for (pos=cursorPosition-2; pos>=0; pos--){

                if (data.mid(pos, 1) == "\n") {
                    break;
                    }
                }

                //  For Each Tab Char At Beggining Of Previous Line: Add Tab To New Line
                while (data.mid(pos + 1, 1) == "\t"){
                    currentEditorWidget->textCursor().insertText("\t");
                    pos++;
                }
         }
    }

    // Update Line Numbers
    CodeEditor::updateLineNums(newBlockCount);
}

//  Text Changed
void CodeEditor::onTextChanged(){

    ui->textBrowser->setText("");
    ui->fileOverview->setPlainText(currentEditorWidget->toPlainText());
    currentSearchTerm = "";
}

// Sync Overview Scrolling With Editor Scrolling
void CodeEditor::scrollOverview(int scrollValue){
    ui->fileOverview->verticalScrollBar()->setValue(scrollValue * 2.5);
}

//  Close Program
void CodeEditor::on_actionExit_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Test", "Quit?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
      QApplication::quit();
    } else {

    }
}

// Close All Tabs
void CodeEditor::on_actionClose_All_triggered()
{
    while (ui->tabWidget->count() > 1){
        on_tabWidget_tabCloseRequested(0);
    }
    on_tabWidget_tabCloseRequested(0);
}

//  Display About Info
void CodeEditor::on_actionAbout_triggered()
{
    QString licence = "Project Page: https://github.com/jubal-R/Geist\n\n"
            "Geist - All purpose text/code editor\n"
            "Version: 1.0\n"
            "Copyright (C) 2017\n\n"

            "This program is free software: you can redistribute it and/or modify "
            "it under the terms of the GNU General Public License as published by "
            "the Free Software Foundation, either version 3 of the License, or "
            "(at your option) any later version.\n\n"

            "This program is distributed in the hope that it will be useful,"
            "but WITHOUT ANY WARRANTY; without even the implied warranty of "
            "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the "
            "GNU General Public License for more details.\n\n"

            "You should have received a copy of the GNU General Public License "
            "along with this program.  If not, see <http://www.gnu.org/licenses/>.\n";
    QMessageBox::information(this, tr("About Geist"), licence,QMessageBox::Close);
}

// Set Tab Stop Width
void CodeEditor::setTabWidth(int width){
    QFont font;
    font.setFamily("Anonymous Pro");
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    font.setPointSize(10);
    QFontMetrics metrics(font);

    int current = ui->tabWidget->currentIndex();

    for(int i = 0; i < ui->tabWidget->count(); i++){
        ui->tabWidget->setCurrentIndex(i);
        currentEditorWidget->setTabStopWidth(width * metrics.width(' ') );
    }

    ui->tabWidget->setCurrentIndex(current);

}

void CodeEditor::on_action8_triggered()
{
    settings.setValue("tabWidth", 8);
    setTabWidth(8);
}

void CodeEditor::on_action4_triggered()
{
    settings.setValue("tabWidth", 4);
    setTabWidth(4);
}

void CodeEditor::on_action2_triggered()
{
    settings.setValue("tabWidth", 2);
    setTabWidth(2);
}

void CodeEditor::openWith(QString file){
    open(file);
}

QAbstractItemModel *CodeEditor::modelFromFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return new QStringListModel(completer);

#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
#endif
    QStringList words;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if (!line.isEmpty())
            words << line.trimmed();
    }

#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
    return new QStringListModel(words, completer);
}
