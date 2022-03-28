import QtQuick 2.4
import QtQuick.Layouts 1.1
import Enums 1.0

Item {
    id: container
    width: 1920; height: 950

    Item {
        width: 640; height: 800
        anchors.centerIn: parent

        Rectangle {
            anchors.fill: parent
            color: "#fff"
            radius: 30
        }

        Text {
            id: titleText
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            anchors.topMargin: 50
            font.pixelSize: 28
            text: "Hello mọi người. Cùng chơi trò chơi nào :D"
            font.family: "Helvetica"
            font.bold: true
        }

        Text {
            id: descText
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            anchors.topMargin: 120
            font.pixelSize: 24
            font.bold: false
            text: getCountOfGames()
            font.family: "Helvetica"
        }

        ListView {
            id: listGames
            width: parent.width - 100; height: 320
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20
            y: 220
            model: dataModel
            delegate: component
            snapMode: ListView.SnapToItem
            orientation: Qt.Horizontal
            interactive: false
        }

        Component {
            id: component
            Item {
                width: 200; height: 250
                Rectangle {
                    id: rect
                    anchors.fill: parent
                    border.color: mouseArea.pressed ? "#8c6339" : "black"
                    border.width: 2
                    Text {
                        id: gameName
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignTop
                        anchors.topMargin: 15
                        font.pixelSize: 20
                        text: name
                        font.family: "Helvetica [Cronyx]"
                    }

                    Image {
                        id: gameImg
                        anchors.horizontalCenter: parent.horizontalCenter
                        y: 50
                        width: parent.width - 10; height: parent.height - 55
                        source: img
                    }

                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.OpenHandCursor

                        onClicked: {
                            myAppMain.setCurrentView(Enums.HMI_VIEW_EASYMATH)
                        }
                    }

                }
            }
        }

    }

    function getCountOfGames() {
        return "Hiện nay đang có " + myAppMain.countOfGames() + " games. Vui lòng chọn!"
    }
}
