#include "plothandler.h"


PlotHandler::PlotHandler(int plot_id, QCustomPlot *plot, QLabel *angle_label, QLabel *fps_label, QObject *parent) : QObject (parent)
{
    this->plot = plot;
    this->angle_label = angle_label;
    this->fps_label = fps_label;
    this->plot_id = plot_id;

    //
    setUpPlot();
}

void PlotHandler::updatePlotData(unsigned int key, QVector<double> targetPosition, QVector<double> actualPosition)
{
    static int a = 0;
    a = a + 1;
    //qDebug("plotter side:MOTOR:%d message number=%d actual position= %f ,target position=%f",plot_id,key,actualPosition[plot_id], targetPosition[plot_id]);
    //qDebug("plotter side: message number");
    //static QTime time(QTime::currentTime());
    // calculate two new data points:
    static double lastPointKey = 0;
//    if (key-lastPointKey > 0.002) // at most add point every 2 ms
//    {


    angle_label->setText( QString::number(actualPosition[plot_id],'f',4));
    plot->graph(0)->addData(key, actualPosition[plot_id]);
    plot->graph(1)->addData(key, targetPosition[plot_id]);


    lastPointKey = key;
//    }
    // make key axis range scroll with the data (at a constant range size of 8):
    //plot->xAxis->setRange(key, 30, Qt::AlignRight);
    /*for actual motors*/
    plot->xAxis->setRange(key, 30000, Qt::AlignRight);
    //plot->xAxis->setRange(key, 100, Qt::AlignRight);
    plot->replot();

    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    //if (key-lastFpsKey > 2) // average fps over 2 seconds
    //{
        fps_label->setText(
                    QString("%1 FPS, Total Data points: %2")
                    .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
                    .arg(plot->graph(0)->data()->size()+plot->graph(1)->data()->size())
                    );
        lastFpsKey = key;
        //frameCount = 0;
   // }
}

void PlotHandler::setUpPlot()
{
    QLinearGradient gradient(0, 0, 0, 200);
    gradient.setColorAt(0, QColor(43, 47, 41));
    //gradient.setColorAt(0.38, QColor(105, 105, 105));
    //gradient.setColorAt(1, QColor(70, 70, 70));
    //gradient.setColorAt(1, QColor(17, 26, 15));
    gradient.setColorAt(1, QColor(17, 26, 15));
    plot->setBackground(QBrush(gradient));


    //prepare x axis
    plot->xAxis->setSubTicks(false);
    plot->xAxis->setTickLength(0, 4);
    //plot->xAxis->setRange(0, 8);
    plot->xAxis->setBasePen(QPen(Qt::white));
    plot->xAxis->setTickPen(QPen(Qt::white));
    plot->xAxis->grid()->setVisible(true);
    plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    plot->xAxis->setTickLabelColor(Qt::white);
    plot->xAxis->setLabelColor(Qt::white);
    //prepare y axis
    plot->yAxis->setSubTicks(false);
    plot->yAxis->setTickLength(0, 4);
    //plot->yAxis->setRange(0, 8);
    plot->yAxis->setBasePen(QPen(Qt::white));
    plot->yAxis->setTickPen(QPen(Qt::white));
    plot->yAxis->grid()->setVisible(true);
    plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    plot->yAxis->setTickLabelColor(Qt::white);
    plot->yAxis->setLabelColor(Qt::white);


    plot->setNotAntialiasedElements(QCP::aeAll);
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    plot->xAxis->setTickLabelFont(font);
    plot->yAxis->setTickLabelFont(font);
    plot->legend->setFont(font);

    plot->addGraph(); // red line
    plot->graph(0)->setPen(QPen(QColor(235, 64, 52)));
    QCPScatterStyle style=QCPScatterStyle::ssStar;
    plot->graph(0)->setScatterStyle(style);
    plot->addGraph(); // green line
    plot->graph(1)->setPen(QPen(QColor(58, 235, 52)));
    QCPScatterStyle style2=QCPScatterStyle::ssDot;
    plot->graph(1)->setScatterStyle(style2);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    //drive2->xAxis->setTicker(timeTicker);
    plot->axisRect()->setupFullAxesBox();
    plot->yAxis->setRange(-120, 120);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(plot->xAxis, SIGNAL(rangeChanged(QCPRange)), plot->xAxis2, SLOT(setRange(QCPRange)));
    connect(plot->yAxis, SIGNAL(rangeChanged(QCPRange)), plot->yAxis2, SLOT(setRange(QCPRange)));


    //make plot zoomable & draggable
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
