#ifndef ANIMATIONBUTTON_H
#define ANIMATIONBUTTON_H

#include <QWidget>

#include <QVariant>
class QPropertyAnimation;

#include "qdebug.h"
#include "qpainter.h"
#include "qpropertyanimation.h"


class AnimationButton : public QWidget
{
    Q_OBJECT
public:
    explicit AnimationButton(QWidget *parent = nullptr);
    ~AnimationButton();

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    bool enter; // 是否进入
    bool leave; // 是否离开
    int pixwidth; // 图片宽度
    int pixheight; // 图片调度
    int oldwidth; // 图片原宽度
    int oldheight; // 图片原高度

    int targetwidth; // 目标宽度
    int targetheight; // 目标高度
    QString text; // 图像文字
    QString image; // 图像路径

    QPropertyAnimation *enteranimation; // 进入动画
    QPropertyAnimation *leaveanimation; // 离开动画

private slots:
    void enterimagechanged(QVariant index);
    void leaveimagechanged(QVariant index);

public slots:
    void settext(QString text); // 显示文字
    void setimage(QString image); // 显示图像





};

#endif // ANIMATIONBUTTON_H
