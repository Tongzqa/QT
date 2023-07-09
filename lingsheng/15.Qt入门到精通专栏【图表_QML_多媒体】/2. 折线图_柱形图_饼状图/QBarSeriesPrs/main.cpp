#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // 创建条形集对象
    QBarSet *ba=new QBarSet("bar");

    *ba<<560<<710<<599<<688<<701;

    QStackedBarSeries *sris=new QStackedBarSeries();
    sris->append(ba);

    QChart *chart=new QChart();
    chart->addSeries(sris);
    chart->setTitle("某某学校实验班高考成绩分数");

    QStringList strlist={"小王","小李","小吴","小张","小赵"};

    // 通过QBarCategoryAxis类将类型添加到图表的轴
    QBarCategoryAxis *axisX=new QBarCategoryAxis();
    axisX->append(strlist);
    axisX->setTitleText("考生姓名");
    chart->addAxis(axisX,Qt::AlignBottom);


    // 通过QBarCategoryAxis类将类型添加到图表的轴
    QValueAxis *axisY=new QValueAxis();
    axisY->setRange(0,750);
    axisY->setTitleText("高考总分阶梯");
    chart->addAxis(axisY,Qt::AlignLeft);

    sris->attachAxis(axisX);
    sris->attachAxis(axisY);



    // 图例
    chart->legend()->setVisible(false); // 设置绘图区与图表边界
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartview=new QChartView(chart);



    MainWindow w;

    w.setWindowTitle("高考成绩--柱状图表展示");
    w.setCentralWidget(chartview);
    w.resize(800,500);


    w.show();
    return a.exec();
}
