#include "mainwindow.h"

#include <QDebug>
#include <regex>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*
     * 通过正则表达式匹配：手机号码
     * 根据目前车家对手机号码规定：11位数字，其中各段有不同的编码方式；
     * 前三位：网络识别号（中国移动、中国联通、中断电信）
     * 后面第8位至11位为用户号码
     * 中国移动：134 159 158 188
     * 中国联通：130 133 189 156
     *
     * 相当以1开头，第2位3 5 8，共计有11位。
     */

    QString qMobileNumber="18923558899";
    std::regex reg("^1(3|5|8)\\d{9}$");
    std::string UserTelIdString=qMobileNumber.toStdString();

    qDebug()<<"Phone Number:"<<qMobileNumber;

    // 进行匹配
    bool bResult=std::regex_match(UserTelIdString,reg);

    if(!bResult)
    {
        qDebug()<<"MobileNumber"<<"-->Error mobile phone number.";
    }
    else
    {
        qDebug()<<qMobileNumber<<"-->Right mobile phone number.";
    }

}

MainWindow::~MainWindow()
{
}

