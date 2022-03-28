import QtQuick 2.9
import QtQuick.Window 2.2
import Enums 1.0

Item {
    id: container
    property int currScreen: myAppMain.currentView

    Rectangle {
        anchors.fill: parent
        color: "#eee"
    }

    function loadScreen(currScreen) {
        switch(currScreen) {
        case Enums.HMI_VIEW_WELCOME:
            mainLoader.source = "WelcomeScreen.qml"
            break;
        case Enums.HMI_VIEW_EASYMATH:
            mainLoader.source = "EasyMaths.qml"
        }

    }

    onCurrScreenChanged: {
        loadScreen(currScreen)
    }

    Loader {
        id: mainLoader
        source: "qrc:/WelcomeScreen.qml"
    }
}
