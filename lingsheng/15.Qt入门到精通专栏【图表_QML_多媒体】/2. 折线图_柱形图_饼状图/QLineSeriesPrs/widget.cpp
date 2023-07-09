#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 调用此函数myselfLineSeriesFunc()
    myselfLineSeriesFunc();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::myselfLineSeriesFunc()
{

    // 实例化图表QChart对象
    QChart *chart=new QChart;

    chart->setTitle("全球各国军费增长折线图"); // 设置标题名称

    ui->graphicsView->setChart(chart);

    // 设置X坐标
    QValueAxis *axisX=new QValueAxis;
    axisX->setTitleText("年份"); // 设置标题名称
    axisX->setRange(2017,2021); // 设置范围
   // axisX->setTickCount(6); // 设置刻度个数
    axisX->setLineVisible(true);
    axisX->setGridLineVisible(false); // 设置网格线是否可见

    QValueAxis *axisY=new QValueAxis;
    axisY->setTitleText("军费（万亿:美元）"); // 设置标题名称
    axisY->setRange(2000,10000); // 设置范围
    axisY->setTickCount(5); // 设置刻度个数
    axisY->setLineVisible(true);
    axisY->setGridLineVisible(false); // 设置网格线是否可见



    // 绘制折线图 ，设置序列
    QLineSeries *sris1=new QLineSeries;
    sris1->setName("中国");
    sris1->setColor(QColor(255,0,0)); // 设置序列颜色值
    // 添加数据点到序列
    sris1->append(2017,5000);
    sris1->append(2018,6500);
    sris1->append(2019,4900);
    sris1->append(2020,8000);
    sris1->append(2021,9000);

    // 绘制折线图 ，设置序列
    QLineSeries *sris2=new QLineSeries;
    sris2->setName("美国");
    sris2->setColor(QColor(0,255,0)); // 设置序列颜色值
    // 添加数据点到序列
    sris2->append(2017,6500);
    sris2->append(2018,7000);
    sris2->append(2019,6900);
    sris2->append(2020,9000);
    sris2->append(2021,9800);



    // 绘制折线图 ，设置序列
    QLineSeries *sris3=new QLineSeries;
    sris3->setName("俄罗斯");
    sris3->setColor(QColor(0,0,255)); // 设置序列颜色值
    // 添加数据点到序列
    sris3->append(2017,4000);
    sris3->append(2018,8000);
    sris3->append(2019,7900);
    sris3->append(2020,10000);
    sris3->append(2021,9500);




    // 为QChart添加序列
    chart->addSeries(sris1);
    chart->addSeries(sris2);
    chart->addSeries(sris3);

    // 将序列设置到坐标轴
    chart->setAxisX(axisX,sris1);
    chart->setAxisY(axisY,sris1);

    chart->setAxisX(axisX,sris2);
    chart->setAxisY(axisY,sris2);

    chart->setAxisX(axisX,sris3);
    chart->setAxisY(axisY,sris3);

}
