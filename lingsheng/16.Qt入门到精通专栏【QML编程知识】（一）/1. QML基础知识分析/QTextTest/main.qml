import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Text元素--测试程序")

    Rectangle{
        x:40
        y:40
        width: 200
        height: 80
        color: "chartreuse"
        border.color: "red"
        border.width:2

        Text {
            x:30
            y:23
            text: "零声教育"
            font.family: "隶书" // 字体名称
            font.pixelSize: 32 // 字体大小
            font.bold: true // 粗体
        }
    }

}
