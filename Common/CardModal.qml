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
                GeneralButton {
                    id: backBtn
                    width: text.width + 20; height: text.height + 20
                    color: "green"
                    text.text: "Trở lại trang chủ"
                    text.color: "#fff"
                    text.font.pixelSize: 20
                    text.font.bold: false

                    onButtonClicked: {
                        requestGoToHomeScreen()
                    }
                }

                GeneralButton {
                    id: continueBtn
                    width: text.width + 20; height: text.height + 20
                    color: "#fff"
                    text.text: "Chơi lại"
                    text.color: "#000"
                    text.font.pixelSize: 20
                    text.font.bold: false

                    onButtonClicked: {
                        requestContinueGame()
                    }
                }
            }
        }
    }
}


