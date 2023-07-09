#include "animationbutton.h"

AnimationButton::AnimationButton(QWidget *parent) : QWidget(parent)
{
    enter=true;
    leave=false;
    pixwidth=0;
    pixheight=0;
    oldwidth=0;
    oldheight=0;

    enteranimation=new QPropertyAnimation(this,"");
    enteranimation->setStartValue(0);
    enteranimation->setEndValue(5);
    enteranimation->setDuration(200);
    connect(enteranimation,SIGNAL(valueChanged(QVariant)),this,
            SLOT(enterimagechanged(QVariant)));

    leaveanimation=new QPropertyAnimation(this,"");
    leaveanimation->setStartValue(0);
    leaveanimation->setEndValue(5);
    leaveanimation->setDuration(200);
    connect(leaveanimation,SIGNAL(valueChanged(QVariant)),this,
            SLOT(leaveimagechanged(QVariant)));

}

AnimationButton::~AnimationButton()
{
    // 删除对象指针
    delete enteranimation;
    delete leaveanimation;
}

void AnimationButton::enterEvent(QEvent *event)
{
    enter=true;
    leave=false;
    pixwidth=pixwidth-25;
    pixheight=pixheight-25;
    enteranimation->start();
}

void AnimationButton::leaveEvent(QEvent *event)
{
    enter=false;
    leave=true;
    pixwidth=oldwidth;
    pixheight=oldheight;
    leaveanimation->start();
}

void AnimationButton::paintEvent(QPaintEvent *event)
{
    if(image.isEmpty())
    {
        return ;
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 通过此QPixmap类中scaled()函数对图像进行放大或缩小
    QPixmap pix(image);
    pix=pix.scaled(targetwidth,targetheight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    if(enter || leave)
    {
        int pixx=rect().center().x()-targetwidth/2;
        int pixy=rect().center().y()-targetheight/2;

        QPoint point(pixx,pixy);
        painter.drawPixmap(point,pix);
        painter.drawText(QRectF(0,height()-20,width(),20),Qt::AlignCenter,text);
    }
}

void AnimationButton::enterimagechanged(QVariant index)
{
    int i=index.toInt();
    targetwidth=pixwidth+i*5;
    targetheight=pixheight+i*5;
    update();
}

void AnimationButton::leaveimagechanged(QVariant index)
{
    int i=index.toInt();
    targetwidth=pixwidth-i*5;
    targetheight=pixheight-i*5;
    update();
}

void AnimationButton::settext(QString text) // 显示文字
{
    this->text=text;
    update();
}

void AnimationButton::setimage(QString image) // 显示图像
{
    this->image=image;
    QPixmap pix(image);
    pixwidth=pix.width();
    pixheight=pix.height();
    oldwidth=pixwidth;
    oldheight=pixheight;

    targetwidth=pixwidth-25;
    targetheight=pixheight-25;
    update();
}
