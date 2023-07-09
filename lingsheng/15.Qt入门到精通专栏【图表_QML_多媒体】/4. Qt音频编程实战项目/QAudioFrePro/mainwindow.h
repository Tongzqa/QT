#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <QMediaPlayer>
#include <QMediaPlaylist>
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
    QMediaPlaylist *playlist;

    QString drtTime; // 歌曲时长
    QString pstTime; // 播放位置


private slots:
    void onstatechg(QMediaPlayer::State state); // 按钮切换状态
    void onplaylistchg(int pos); // 播放列表
    void onDrtchg(qint64 drt); // 歌曲总时间长度
    void onpstchg(qint64 pos); // 播放歌曲当前位置


    void on_pushButton_open_clicked();
    void on_pushButton_PLayer_clicked();
    void on_pushButton_Pause_clicked();
    void on_pushButton_Stop_clicked();
    void on_pushButton_Prev_clicked();
    void on_pushButton_next_clicked();
    void on_pushButton_Volumn_clicked();
    void on_horizontalSlider_Volumn_valueChanged(int value);
    void on_horizontalSlider_Speed_valueChanged(int value);
};
#endif // MAINWINDOW_H
