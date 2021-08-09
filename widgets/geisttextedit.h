#ifndef GeistTextEdit_H
#define GeistTextEdit_H

#include <QPlainTextEdit>
#include <QCompleter>
#include <QAbstractItemView>
#include <QScrollBar>
#include "highlighter.h"

class GeistTextEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    GeistTextEdit(QWidget *parent = 0);
    QString getFilepath();
    QString getFileType();
    void setFilePath(QString newFilepath);
    void setFileType(QString newFileType);
    void setHighlighter(Highlighter * h);
    void setHighlighterTheme(QString theme);
    void selectLine();
    void selectWord();
    QString lineUnderCursor();
    QString wordUnderCursor();
    void deleteLine();
    void deleteWord();
    void joinLines();
    void swapLineUp();
    void swapLineDown();
    void toggleComment();
    void setCompleter(QCompleter *completer);
    QCompleter *completer() const;
    void setStyle(QString fontColor,QString backgroundColor,QString selectedItemBackgroundColor);
    void setStyle(QString fontColor,QString backgroundColor);


protected:
    virtual void keyPressEvent(QKeyEvent * e);

public slots:
private slots:
    void insertCompletion(const QString &completion);
private:
    QString textUnderCursor() const;
private:
    QString filepath;
    QString fileType;
    Highlighter * highlighter;
    QCompleter* c;

};

#endif // GeistTextEdit_H
