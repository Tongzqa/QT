#ifndef CREATESQLCONNECT_H
#define CREATESQLCONNECT_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

static bool CreateSQLConnectionFunc()
{
    QSqlDatabase sqldb=QSqlDatabase::addDatabase("QSQLITE");
    sqldb.setDatabaseName("test.db");

    if(!sqldb.open())
    {
        QMessageBox::critical(0,"错误","SQLite数据库打开失败，请重新检查!",QMessageBox::Ok);
        return false;
    }
    else
    {
        QMessageBox::information(0,"正确","恭喜你，SQLite数据库打开成功!",QMessageBox::Ok);
    }

    QSqlQuery queryexec;

    //创建数据表
    queryexec.exec("create table emp(empid int primary key," "empname varchar(20))");

    // 插入记录
    queryexec.exec("insert into emp values(101,'vico')");
    queryexec.exec("insert into emp values(102,'mark')");
    queryexec.exec("insert into emp values(103,'darren')");
    queryexec.exec("insert into emp values(104,'sunny')");
    queryexec.exec("insert into emp values(105,'kitty')");

    return true;

}





#endif // CREATESQLCONNECT_H
