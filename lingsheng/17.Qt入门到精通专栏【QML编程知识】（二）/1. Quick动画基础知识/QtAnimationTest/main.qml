import QtQuick 2.12
import QtQuick.Window 2.12

import QtQuick.Controls 2.0

Window {
    visible: true
    width: 800
    height: 400
    title: qsTr("QML动画基础知识--测试程序")
/*
    // 动画基础1
    Rectangle {
        id:myrect1
        x:30
        y:40
        width: 30
        height: 60
        color: "cyan" // 青色
    }

    Rectangle {
        id:myrect2
        x:30;
        y:40+myrect1.height+10
        width: 30
        height: 60;
        color: "darkorange" // 深橘色
    }

     PropertyAnimation { // 属性动画
         id:myanimation
         targets:[myrect1,myrect2] // 目标
         properties: "width,x"
         from: 30
         to:800
         duration: 30000
     }

     // 鼠标区域
     MouseArea {
         anchors.fill: parent
         onClicked: myanimation.running=true
     }
*/

/*
     // 动画基础2
    Rectangle {
        id:myrect3
        anchors.fill: parent
        color: "white"

        Rectangle {
            id:myrect4
            x:0
            y:0
            width: 50
            height: 600
            color: "orange"
        }
    }

    Timer {
        id:mytimer
        interval: 1000
        repeat: true // 启动重复触发，默认false
        running: true // 启动定时器，默认false

        triggeredOnStart: false // true则定时器在启动之后立即触发，然后再根据指定的时间间隔触发

        onTriggered: {
            if(myrect4.x+myrect4.width<myrect3.width)
            {
                myrect4.x+=60
            }
            else
            {
                myrect4.x=0
            }
        }
    }
*/

/*
    // 动画基础3
    Rectangle {
        id:myrect5
        width: 200
        height: 200
        color: "orange"
        anchors.centerIn: parent

        QtObject{
            id:myattr
            property  int counters;
            Component.onCompleted: {
                counters=10;
            }
        }
    }

    Text {
        id: mycountersshow
        anchors.centerIn: parent
        color: "white"
        font.pixelSize: 150
    }

    Timer { // 定时器
        id:mycountersdown
        interval: 1000
        repeat: true
        triggeredOnStart: true

        onTriggered: {
            mycountersshow.text=myattr.counters
            myattr.counters=myattr.counters-1;
            if(myattr.counters<0)
            {
                mycountersdown.stop();
            }
        }
    }

    Button { // 触发命令按钮
        id:mybuttonstart
        width: 200
        text: "开始倒计时"

        anchors.top: myrect5.bottom // 让按钮显示到矩形底部
        anchors.horizontalCenter: myrect5.horizontalCenter

        onClicked: { // 单击事件
            myattr.counters=10
            mycountersdown.start();
        }
    }
*/

    property int rangevalue: 65;
    property int nowrange:0;

    // 画布大小
    property int mw:300;
    property int mh:300;
    property int linewidth:3;

    // 画圆
    property double r:mh/2; // 圆心
    property double cr:r-20*linewidth; // 圆半径

    // 绘制曲线
    property int sx:0;
    property int sy:mh/2;
    property int axislength:mw; // 画轴长度
    property double wavewidth:0.01;  // 波浪宽度，数字越小越宽
    property double waveheight:5; // 波浪调度，数字越大越高
    property double speed:0.08;  // 波浪速度 数字越大速度越快
    property double xoffset:0; // 波浪x偏移量

    Canvas {
        id:mycanvas
        width: mw
        height: mh
        anchors.centerIn: parent

        onPaint: {
            var mytx=getContext("2d");

            mytx.clearRect(0,0,mw,mh);

            // 显示外面圈
            mytx.beginPath();
            mytx.strokeStyle='red'; // 红色
            mytx.arc(r,r,cr+2,0,2*Math.PI);
            mytx.stroke();

            mytx.beginPath();
            mytx.arc(r,r,cr,0,2*Math.PI);
            mytx.clip();

            // 显示曲线 sin
            mytx.save();
            var points=[];
            mytx.beginPath();

            for(var x = sx; x < sx + axislength; x += 20 / axislength){
                var y = -Math.sin((sx + x) * wavewidth + xoffset);
                var dy = mh * (1 - nowrange / 100 );
                points.push([x, dy + y * waveheight]);
                mytx.lineTo(x, dy + y * waveheight);
            }

            // 显示波浪
            mytx.lineTo(axislength,mh);
            mytx.lineTo(sx,mh);
            mytx.lineTo(points[0][0],points[0][1]);
            mytx.fillStyle='blue';
            mytx.fill();
            mytx.restore();

            // 显示百分数操作
            mytx.save();
            var size = 0.4*cr;
            mytx.font = size + 'px Arial';
            mytx.textAlign = 'center';
            mytx.fillStyle = "rgba(0, 255, 0, 0.8)";
            mytx.fillText(nowrange + '%', r, r + size / 2);
            mytx.restore();

            // 增加Rang值
            if(nowrange<=rangevalue)
            {
                nowrange=nowrange+1;
            }

            if(nowrange>rangevalue){
                nowrange=nowrange-1;
            }
            xoffset=xoffset+speed;
        }

        // 设计定时器
        Timer {
            id:mytimer
            running: false;
            repeat: true;
            interval: 100;
            onTriggered: {
                parent.requestPaint();
            }
        }
    }

    // 设计命令按钮
    Button {
        id:mybutton
        width: 80;
        height: 30;
        anchors.horizontalCenter: parent.horizontalCenter

        text: "开始运行"
        onClicked: {
            if(mytimer.running==false)
            {
                mytimer.start();
                mybutton.text="停止运行";
            }
            else
            {
                mytimer.stop();
                mybutton.text="开始运行";
            }
        }
    }

}
