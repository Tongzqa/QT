#include "mainwindow.h"

#include <QVariant>
#include <QDebug>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVariant qv1(298);
    qDebug()<<"qv1:"<<qv1.toInt();

    QVariant qv2("LingShengEDU");
    qDebug()<<"qv2:"<<qv2.toString();

    QMap<QString,QVariant> qmap;
    qDebug()<<endl;
    qmap["int"]=20000; // 整型
    qmap["double"]=99.88; // 浮点型
    qmap["string"]="Good"; // 字符串
    qmap["color"]=QColor(255,255,0); // QColor类型

    // 输出：转换函数来处理
    qDebug()<<qmap["int"]<<qmap["int"].toInt();
    qDebug()<<qmap["double"]<<qmap["double"].toDouble();
    qDebug()<<qmap["string"]<<qmap["string"].toString();
    qDebug()<<qmap["color"]<<qmap["color"].value<QColor>();

    // 创建一个字符串列表：QStringList
    qDebug()<<endl;
    QStringList qsl;
    qsl<<"A"<<"B"<<"C"<<"D"<<"E"<<"F";

    QVariant qvsl(qsl); // 将列表存储在一个QVariant变量
    if(qvsl.type()==QVariant::StringList)
    {
        QStringList qlist=qvsl.toStringList();
        for (int i=0;i<qlist.size();i++) {
            qDebug()<<qlist.at(i);  // 输出列表数据信息
        }
    }

    // 结构体类型和QVariant类配合使用
    qDebug()<<endl;
    student stu;
    stu.iNo=202201;
    stu.strName="sunny";
    stu.score=715;

    // 使用静态方法保存数据
   QVariant qstu=QVariant::fromValue(stu);

    if(qstu.canConvert<student>())  // 判断是否可以转换操作
    {
        student temp=qstu.value<student>(); // 获取数据
        student qtemp=qvariant_cast<student>(qstu); // 获取数据

        qDebug()<<"student:iNo="<<temp.iNo<<",strName="<<temp.strName<<",score="<<temp.score;
        qDebug()<<"student:iNo="<<qtemp.iNo<<",strName="<<qtemp.strName<<",score="<<qtemp.score;
    }




}

MainWindow::~MainWindow()
{
}

