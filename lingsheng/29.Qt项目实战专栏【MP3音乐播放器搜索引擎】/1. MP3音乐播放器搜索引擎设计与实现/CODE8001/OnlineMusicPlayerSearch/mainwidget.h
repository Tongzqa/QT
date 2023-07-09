﻿#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include <QPainter>  // 实现窗口重绘

#include <QNetworkRequest>          // HTTP的URL请求管理
#include <QNetworkAccessManager>    // URL的上传管理
#include <QNetworkReply>            // 网页回复数据触发信号的类
#include <QEventLoop>               // QEventLoop类提供一种进入和离开事件循环的方法
#include <QJsonArray>               // QJsonArray类用于封装JSON数组
#include <QJsonObject>              // QJsonObject类用于封装JSON对象
#include <QJsonDocument>

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

#include <QMessageBox>
#include <QTime>
#include <math.h>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();


    // 处理窗口UI图片
    void paintEvent(QPaintEvent *event);

signals: // 暂时未用
    void finish(QByteArray);
    void lyricShow(QString);


private slots:
    void on_pushButton_Close_clicked(); // 关闭窗口
    void on_pushButton_Skin_clicked(); // 更换窗口皮肤
    void on_pushButton_About_clicked(); // 应用程序关于操作

    void on_pushButton_Search_clicked(); // 搜索音乐
    void on_VopSlider_valueChanged(int value); // 音量调节


    void on_progressSlider_valueChanged(int value);    // 播放进度
    void on_progressSlider_sliderPressed();
    void on_progressSlider_sliderReleased();

    void on_pushButton_Front_clicked();  // 上一曲
    void on_pushButton_Playpause_clicked();   // 播放暂停
    void on_pushButton_Next_clicked(); // 下一曲
    void on_pushButton_Loopplay_clicked(); // 循环播放


    // 更新播放的进度条和显示的时间
    void updateDuration(qint64);

    // 读取网络数据的槽函数
    void netReply(QNetworkReply *);

    // 显示歌词的槽函数
    void lyricTextShow(QString);




protected:
    // 音乐歌曲下载 和播放
    void downloadPlayer(QString album_id,QString hash);

    // 访问HTTP网页
    void httpAccess(QString);

    // 音乐的hash和ablum_id值解析，使用JSON
    void hashJsonAnalysis(QByteArray);

    // 搜索的音乐数据信息JSON解析，解析出真正的音乐文件和歌词
    QString musicJsonAnalysis(QByteArray);


private:
    Ui::MainWidget *ui;

    // 网络 播放器 SQLite数据库
    QNetworkRequest *request;
    QNetworkAccessManager *manager;
    QMediaPlayer *player;
    QMediaPlaylist *playerlist;
    QSqlDatabase db;
    int num,row;


    // 处理鼠标拖动窗口移动操作
private:
    QPoint m_mousePoint;
    QPoint movePoint;
    bool mousePress;
protected:
    void mouseMoveEvent(QMouseEvent *event); // 移动事件
    void mouseReleaseEvent(QMouseEvent *event); // 释放事件
    void mousePressEvent(QMouseEvent *event); // 按下事件


};
#endif // MAINWIDGET_H
