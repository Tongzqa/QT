#ifndef QMYSELFVIDEOWIDGET_H
#define QMYSELFVIDEOWIDGET_H

#include <QWidget>
#include <QObject>
#include <QVideoWidget>
#include <QMediaPlayer>

#include <QKeyEvent>
#include <QMouseEvent>

class QMyselfVideoWidget : public QVideoWidget
{
public:
    QMyselfVideoWidget(QWidget *parent=Q_NULLPTR);

    void SetMediaPlayer(QMediaPlayer *player);

private:
    QMediaPlayer *theplayer;

protected:
    void keyPressEvent(QKeyEvent *event); // 键盘按键事件，当用户按下ESC退出全局播放状态
    void mousePressEvent(QMouseEvent *event); // 鼠标按键事件，当用户控制暂停和继续播放


};

#endif // QMYSELFVIDEOWIDGET_H
