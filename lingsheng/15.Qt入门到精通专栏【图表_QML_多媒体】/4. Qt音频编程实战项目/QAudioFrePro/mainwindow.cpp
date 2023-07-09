#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player=new QMediaPlayer(this);
    playlist=new QMediaPlaylist(this);

    playlist->setPlaybackMode(QMediaPlaylist::Loop); //  循环模式
    player->setPlaylist(playlist);

    connect(player,SIGNAL(statechanged(QMediaPlayer::State)),this,SLOT(onstatechg(QMediaPlayer::State)));


    connect(player,SIGNAL(positionChanged(qint64)),this,
            SLOT(onpstchg(qint64)));

    connect(player,SIGNAL(durationChanged(qint64)),this,
            SLOT(onDrtchg(qint64)));

    connect(playlist,SIGNAL(currentIndexChanged(int)),this,
            SLOT(onplaylistchg(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onstatechg(QMediaPlayer::State state) // 按钮切换状态
{
    ui->pushButton_PLayer->setEnabled(!(state==QMediaPlayer::PlayingState));
    ui->pushButton_Pause->setEnabled(state==QMediaPlayer::PlayingState);
    ui->pushButton_Stop->setEnabled(state==QMediaPlayer::PlayingState);
}


void MainWindow::onplaylistchg(int pos) // 播放列表
{
    ui->listWidget->setCurrentRow(pos);
    QListWidgetItem *item=ui->listWidget->currentItem();
    if(item)
        ui->label_Name->setText(item->text());
}

void MainWindow::onDrtchg(qint64 drt) // 歌曲总时间长度、更新变化进度
{
    ui->horizontalSlider_Speed->setMaximum(drt);

    int sec=drt/1000; // 秒
    int min=sec/60; // 分
    sec=sec%60; // 余数为秒

    drtTime=QString::asprintf("%d:%d",min,sec);
    ui->label_Time->setText(pstTime+"/"+drtTime);

}

void MainWindow::onpstchg(qint64 pos) // 播放歌曲当前位置、更新变化情况
{
    if(ui->horizontalSlider_Speed->isSliderDown())
        return ;

    ui->horizontalSlider_Speed->setSliderPosition(pos);

    int sec=pos/1000; // 秒
    int min=sec/60; // 分
    sec=sec%60; // 余数为秒

    pstTime=QString::asprintf("%d:%d",min,sec);
    ui->label_Time->setText(pstTime+"/"+drtTime);
}

void MainWindow::on_pushButton_open_clicked()
{
    // 添加歌曲文件
    QString currentpath=QDir::homePath();
    QString dlgtitle="请选择音频文件:"; // 文件对话框标题
    QString strfilter="所有文件(*.*);;音频文件(*.mp3);;mp3文件(*.mp3)";

    QStringList filelist=QFileDialog::getOpenFileNames(this,dlgtitle,currentpath,strfilter);

    if(filelist.count()<1)
        return;

    for (int i=0;i<filelist.count();i++)
    {
        QString afile=filelist.at(i);
        playlist->addMedia(QUrl::fromLocalFile(afile)); // 添加文件

        QFileInfo fileinfo(afile);
        ui->listWidget->addItem(fileinfo.fileName());  // 将文件添加到界面listwidget控件
    }

    if(player->state()!=QMediaPlayer::PlayingState)
        playlist->setCurrentIndex(0);
    player->play();
}

void MainWindow::on_pushButton_PLayer_clicked()
{
    if(playlist->currentIndex()<0)
        playlist->setCurrentIndex(0);
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

void MainWindow::on_pushButton_Prev_clicked()
{
    playlist->previous();
}

void MainWindow::on_pushButton_next_clicked()
{
    playlist->next();

}

void MainWindow::on_pushButton_Volumn_clicked()
{
    // 控制静音状态
    bool mute=player->isMuted();

    player->setMuted(!mute);
    if(mute)
    {
        ui->pushButton_Volumn->setIcon(QIcon(":/new/prefix1/images/volumn.bmp"));
    }
    else
    {
        ui->pushButton_Volumn->setIcon(QIcon(":/new/prefix1/images/mute.bmp"));

    }

}

void MainWindow::on_horizontalSlider_Volumn_valueChanged(int value)
{
    player->setVolume(value);
}

void MainWindow::on_horizontalSlider_Speed_valueChanged(int value)
{
    player->setPosition(value);
}
