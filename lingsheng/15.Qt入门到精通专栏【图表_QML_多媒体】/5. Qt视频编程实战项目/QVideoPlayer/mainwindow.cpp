#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player=new QMediaPlayer(this);
    player->setNotifyInterval(1000);
    player->setVideoOutput(ui->graphicsView); // 视频显示组件

    ui->graphicsView->SetMediaPlayer(player); // 设置显示组件的关联播放器

    connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,
            SLOT(onstatebuttonchanged(QMediaPlayer::State)));

    connect(player,SIGNAL(positionChanged(qint64)),this,
            SLOT(onpostimechanged(qint64)));

    connect(player,SIGNAL(durationChanged(qint64)),this,
            SLOT(ondrttimechanged(qint64)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onstatebuttonchanged(QMediaPlayer::State state) // 控制按钮状态切换
{
    ui->pushButton_Play->setEnabled(!(state==QMediaPlayer::PlayingState));
    ui->pushButton_Pause->setEnabled(state==QMediaPlayer::PlayingState);
    ui->pushButton_Stop->setEnabled(state==QMediaPlayer::PlayingState);
}

void MainWindow::ondrttimechanged(qint64 drt) // 视频文件时间长度、更新变化
{
    ui->horizontalSlider_position->setMaximum(drt);

    int sec=drt/1000; // 秒
    int min=sec/60; // 分
    sec=sec%60; // 余数秒
    drtTime=QString::asprintf("%d:%d",min,sec);
    ui->label_Time->setText(posTime+"|"+drtTime);
}

void MainWindow::onpostimechanged(qint64 pos) // 播放视频当前位置时间、更新变化
{
    if(ui->horizontalSlider_position->isSliderDown())
        return ; // 如果正在手动滑动条，则直接退出

    ui->horizontalSlider_position->setSliderPosition(pos);

    int sec=pos/1000; // 秒
    int min=sec/60; // 分
    sec=sec%60; // 余数秒
    posTime=QString::asprintf("%d:%d",min,sec);
    ui->label_Time->setText(posTime+"|"+drtTime);

}

void MainWindow::on_pushButton_Open_clicked()
{
    QString currentpath=QDir::homePath(); // 获取系统当前目录
    QString dlgtitle="请选择视频文件";
    QString filter="所有文件(*.*);;mp4文件(*.mp4)"; // 文件过滤器
    QString strfile=QFileDialog::getOpenFileName(this,dlgtitle,currentpath,filter);

    if(strfile.isEmpty())
        return ;


    QFileInfo fileinfo(strfile);
    ui->label_Name->setText(fileinfo.fileName());
    player->setMedia(QUrl::fromLocalFile(strfile)); // 设置播放文件
    player->play();

}

void MainWindow::on_pushButton_Play_clicked()
{
    player->play();

}

void MainWindow::on_pushButton_Pause_clicked()
{
    player->pause();

}

void MainWindow::on_pushButton_Stop_clicked()
{
    player->stop();

}

void MainWindow::on_pushButton_Volumn_clicked()
{
    bool bmute=player->isMuted();
    player->setMuted(!bmute);

    if(bmute)
        ui->pushButton_Volumn->setIcon(QIcon(":/new/prefix1/images/volumn.bmp"));
    else
        ui->pushButton_Volumn->setIcon(QIcon(":/new/prefix1/images/mute.bmp"));
}

void MainWindow::on_horizontalSlider_Volumn_valueChanged(int value)
{
    player->setVolume(value);

}

void MainWindow::on_horizontalSlider_position_valueChanged(int value)
{
    player->setPosition(value);

}
