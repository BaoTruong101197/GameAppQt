import QtQuick 2.9
import Enums 1.0
import "Common"

Item {
    id: container
    width: 1920; height: 950
    property string textScore: "Điểm: " + easyMath.score
    property string textLevel: "Level: " + easyMath.level
    property string highScore: "Điểm cao: " + dataModel.getDataFromRole(Enums.HMI_GAME_EASY_MATH, Enums.ROLE_GAME_HIGHSCORE)

    CardModal {
        id: cardModel
        visible: false
        width: container.width; height: container.height
        widthModal: 450; heightModal: 330
        score: easyMath.score
        highScore: dataModel.getDataFromRole(Enums.HMI_GAME_EASY_MATH, Enums.ROLE_GAME_HIGHSCORE)

        onRequestContinueGame: {
            cardModel.visible = false
            easyMath.requestRestartGame()

        }

        onRequestGoToHomeScreen: {
            myAppMain.setCurrentView(Enums.HMI_VIEW_WELCOME)
        }
    }

    Column {
        x: 350; y: 300
        spacing: 70

        Text {
            id: levelText
            text: textLevel
            font.pixelSize: 42
            font.family: "Helvetica"
        }

        Text {
            id: highScoreText
            text: highScore
            font.pixelSize: 42
            font.family: "Helvetica"
        }
    }



    Item {
        width: 480; height: 800
        anchors.centerIn: parent

        Connections {
            target: easyMath

            onSigNextLevel: {
                textScore = "Điểm: " + easyMath.score
                textLevel = "Level: " + easyMath.level
                progressBar.animationRunning = false
                progressBar.value = easyMath.time
                progressBar.animationRunning = true
            }

            onSigGameOver: {
                highScore = "Điểm cao: " + dataModel.getDataFromRole(Enums.HMI_GAME_EASY_MATH, Enums.ROLE_GAME_HIGHSCORE)
                cardModel.highScore = dataModel.getDataFromRole(Enums.HMI_GAME_EASY_MATH, Enums.ROLE_GAME_HIGHSCORE)
                progressBar.animationRunning = false
                cardModel.visible = true
            }
        }


        Rectangle {
            id: headerRect
            width: parent.width; height: 125
            color: "beige"

            Text {
                id: title
                text: "Easy Maths"
                font.pixelSize: 60
                font.bold: true
                font.family: "Helvetica"
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignTop
                anchors.topMargin: 20
            }
        }

        Rectangle {
            id: scoreBlock
            width: parent.width; height: 80
            color: "aqua"
            y: 125

            Text {
                anchors.centerIn: parent
                text: textScore
                font.pixelSize: 40
                font.family: "Helvetica"
            }
        }

        ProgressBar {
            id: progressBar
            y: 205; z: 1
            width: parent.width; height: 10
            maximum: 10
            value: 10
            minimum: 0
            timeOfProgessBar: 10.2
            animationRunning: false

            onValueChanged: {
                if (value === 10) {
                    easyMath.setTime(easyMath.time)
                } else {
                    easyMath.setTime(easyMath.time - 1)
                }
            }
        }


        Rectangle {
            id: calcRect
            width: parent.width; height: 200
            color: "aquamarine"
            y: 205

            Text {
                id: calcText
                anchors.centerIn: parent
                text: easyMath.calculator
                font.pixelSize: 40
                font.family: "Helvetica"
            }
        }

        Rectangle {
            id: resultRect
            width: parent.width; height: 80
            color: "beige"
            y: 405

            Text {
                id: resultText
                anchors.centerIn: parent
                text: easyMath.result
                font.pixelSize: 40
                font.family: "Helvetica"
            }
        }

        Rectangle {
            id: btnRect
            width: parent.width; height: 200
            color: "bisque"
            y: 485

            Row {
                transformOrigin: Item.Left
                spacing: 20
                anchors.centerIn: parent
                GeneralButton {
                    id: correctBtn
                    width: 100; height: 100
                    color: "#fff"
                    text.text: "Đúng"
                    text.color: "green"
                    text.font.pixelSize: 25
                    text.font.bold: true

                    onButtonClicked: {
                        easyMath.requestAnswearGame(true)
                    }
                }

                GeneralButton {
                    id: incorrectBtn
                    width: 100; height: 100
                    color: "#fff"
                    text.text: "Sai"
                    text.color: "red"
                    text.font.pixelSize: 25
                    text.font.bold: true

                    onButtonClicked: {
                        easyMath.requestAnswearGame(false)
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        progressBar.animationRunning = true
    }
}
