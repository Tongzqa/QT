#include "frmanimationbutton.h"
#include "ui_frmanimationbutton.h"

FrmAnimationButton::FrmAnimationButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FrmAnimationButton)
{
    ui->setupUi(this);

    QString qss="color:#BECEC6;background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #1B3152,stop:1 #255C80);";
    this->setStyleSheet(qss);

    ui->widget1->settext("主页");
    ui->widget1->setimage(":/new/prefix1/image/v-home.png");

    ui->widget2->settext("通讯录");
    ui->widget2->setimage(":/new/prefix1/image/v-contact.png");

    ui->widget3->settext("相册");
    ui->widget3->setimage(":/new/prefix1/image/v-img.png");

    ui->widget4->settext("录音");
    ui->widget4->setimage(":/new/prefix1/image/v-record.png");

    update();
}

FrmAnimationButton::~FrmAnimationButton()
{
    delete ui;
}

