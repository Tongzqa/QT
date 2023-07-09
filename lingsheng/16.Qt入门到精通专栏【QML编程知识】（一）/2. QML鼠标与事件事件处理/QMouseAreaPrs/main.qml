import QtQuick 2.12
import QtQuick.Window 2.12

import QtQuick.Controls 2.0

Window {
    visible: true
    width: 600
    height: 400
    title: qsTr("MouseArea事件--测试程序")

    Rectangle{
        id:mouseareatest

        anchors.centerIn: parent //  通过锚将矩形定位到窗口正中心

       // x:30
       // y:30

        width: 450
        height: 200
        color: "red"

        // radius:3  // 0:直角 大于0:圆角

        MouseArea{
            anchors.fill: parent
            acceptedButtons: Qt.AllButtons

            hoverEnabled: true // 此属性为false，鼠标进入、离开、移动不能捕获到

            onPositionChanged: {
                console.log("监控区域提示：你当前鼠标移动坐标为：("+mouseX+","+mouseY+")");
            }

            // 点击事件
            onClicked: {

                if(mouse.button===Qt.LeftButton){
                    console.log("监控区域提示：你已经按下鼠标左键!");
                }
                else if(mouse.button===Qt.RightButton){
                    console.log("监控区域提示：你已经按下鼠标右键!");
                }
                else if(mouse.button===Qt.MidButton){
                    console.log("监控区域提示：你已经按下鼠标中间键!");
                }
            }

            // 双击事件 onDoubleClicked:

        }
    }

}
