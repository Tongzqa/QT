import QtQuick 2.12
import QtQuick.Window 2.12

// 使用到控件的时候，加上下面这个
import QtQuick.Controls 2.5

Window {
    visible: true // 属性：可见
    width: 800 // 宽度
    height: 600 // 高度
    title: qsTr("Qt Quick测试程序") // 标准名称


    // 创建一个按钮Button
    Button
    {
        id:exitbutton
        text: "Exit Button"
        anchors.left:parent.left
        anchors.leftMargin: 100 // 左边距离
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 500

        onClicked: {
            Qt.quit(); // 退出操作
        }
    }

    // 创建一个矩形Rectangle
    Rectangle{
        // 坐标:x y
        x:100
        y:150

        width: 190
        height: 70

        color: "#00B000"
        opacity: 1.2;
    }

    // 创建一个复选框控件 CheckBox
    CheckBox{
        id:checkboxcontrol
        text: qsTr("湖南省长沙市")
        checked: true
        x:100
        y:300

        indicator: Rectangle{
            implicitWidth: 60
            implicitHeight: 60
            x:checkboxcontrol.leftPadding
            y:parent.height/2-height/2;
            radius: 3

            border.color: checkboxcontrol.down?"#18a81a":"*888999" // 边框颜色

            Rectangle{
                width: 30
                height: 30
                x:15
                y:15
                radius: 3

                color: checkboxcontrol.down?"#18a81a":"*888999"
            }
        }

        // 改变控件字体大小
        contentItem: Text {
            text: checkboxcontrol.text
            font.pixelSize:30

            color: checkboxcontrol.down?"#18a81a":"*888999"
            verticalAlignment: Text.AlignVCenter // 垂直对齐
            leftPadding: checkboxcontrol.indicator.width+checkboxcontrol.spacing
        }
    }


    // 动画效果操作
    Rectangle{
        id:irect // 定义矩形
        x:400
        y:120
        width: 300
        height: 60

        state: "normal" // 设置默认状态

        states: [ // 状态列表
            State {
                name:"normal"
                PropertyChanges {
                    target:irect
                    color: "red"
                }
            },
            State {
                name:"lightblue"

                PropertyChanges {
                    target: irect
                    color:"lightblue"
                    width:200
                    height:60

                }
            }
        ]

        transitions: [
            Transition {
                from: "normal"
                to: "lightblue"
                PropertyAnimation{
                    properties: "color,width,height"
                    duration: 3000 // 过程时间
                }
            }
        ]
    }


    Button{
        id:changesstatess
        x:400
        y:190
        text: "change state"
        onClicked: irect.state="lightblue";
    }

    Button{
        id:recoverss
        x:570
        y:190
        text: "recoverss state"
        onClicked: irect.state="normal";
    }









}
