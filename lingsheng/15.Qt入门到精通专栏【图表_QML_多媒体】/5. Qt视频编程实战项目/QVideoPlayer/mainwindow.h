#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qmyselfvideowidget.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QMediaPlayer *player;
    QString drtTime; // 视频文件时间长度
    QString posTime; // 播放视频当前位置


private slots: // 自定义槽函数
    void onstatebuttonchanged(QMediaPlayer::State state); // 控制按钮状态切换
    void ondrttimechanged(qint64 drt); // 视频文件时间长度、更新变化
    void onpostimechanged(qint64 pos); // 播放视频当前位置时间、更新变化





    void on_pushButton_Open_clicked();
    void on_pushButton_Play_clicked();
    void on_pushButton_Pause_clicked();
    void on_pushButton_Stop_clicked();
    void on_pushButton_Volumn_clicked();
    void on_horizontalSlider_Volumn_valueChanged(int value);
    void on_horizontalSlider_position_valueChanged(int value);
};
#endif // MAINWINDOW_H
