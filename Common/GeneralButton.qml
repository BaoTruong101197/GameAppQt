import QtQuick 2.0

Rectangle {
    id: container
    width: 100; height: 100
    color: "#fff"
    radius: 20
    property alias text: text
    signal buttonClicked()

    Text {
        id: text
        font.family: "Helvetica"
        anchors.centerIn: parent
        text: "text"
        font.pixelSize: 25
        color: "#000"
        font.bold: false
    }

    MouseArea {
        id: mouseArea1
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.OpenHandCursor

        onClicked: {
            buttonClicked()
        }
    }
}
