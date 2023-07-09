import QtQuick 2.12
import QtQuick.Window 2.12

import QtQuick.Controls 2.4


Window {
    visible: true
    width: 900
    height: 300
    title: qsTr("Qt Quick Canvas画布--测试程序")

    Row{
        anchors.centerIn: parent
        spacing: 20

        CProgresBars{
            id:progress1
            linewidth:10
            value: 0.13
            size:150
            secondarycolor: "red"
            primarycolor: "blue"

            Text {

                text:parseInt(progress1.value*100)+"%"
                anchors.centerIn: parent
                font.pointSize: 20;
                color: progress1.primarycolor
            }
        }

        CProgresBars{
            id:progress2
            linewidth:10
            value: 0.25
            size:150
            secondarycolor: "red"
            primarycolor: "green"

            Text {

                text:parseInt(progress2.value*100)+"%"
                anchors.centerIn: parent
                font.pointSize: 20;
                color: progress2.primarycolor
            }
        }

        CProgresBars{
            id:progress3
            linewidth:10
            value: 0.55
            size:150
            secondarycolor: "red"
            primarycolor: "aqua"

            Text {

                text:parseInt(progress3.value*100)+"%"
                anchors.centerIn: parent
                font.pointSize: 20;
                color: progress3.primarycolor
            }
        }

        CProgresBars{
            id:progress4
            linewidth:10
            value: 0.75
            size:150
            secondarycolor: "red"
            primarycolor: "darkblue"

            Text {

                text:parseInt(progress4.value*100)+"%"
                anchors.centerIn: parent
                font.pointSize: 20;
                color: progress4.primarycolor
            }
        }


        CProgresBars{
            id:progress5
            linewidth:10
            value: 0.95
            size:150
            secondarycolor: "red"
            primarycolor: "darkorange"

            Text {

                text:parseInt(progress5.value*100)+"%"
                anchors.centerIn: parent
                font.pointSize: 20;
                color: progress5.primarycolor
            }
        }



    }
}
