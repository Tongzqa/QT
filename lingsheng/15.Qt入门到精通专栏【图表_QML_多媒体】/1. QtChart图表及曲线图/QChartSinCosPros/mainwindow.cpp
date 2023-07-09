#include "mainwindow.h"
#include "ui_mainwindow.h"



#include <QtCharts>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // 1:创建图表视图对象
    QChartView *chartview=new QChartView(this);

    QChart *chart=new QChart(); // 创建图表

    chart->setTitle("图表测试--正弦余弦曲线程序");

    // 2:将图表添加到图表视图
    chartview->setChart(chart);

    // 3:将图表视图展示到窗口中间
    this->setCentralWidget(chartview);


    // 4:创建曲线
    QLineSeries *s1=new QLineSeries();
    QLineSeries *s2=new QLineSeries();

    s1->setName("正弦曲线");
    s2->setName("余弦曲线");

    // 5:将创建曲线添加到图表
    chart->addSeries(s1);
    chart->addSeries(s2);

    // 6： 为曲线序列添加对应数值
    qreal t=0,y1,y2,iv=0.1;
    int cnt=100;

    for(int i=0;i<cnt;i++)
    {
        y1=qSin(t);
        s1->append(t,y1);
        y2=qSin(t+20);
        s2->append(t,y2);

        t=t+iv;
    }

    // 7：创建坐标轴
    QValueAxis *ax=new QValueAxis; // X轴
    ax->setRange(0,10); // 设置坐标轴范围
    ax->setTitleText("times(secs)");

    QValueAxis *ay=new QValueAxis; // Y轴
    ay->setRange(-2,2);
    ay->setTitleText("values");


    chart->setAxisX(ax,s1);
    chart->setAxisY(ay,s1);

    chart->setAxisX(ax,s2);
    chart->setAxisY(ay,s2);






}

MainWindow::~MainWindow()
{
    delete ui;
}

