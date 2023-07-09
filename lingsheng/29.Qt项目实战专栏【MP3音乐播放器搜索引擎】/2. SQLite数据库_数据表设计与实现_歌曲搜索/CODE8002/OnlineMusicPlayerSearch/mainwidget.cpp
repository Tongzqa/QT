#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    // 禁止窗口改变尺寸大小
    this->setFixedSize(this->geometry().size());

    // 去掉标题栏
    this->setWindowFlag(Qt::FramelessWindowHint);


    // 1:判断数据库连接是否存在，存在就得到连接，如果不存在添加得到链接
    if(QSqlDatabase::contains("sql_default_connection"))
    {
        // 根据数据库默认连接名称得到连接
        db=QSqlDatabase::database("sql_default_connection");
    }
    else
    {
        db=QSqlDatabase::addDatabase("QSQLITE"); // 添加数据库，得到该数据库的默认连接
        db.setDatabaseName("mp3listdatabase.db"); // 设置数据库文件名称
    }

    // 2:打开数据库，打开标识（QSqlQuery类
    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Open Data Error."),db.lastError().text());
    }
    else
    {
        // 3:定义query对象，得到打开的数据库标识
        QSqlQuery query;

        QString sql="create table if not exists searchlist(id integer,songname text,singername text,album_id text,hash text)";

        if(!query.exec(sql))
        {
            QMessageBox::critical(0,QObject::tr("create searchlist Error."),db.lastError().text());
        }

        // 歌曲痕迹数据表
        sql="create table if not exists historysong(id integer primary key autoincrement,songname text,singername text,album_id text,hash text)";

        if(!query.exec(sql))
        {
            QMessageBox::critical(0,QObject::tr("create historysong Error."),db.lastError().text());
        }

        // 查询历史数据表中的插入歌曲数据
        sql="select *from historysong;";
        if(!query.exec(sql))
        {
            QMessageBox::critical(0,QObject::tr("select historysong Error."),db.lastError().text());
        }

        while(query.next())
        {
            QString songname,singername;
            QSqlRecord rec=query.record();
            int ablumkey=rec.indexOf("songname");
            int hashkey=rec.indexOf("songername");
            songname=query.value(ablumkey).toString();
            singername=query.value(hashkey).toString();

            QString strshow=songname + "--" +singername;

            QListWidgetItem *item=new QListWidgetItem(strshow);
            ui->listWidget_History->addItem(item);
        }
    }

    // 播放操作
    player=new QMediaPlayer;
    playerlist=new QMediaPlaylist;

    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(updateDuration(qint64)));
    connect(this,SIGNAL(lyricShow(QString)),this,SLOT(lyricTextShow(QString)));

    connect(ui->listWidget_Search,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(playSearchMusic()));
    connect(ui->listWidget_History,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(playHistoryMusic()));

    num=0;
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/images/musicplayer_ui.jpg"));

}



void MainWidget::on_pushButton_Close_clicked()
{
    // 关闭窗口
    close();
}

void MainWidget::on_pushButton_Skin_clicked()
{

}

void MainWidget::on_pushButton_About_clicked()
{

}

// 搜索音乐
void MainWidget::on_pushButton_Search_clicked()
{
   // 将原有歌曲数据清空
    ui->listWidget_Search->clear();

    // 先清理数据库中已经存储的 hash等数据
    QSqlQuery query;
    QString sql="delete from searchlist;";

    if(!query.exec(sql))
    {
        QMessageBox::critical(0,QObject::tr("Delete searchlist Error."),db.lastError().text());
    }

    // 根据用户输入的MP3音乐名称，发起请求操作
    QString url=kugouSearchApi + QString("format=json&keyword=%1&page=1&pagesize=20&showtype=1").arg(ui->lineEdit_Search->text());

    httpAccess(url);

    QByteArray JsonData;
    QEventLoop loop;

    auto c=connect(this, finish, [&](const QByteArray & data)
    {
        JsonData=data;
        loop.exit(1);
    });

    loop.exec();
    disconnect(c);

    //解析网页回复的数据，将搜索得到的音乐hash和album_id与列表的索引值存放到数据库
    hashJsonAnalysis(JsonData);

}

void MainWidget::on_VopSlider_valueChanged(int value)
{

}


void MainWidget::on_progressSlider_valueChanged(int value)
{

}

void MainWidget::on_progressSlider_sliderPressed()
{

}

void MainWidget::on_progressSlider_sliderReleased()
{

}

void MainWidget::on_pushButton_Front_clicked()
{

}

void MainWidget::on_pushButton_Playpause_clicked()
{

}

void MainWidget::on_pushButton_Next_clicked()
{

}

void MainWidget::on_pushButton_Loopplay_clicked()
{

}


// 更新播放的进度条和显示的时间
void MainWidget::updateDuration(qint64 value)
{
    ui->progressSlider->setRange(0,player->duration());
    ui->progressSlider->setValue(value);
}

// 读取网络数据的槽函数
void MainWidget::netReply(QNetworkReply *reply)
{
    // 获取响应的信息，状态码为200属于正常
    QVariant status_code=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<status_code;

    reply->attribute(QNetworkRequest::RedirectionTargetAttribute);

    // 没有错误返回
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray data=reply->readAll();
        emit finish(data);
    }
    else
    {
        qDebug()<<reply->errorString();
    }

    reply->deleteLater();

}

// 显示歌词的槽函数
void MainWidget::lyricTextShow(QString)
{

}

// 音乐歌曲下载和播放
void MainWidget::downloadPlayer(QString album_id,QString hash)
{

}

// 访问HTTP网页
void MainWidget::httpAccess(QString url)
{
    // 实例化网络请求操作事项
    request=new QNetworkRequest;

    // 将url网页地址存入 request请求当中
    request->setUrl(url);

    // 实例化网络管理（访问）
    manager=new QNetworkAccessManager;

    // 通过get方法，上传具体的请求
    manager->get(*request);

    // 当网页回复消息时，触发 finished信号，我们才能够读取数据信息
    connect(manager,SIGNAL(finished(QNetworkReplay*)),this,SLOT(netReply(QNetworkReply*)));


}

// 音乐的hash和ablum_id值解析，使用JSON
void MainWidget::hashJsonAnalysis(QByteArray)
{

}

// 搜索的音乐数据信息JSON解析，解析出真正的音乐文件和歌词
QString MainWidget::musicJsonAnalysis(QByteArray)
{

    return "test";
}


void MainWidget::playSearchMusic() // 双击搜索列表，播放音乐
{

}
void MainWidget::playHistoryMusic() // 双击历史播放列表，播放音乐
{

}



void MainWidget::mouseMoveEvent(QMouseEvent *event) // 移动事件
{
    if(mousePress)
    {
        QPoint movepos=event->globalPos(); // 窗口初始位置
        move(movepos-movePoint);
    }

}

void MainWidget::mouseReleaseEvent(QMouseEvent *event) // 释放事件
{
    Q_UNUSED(event)
    mousePress=false;
}

void MainWidget::mousePressEvent(QMouseEvent *event) // 按下事件
{
    if(event->button()==Qt::LeftButton)
    {
        mousePress=true;
    }

    movePoint=event->globalPos()-pos();
}
