#include "mainwindow.h"

#include <QDebug>
#include <regex>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*
     * ͨ��������ʽƥ�䣺�ֻ�����
     * ����Ŀǰ���Ҷ��ֻ�����涨��11λ���֣����и����в�ͬ�ı��뷽ʽ��
     * ǰ��λ������ʶ��ţ��й��ƶ����й���ͨ���жϵ��ţ�
     * �����8λ��11λΪ�û�����
     * �й��ƶ���134 159 158 188
     * �й���ͨ��130 133 189 156
     *
     * �൱��1��ͷ����2λ3 5 8��������11λ��
     */

    QString qMobileNumber="18923558899";
    std::regex reg("^1(3|5|8)\\d{9}$");
    std::string UserTelIdString=qMobileNumber.toStdString();

    qDebug()<<"Phone Number:"<<qMobileNumber;

    // ����ƥ��
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

