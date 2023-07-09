#ifndef READWRITEXML_H
#define READWRITEXML_H

#include <QDialog>

 // QDomComment是Qt所封装的类，专门用来操作XML文件（项目中用来存储一些配置数据信息）
#include <QDomComment>
#include <QDir>
#include <QFile>
#include <QDebug>

#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class ReadWriteXml; }
QT_END_NAMESPACE

class ReadWriteXml : public QDialog
{
    Q_OBJECT

public:
    ReadWriteXml(QWidget *parent = nullptr);
    ~ReadWriteXml();

private:
    Ui::ReadWriteXml *ui;

    QFile m_qfiles;
    QString strcurrentfilepath; // 当前文件路径
    QString strcurrentfilename; // 当前文件名

public:
    bool openxmlfiles(QString filenamepath); // 打开指定文件
    void writexmlfiles();   // 写入xml文件
    void readxmlfiles();    // 读取xml文件
    void readrootxml(QDomNodeList sonnodelist); // 读取子节点数据



private slots:
    void on_pushButton_WriteXml_clicked();
    void on_pushButton_ReadXml_clicked();
};
#endif // READWRITEXML_H
