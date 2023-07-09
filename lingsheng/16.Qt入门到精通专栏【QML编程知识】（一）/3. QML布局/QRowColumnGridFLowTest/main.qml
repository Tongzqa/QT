import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.1

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("常见布局RowColumnGridFlow--测试程序")

    /*
    // Row布局
    Rectangle{
        id:myrowrect1
        x:30
        y:20
        width: 500
        height: 100
        border.width: 4
        border.color: "red"
        // radius:数字

        Row{
            anchors.centerIn: parent // 相对背景父窗口居中
            spacing: 20 // 设置行与行之间的间距
            Rectangle{color:"green";width: 40;height: 40 }
            Rectangle{color:"red";width: 40;height: 40 }
            Rectangle{color:"blue";width: 40;height: 40 }
            Rectangle{color:"cyan";width: 40;height: 40 }
            Rectangle{color:"orange";width: 40;height: 40 }
            Rectangle{color:"black";width: 40;height: 40 }
        }
    }

    // Column布局
    Rectangle{
        id:mycolumnrect2
        x:30
        y:150
        width: 500
        height: 350
        border.width: 4
        border.color: "red"
        // radius:数字

        Column{
            anchors.centerIn: parent // 相对背景父窗口居中
            spacing: 10 // 设置行与行之间的间距
            Rectangle{color:"green";width: 40;height: 40 }
            Rectangle{color:"red";width: 40;height: 40 }
            Rectangle{color:"blue";width: 40;height: 40 }
            Rectangle{color:"cyan";width: 40;height: 40 }
            Rectangle{color:"orange";width: 40;height: 40 }
            Rectangle{color:"black";width: 40;height: 40 }
        }
    }
*/

    /*
    // Grid布局
    Rectangle{
        id:myrowrect4
        x:30
        y:50
        width: 400
        height: 400
        border.width: 4
        border.color: "red"
        // radius:数字

        Grid{
            anchors.centerIn: parent // 相对背景父窗口居中
            spacing: 20 // 设置行与行之间的间距
            columns: 5
            Rectangle{color:"green";width: 40;height: 40 }
            Rectangle{color:"red";width: 40;height: 40 }
            Rectangle{color:"blue";width: 40;height: 40 }
            Rectangle{color:"cyan";width: 40;height: 40 }
            Rectangle{color:"orange";width: 40;height: 40 }
            Rectangle{color:"black";width: 40;height: 40 }
            Rectangle{color:"green";width: 40;height: 40 }
            Rectangle{color:"red";width: 40;height: 40 }
            Rectangle{color:"blue";width: 40;height: 40 }
            Rectangle{color:"cyan";width: 40;height: 40 }
            Rectangle{color:"orange";width: 40;height: 40 }
            Rectangle{color:"black";width: 40;height: 40 }
            Rectangle{color:"green";width: 40;height: 40 }
            Rectangle{color:"red";width: 40;height: 40 }
            Rectangle{color:"blue";width: 40;height: 40 }
            Rectangle{color:"cyan";width: 40;height: 40 }
            Rectangle{color:"orange";width: 40;height: 40 }
            Rectangle{color:"black";width: 40;height: 40 }
            Rectangle{color:"green";width: 40;height: 40 }
            Rectangle{color:"red";width: 40;height: 40 }
            Rectangle{color:"blue";width: 40;height: 40 }
            Rectangle{color:"cyan";width: 40;height: 40 }
            Rectangle{color:"orange";width: 40;height: 40 }
            Rectangle{color:"black";width: 40;height: 40 }
            Rectangle{color:"green";width: 40;height: 40 }
        }
    }
    */

    // Flow流方布局
    Flow{
        anchors.fill:parent //  填充方式
        anchors.margins: 5
        spacing: 20 // 设置行与行之间的间距

        Rectangle{color:"green";width: 40;height: 40 }
        Rectangle{color:"red";width: 40;height: 40 }
        Rectangle{color:"blue";width: 40;height: 40 }
        Rectangle{color:"cyan";width: 40;height: 40 }
        Rectangle{color:"orange";width: 40;height: 40 }
        Rectangle{color:"black";width: 40;height: 40 }
        Rectangle{color:"green";width: 40;height: 40 }
        Rectangle{color:"red";width: 40;height: 40 }
        Rectangle{color:"blue";width: 40;height: 40 }
        Rectangle{color:"cyan";width: 40;height: 40 }
        Rectangle{color:"orange";width: 40;height: 40 }
        Rectangle{color:"black";width: 40;height: 40 }
        Rectangle{color:"green";width: 40;height: 40 }
        Rectangle{color:"red";width: 40;height: 40 }
        Rectangle{color:"blue";width: 40;height: 40 }
        Rectangle{color:"cyan";width: 40;height: 40 }
        Rectangle{color:"orange";width: 40;height: 40 }
        Rectangle{color:"black";width: 40;height: 40 }
        Rectangle{color:"green";width: 40;height: 40 }
        Rectangle{color:"red";width: 40;height: 40 }
        Rectangle{color:"blue";width: 40;height: 40 }
        Rectangle{color:"cyan";width: 40;height: 40 }
        Rectangle{color:"orange";width: 40;height: 40 }
        Rectangle{color:"black";width: 40;height: 40 }
        Rectangle{color:"green";width: 40;height: 40 }
    }





}
