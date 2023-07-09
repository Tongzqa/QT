#include "qmyselfvideowidget.h"

QMyselfVideoWidget::QMyselfVideoWidget(QWidget *parent):QVideoWidget(parent)
{

}
void QMyselfVideoWidget::SetMediaPlayer(QMediaPlayer *player)
{
    //    设置播放器操作
    theplayer=player;
}

void QMyselfVideoWidget::keyPressEvent(QKeyEvent *event) // 键盘按键事件，当用户按下ESC退出全局播放状态
{
    if((event->key()==Qt::Key_Escape)&& (isFullScreen()))
    {
        setFullScreen(false);
        event->accept();
        QVideoWidget::keyPressEvent(event);
    }
}

void QMyselfVideoWidget::mousePressEvent(QMouseEvent *event) // 鼠标按键事件，当用户控制暂停和继续播放
{
    if(event->button()==Qt::LeftButton)
    {
        if(theplayer->state()==QMediaPlayer::PlayingState)
            theplayer->pause();
        else
            theplayer->play();
    }

    QVideoWidget::mousePressEvent(event);
}
