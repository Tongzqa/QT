import QtQuick 2.9

Item {
    id:myroot

    property int size:150
    property int linewidth:5
    property real value:0

    property color primarycolor:"blue"
    property color secondarycolor:"red"

    property int animationduration:1000

    width: size
    height: size

    onValueChanged: {
        mycanvas.degree=value*360;
        can
    }

    Canvas{
        id:mycanvas

        property real degree:0

        anchors.fill: parent
        antialiasing: true

        onDegreeChanged: {
            requestPaint();
        }

        onPaint: {

            var ctx=getContext("2d");

            var x=myroot.width/2;
            var y=myroot.height/2;

            var radius=myroot.size/2-myroot.linewidth
            var startangle=(Math.PI/180)*270;
            var fullAngle=(Math.PI/180)*(270+360);
            var progressAngle=(Math.PI/180)*(270+degree);

            ctx.reset();
            ctx.lineCap='round';
            ctx.lineWidth=myroot.linewidth;

            ctx.beginPath();
            ctx.arc(x,y,radius,startangle,fullAngle);
            ctx.strokeStyle=myroot.secondarycolor;
            ctx.stroke();

            ctx.beginPath();
            ctx.arc(x,y,radius,startangle,progressAngle);
            ctx.strokeStyle=myroot.primarycolor;
            ctx.stroke();
        }

        Behavior on degree {
            NumberAnimation{
                duration: myroot.animationduration
            }
        }
    }

}
