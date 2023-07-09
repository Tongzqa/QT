import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Keys事件--测试程序")

    Rectangle{
        id:keysrecttest
        anchors.centerIn: parent

        width: 450
        height: 200
        color: "red"

        radius: 10
        focus: true // 不设置焦点，获取不了键盘事件

        Keys.onPressed: {
            console.log("key:"+event.key)
            console.log("scancode:"+event.nativeScanCode)
            console.log("text:"+event.text)
        }

        Keys.onTabPressed: {
            console.log("监控区域提示：你已经按下Tab键!")
        }

        Keys.onSpacePressed: {
            console.log("监控区域提示：你已经按下空格键!")
        }
    }

}
