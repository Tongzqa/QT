#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 创建饼状图形对象
    QPieSeries *sris=new QPieSeries();

    // 占用比例
    sris->append("70分以下：30%",30);
    sris->append("70分-85分：40%",40);
    sris->append("86分-99分：25%",25);
    sris->append("100分：5%",5);

    sris->setLabelsVisible(); // 设置标签属性，可见

    QPieSlice *sred=sris->slices().at(0);
    QPieSlice *sgreen=sris->slices().at(1);
    QPieSlice *sblue=sris->slices().at(2);
    QPieSlice *sblack=sris->slices().at(3);

    sred->setColor(QColor(255,0,0,255));
    sgreen->setColor(QColor(0,255,0,255));
    sblue->setColor(QColor(0,0,255,255));
    sblack->setColor(QColor(0,0,0,255));

    QChart *chart=new QChart();
    chart->addSeries(sris);
    chart->setTitle("饼图形状--班级考试百分制整数比例");

    QChartView *chartview=new QChartView(chart);





    MainWindow w;

    w.setCentralWidget(chartview);
    w.resize(600,600);


    w.show();
    return a.exec();
}
