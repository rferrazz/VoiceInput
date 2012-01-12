import QtQuick 1.1
import com.nokia.meego 1.0

Item {
    width: parent.width
    height: 70
    z:7

    property alias title: h_title.text
    property alias subtitle: h_subtilte.text

    Rectangle {
        width: parent.width
        height: parent.height
        color:"#f2f2f2"
    }

    Rectangle {
        id: top_banner
        x: -1
        y: -1
        width: parent.width + 1
        height: 71
        color: "#1086d6"

        Text {
            id:h_title
            visible: true
            anchors.verticalCenter: parent.verticalCenter
            x:20
            color: "#ffffff"
            font.family: "Nokia Pure Text Light"
            font.pixelSize: 30
        }

        Text {
            id:h_subtilte
            y:42
            x:20
            font.family: "Nokia Pure Text Light"
            font.pixelSize: 22
            color:"blue"
        }
    }
}
