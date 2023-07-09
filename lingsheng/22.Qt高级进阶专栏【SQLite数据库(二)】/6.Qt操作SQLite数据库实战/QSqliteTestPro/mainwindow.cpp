#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "CreateSQLConnect.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    qDebug()<<"正在连接SQLite数据库......";
    if(!CreateSQLConnectionFunc())
    {
        QMessageBox::information(0,"错误","数据库创建失败，请重新检查!",QMessageBox::Ok);
    }

    QSqlQuery query;
    query.exec("select *from emp");

    qDebug()<<"职工编号"<<"职工姓名";

    while(query.next())
    {
        qDebug()<<query.value(0).toInt()<<qPrintable(query.value(1).toString());
    }







}

MainWindow::~MainWindow()
{
    delete ui;
}

