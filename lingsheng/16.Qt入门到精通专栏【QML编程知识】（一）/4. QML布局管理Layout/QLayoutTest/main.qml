import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.2

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Layout布局管理器--测试程序")

    // 行布局
    RowLayout{

        Rectangle{
            Layout.preferredHeight: 100
            Layout.preferredWidth: 100
            Layout.alignment: Qt.AlignLeft
            color: "red" // 红色

        }

        Rectangle{
            Layout.preferredHeight: 75
            Layout.preferredWidth: 120
            Layout.alignment: Qt.AlignLeft
            color: "cyan" // 青色
        }

        Rectangle{
            Layout.preferredHeight: 50
            Layout.preferredWidth: 250
            Layout.alignment: Qt.AlignRight
            color: "darkorange" // 暗桔色
        }
    }


    // 列布局
    ColumnLayout{
        x:150
        y:150

        Rectangle{
            Layout.alignment: Qt.AlignCenter // 居中对齐
            color: "yellow" // 黄色
            Layout.preferredHeight: 120
            Layout.preferredWidth: 60;
        }

        Rectangle{
            Layout.alignment: Qt.AlignRight // 右对齐
            color: "blue" // 蓝色
            Layout.preferredHeight: 90
            Layout.preferredWidth: 50;
        }

        Rectangle{
            Layout.alignment: Qt.AlignBottom // 底部对齐
            color: "blueviolet" // 蓝紫色
            Layout.preferredHeight: 180
            Layout.preferredWidth: 55;
        }

    }


}
