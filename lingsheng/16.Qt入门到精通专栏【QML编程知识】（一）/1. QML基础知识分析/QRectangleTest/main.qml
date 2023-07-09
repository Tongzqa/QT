import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Rectangle元素--测试程序")

    Rectangle{
        width: 640
        height: 480
        color: "yellow"

        Rectangle{
            x:30
            y:30
            width: 60
            height: 50
            color: "lightgreen"
        }
    }

    Rectangle{
        x:30
        y:100
        width: 400
        height: 150
        color:"red"

        Rectangle{
            x:100
            y:40
            width: 200
            height: 60
            color: "deepskyblue"
        }
    }
}
