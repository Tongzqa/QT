#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 禁止窗口改变尺寸大小
    this->setFixedSize(this->geometry().size());

    // 去掉标题栏
    this->setWindowFlag(Qt::FramelessWindowHint);

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/images/musicplayer_ui.jpg"));

}



void MainWidget::on_pushButton_Close_clicked()
{
    // 关闭窗口
    close();
}

void MainWidget::on_pushButton_Skin_clicked()
{

}

void MainWidget::on_pushButton_About_clicked()
{

}

void MainWidget::on_pushButton_Search_clicked()
{

}

void MainWidget::on_VopSlider_valueChanged(int value)
{

}


void MainWidget::on_progressSlider_valueChanged(int value)
{

}

void MainWidget::on_progressSlider_sliderPressed()
{

}

void MainWidget::on_progressSlider_sliderReleased()
{

}

void MainWidget::on_pushButton_Front_clicked()
{

}

void MainWidget::on_pushButton_Playpause_clicked()
{

}

void MainWidget::on_pushButton_Next_clicked()
{

}

void MainWidget::on_pushButton_Loopplay_clicked()
{

}


// 更新播放的进度条和显示的时间
void MainWidget::updateDuration(qint64)
{

}

// 读取网络数据的槽函数
void MainWidget::netReply(QNetworkReply *)
{

}

// 显示歌词的槽函数
void MainWidget::lyricTextShow(QString)
{

}

// 音乐歌曲下载和播放
void MainWidget::downloadPlayer(QString album_id,QString hash)
{

}

// 访问HTTP网页
void MainWidget::httpAccess(QString)
{

}

// 音乐的hash和ablum_id值解析，使用JSON
void MainWidget::hashJsonAnalysis(QByteArray)
{

}

// 搜索的音乐数据信息JSON解析，解析出真正的音乐文件和歌词
QString MainWidget::musicJsonAnalysis(QByteArray)
{

    return "test";
}

void MainWidget::mouseMoveEvent(QMouseEvent *event) // 移动事件
{
    if(mousePress)
    {
        QPoint movepos=event->globalPos(); // 窗口初始位置
        move(movepos-movePoint);
    }

}

void MainWidget::mouseReleaseEvent(QMouseEvent *event) // 释放事件
{
    Q_UNUSED(event)
    mousePress=false;
}

void MainWidget::mousePressEvent(QMouseEvent *event) // 按下事件
{
    if(event->button()==Qt::LeftButton)
    {
        mousePress=true;
    }

    movePoint=event->globalPos()-pos();
}
