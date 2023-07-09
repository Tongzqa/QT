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
    qmap["int"]=20000; // ����
    qmap["double"]=99.88; // ������
    qmap["string"]="Good"; // �ַ���
    qmap["color"]=QColor(255,255,0); // QColor����

    // �����ת������������
    qDebug()<<qmap["int"]<<qmap["int"].toInt();
    qDebug()<<qmap["double"]<<qmap["double"].toDouble();
    qDebug()<<qmap["string"]<<qmap["string"].toString();
    qDebug()<<qmap["color"]<<qmap["color"].value<QColor>();

    // ����һ���ַ����б�QStringList
    qDebug()<<endl;
    QStringList qsl;
    qsl<<"A"<<"B"<<"C"<<"D"<<"E"<<"F";

    QVariant qvsl(qsl); // ���б�洢��һ��QVariant����
    if(qvsl.type()==QVariant::StringList)
    {
        QStringList qlist=qvsl.toStringList();
        for (int i=0;i<qlist.size();i++) {
            qDebug()<<qlist.at(i);  // ����б�������Ϣ
        }
    }

    // �ṹ�����ͺ�QVariant�����ʹ��
    qDebug()<<endl;
    student stu;
    stu.iNo=202201;
    stu.strName="sunny";
    stu.score=715;

    // ʹ�þ�̬������������
   QVariant qstu=QVariant::fromValue(stu);

    if(qstu.canConvert<student>())  // �ж��Ƿ����ת������
    {
        student temp=qstu.value<student>(); // ��ȡ����
        student qtemp=qvariant_cast<student>(qstu); // ��ȡ����

        qDebug()<<"student:iNo="<<temp.iNo<<",strName="<<temp.strName<<",score="<<temp.score;
        qDebug()<<"student:iNo="<<qtemp.iNo<<",strName="<<qtemp.strName<<",score="<<qtemp.score;
    }




}

MainWindow::~MainWindow()
{
}

