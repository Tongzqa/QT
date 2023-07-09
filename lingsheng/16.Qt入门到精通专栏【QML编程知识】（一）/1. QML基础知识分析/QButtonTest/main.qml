import QtQuick 2.12
import QtQuick.Window 2.12

import QtQuick.Controls 2.5  // 控件

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Button元素--测试程序")


    // 定义变量统计单击次数
    property int count:1

    Button{
        id:mybutton1
        x:200
        y:150
        width: 120
        height: 40

        text: "测试点击按钮次数"

        // 信号槽连接：单击信号
        onClicked: {
            console.log("你好，mybutton1按钮已经被你单击:"+count++)
        }
    }

    Button{
        id:mybutton2
        x:400
        y:150
        width: 120
        height: 40

        // 添加图标
        icon.source: "qrc:/new/prefix1/images/login01.bmp"
        icon.color: "transparent"

        text: "登录系统"
    }



}
