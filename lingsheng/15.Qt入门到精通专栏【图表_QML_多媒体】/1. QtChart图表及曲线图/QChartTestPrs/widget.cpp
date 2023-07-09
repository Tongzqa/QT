#include "widget.h"
#include "ui_widget.h"




Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QSplineSeries *s1=new QSplineSeries(); // 创建曲线对象

    s1->append(0,5);
    s1->append(1,3);
    s1->append(2,5);
    s1->append(3,9);
    s1->append(4,6);
    s1->append(5,16);
    s1->append(6,10);
    s1->append(7,12);
    s1->append(8,17);
    s1->append(9,19);

    QChart *ct=ui->chartview->chart();
    ct->legend()->hide(); // 隐藏图表比例
    ct->addSeries(s1);
    ct->setTitle("曲线图表标题--自定义");
    ct->createDefaultAxes();
    ct->axes(Qt::Vertical).first()->setRange(0,20); // 设置y轴的范围





}

Widget::~Widget()
{
    delete ui;
}

