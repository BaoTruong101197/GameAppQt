import QtQuick 2.0

Item {
    property int widthModal: 0
    property int heightModal: 0
    property int score: 0
    property int highScore: 0
    property string scoreText: "Số điểm của bạn là: " + score
    property string highScoreText: "Điểm cao: " + highScore
    z: 1000
    signal requestGoToHomeScreen()
    signal requestContinueGame();

    Overlay {
        width: parent.width; height: parent.height
    }


    Rectangle {
        id: modal
        anchors.centerIn: parent
        width: widthModal; height: heightModal
        color: '#fff'
        radius: 20
        opacity: 1

        Item {
            width: modal.width - 100
            height: modal.height - 100
            anchors.centerIn: parent
            Column {
                id: textColumn
                spacing: 20
                Text {
                    id: incorrectText
                    text: "Oops. Sai rồi nhé :D"
                    color: "red"
                    font.pixelSize: 35
                    font.family: "Helvetica"
                }

                Text {
                    text: scoreText
                    font.pixelSize: 20
                    font.family: "Helvetica"
                }

                Text {
                    text: highScoreText
                    font.pixelSize: 20
                    font.family: "Helvetica"
                }
            }

            Row {
                transformOrigin: Item.Center
                anchors.top: textColumn.bottom
                anchors.topMargin: 50
                spacing: 20
                Rectangle {
                    id: backBtn
                    width: backBtnText.width + 20; height: backBtnText.height + 20
                    color: "green"
                    border.color: mouseArea1.pressed ? "#8c6339" : "green"
                    radius: 10

                    Text {
                        id: backBtnText
                        font.family: "Helvetica"
                        anchors.centerIn: parent
                        text: "Trở lại trang chủ"
                        font.pixelSize: 20
                        color: "#fff"
                    }

                    MouseArea {
                        id: mouseArea1
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.OpenHandCursor

                        onClicked: {
                            requestGoToHomeScreen()
                        }
                    }
                }

                Rectangle {
                    id: continueBtn
                    width: continueBtnText.width + 20; height: continueBtnText.height + 20
                    color: "#fff"

                    Text {
                        id: continueBtnText
                        font.family: "Helvetica"
                        anchors.centerIn: parent
                        text: "Tiếp tục"
                        font.pixelSize: 20
                        color: "#000"
                    }

                    MouseArea {
                        id: mouseArea2
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.OpenHandCursor

                        onClicked: {
                            requestContinueGame()
                        }
                    }
                }
            }
        }
    }
}


