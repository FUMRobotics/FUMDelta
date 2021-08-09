#ifndef PLOTHANDLER_H
#define PLOTHANDLER_H

#include <QObject>
#include "qcustomplot.h"
class PlotHandler : public QObject
{
    Q_OBJECT
public:
    //explicit PlotHandler(QObject *parent = nullptr);
    PlotHandler(int plot_id ,QCustomPlot *plot,QLabel* angle_label,QLabel* fps_label,QObject *parent = nullptr);

signals:

public slots:
    void updatePlotData(unsigned int key,QVector<double> targetPosition, QVector<double> actualPosition);

private:

    void setUpPlot();

    QCustomPlot *plot;
    QLabel* angle_label;
    QLabel* fps_label;
    int plot_id;
};

#endif // PLOTHANDLER_H
