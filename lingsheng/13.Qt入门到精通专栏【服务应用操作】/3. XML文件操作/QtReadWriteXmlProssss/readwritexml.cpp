#include "readwritexml.h"
#include "ui_readwritexml.h"

ReadWriteXml::ReadWriteXml(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ReadWriteXml)
{
    ui->setupUi(this);

    QDir dirs;
    strcurrentfilepath="d:/xmlfiles"; // xml文件路径
    strcurrentfilename="/factoryworkersxml.xml";
}

ReadWriteXml::~ReadWriteXml()
{
    delete ui;
}


bool ReadWriteXml::openxmlfiles(QString filenamepath) // 打开指定文件
{
    // 如果没有，则创建文件
    m_qfiles.setFileName(strcurrentfilepath+filenamepath);



    return m_qfiles.open(QIODevice::ReadWrite | QFile::Text);
}

void ReadWriteXml::writexmlfiles()   // 写入xml文件
{

    if(!openxmlfiles(strcurrentfilename))
    {
        qDebug()<<"写入：打开XML文件失败，请重新检查？";
        return;
    }
    qDebug()<<"写入：打开XML文件成功，请认真操作xml！";

    QDomDocument domdoct; // 创建对象
    QDomProcessingInstruction version; // 写入xml头部（添加处理命令）
    version=domdoct.createProcessingInstruction("xml","version = \"1.0\" encoding = \"GB2312\"");
    domdoct.appendChild(version);

    // 添加第1个子节点及相关子元素
    QDomElement domrootelement=domdoct.createElement("factory"); // 创建顶层节点
    domdoct.appendChild(domrootelement);

    QDomElement itemrootelement=domdoct.createElement("worker"); // 创建父节点
    {
        // 创建子元素
        QDomElement node1=domdoct.createElement("WNo"); // 创建子节点（创建元素节点）
        QDomText domtext1=domdoct.createTextNode("WNo"); // 可创建文本节点
        domtext1.setData(ui->lineEdit_No->text()); // 设置子节点数据
        node1.appendChild(domtext1); // 将子节点数据进行绑定
        itemrootelement.appendChild(node1); // 将子节点绑定到父亲节点

        QDomElement node2=domdoct.createElement("WName"); // 创建子节点（创建元素节点）
        QDomText domtext2=domdoct.createTextNode("WName"); // 可创建文本节点
        domtext2.setData(ui->lineEdit_Name->text()); // 设置子节点数据
        node2.appendChild(domtext2); // 将子节点数据进行绑定
        itemrootelement.appendChild(node2); // 将子节点绑定到父亲节点

        QDomElement node3=domdoct.createElement("WSex"); // 创建子节点（创建元素节点）
        QDomText domtext3=domdoct.createTextNode("WSex"); // 可创建文本节点
        domtext3.setData(ui->lineEdit_Sex->text()); // 设置子节点数据
        node3.appendChild(domtext3); // 将子节点数据进行绑定
        itemrootelement.appendChild(node3); // 将子节点绑定到父亲节点

        QDomElement node4=domdoct.createElement("WEducation"); // 创建子节点（创建元素节点）
        QDomText domtext4=domdoct.createTextNode("WEducation"); // 可创建文本节点
        domtext4.setData(ui->lineEdit_Education->text()); // 设置子节点数据
        node4.appendChild(domtext4); // 将子节点数据进行绑定
        itemrootelement.appendChild(node4); // 将子节点绑定到父亲节点

        QDomElement node5=domdoct.createElement("WDepartment"); // 创建子节点（创建元素节点）
        QDomText domtext5=domdoct.createTextNode("WDepartment"); // 可创建文本节点
        domtext5.setData(ui->lineEdit_Department->text()); // 设置子节点数据
        node5.appendChild(domtext5); // 将子节点数据进行绑定
        itemrootelement.appendChild(node5); // 将子节点绑定到父亲节点

        QDomElement node6=domdoct.createElement("WSalary"); // 创建子节点（创建元素节点）
        QDomText domtext6=domdoct.createTextNode("WSalary"); // 可创建文本节点
        domtext6.setData(ui->lineEdit_Salary->text()); // 设置子节点数据
        node6.appendChild(domtext6); // 将子节点数据进行绑定
        itemrootelement.appendChild(node6); // 将子节点绑定到父亲节点

    }
    domrootelement.appendChild(itemrootelement); // 绑定到顶层节点
    m_qfiles.write(domdoct.toString().toLocal8Bit().data());
    m_qfiles.close();
    QMessageBox::information(this,"提示","恭喜你，写入XML文件数据成功，请查看目录文件?",QMessageBox::Yes);
}

void ReadWriteXml::readxmlfiles()    // 读取xml文件
{
    if(!openxmlfiles(strcurrentfilename))
    {
        qDebug()<<"读取：打开XML文件失败，请重新检查？";
        return;
    }
    qDebug()<<"读取：打开XML文件成功，请认真操作xml!";

    QDomDocument docs;
    if(!docs.setContent(&m_qfiles))
    {
        m_qfiles.close();
        qDebug()<<"读取：操作setContent失败,请重新检查？";
        return;
    }
    qDebug()<<"读取：操作setContent成功,请认真操作!";


    // 读取根节点
    QDomElement root=docs.documentElement();

    // 读取第1个父亲节点
    QDomNode node=root.firstChild();

    while(!node.isNull())
    {
        QDomNodeList sonlist=node.childNodes(); // 读取子结点集合信息
        QString rootname=node.toElement().tagName(); // 读取父亲节点名称

        if(rootname.compare("worker")==0)
        {
            // 将子节点集合信息传递到读取子节点数据
            readrootxml(sonlist);
        }
        node=node.nextSibling(); // 读取下一个父节点
    }

}

void ReadWriteXml::readrootxml(QDomNodeList sonnodelist) // 读取子节点数据
{
   for(int sonnode=0;sonnode<sonnodelist.size();sonnode++)
   {
       // 获取子节点
       QDomElement sonelement=sonnodelist.at(sonnode).toElement();

       if(sonelement.toElement().tagName().compare("WNo")==0) // 取出子节点进行比较
       {
           ui->lineEdit_No_R->setText(sonelement.text());
       }
       else if(sonelement.toElement().tagName().compare("WName")==0)
       {
           ui->lineEdit_Name_R->setText(sonelement.text());
       }
       else if(sonelement.toElement().tagName().compare("WSex")==0)
       {
           ui->lineEdit_Sex_R->setText(sonelement.text());
       }
       else if(sonelement.toElement().tagName().compare("WEducation")==0)
       {
           ui->lineEdit_Education_R->setText(sonelement.text());
       }
       else if(sonelement.toElement().tagName().compare("WDepartment")==0)
       {
           ui->lineEdit_Department_R->setText(sonelement.text());
       }
       else if(sonelement.toElement().tagName().compare("WSalary")==0)
       {
           ui->lineEdit_Salary_R->setText(sonelement.text());
       }
   }
}



void ReadWriteXml::on_pushButton_WriteXml_clicked()
{
    writexmlfiles();
}

void ReadWriteXml::on_pushButton_ReadXml_clicked()
{
    readxmlfiles();
}
