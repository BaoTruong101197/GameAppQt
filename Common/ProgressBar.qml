import QtQuick 2.0

Rectangle { // background
    id: root

// public
    property double maximum: 10
    property double value:   0
    property double minimum: 0
    property bool   animationRunning: false
    property alias  foreground: foreground
    property double    timeOfProgessBar: 10
    color: "#fff"

// private
    width: 800;  height: 10 // default size

    Rectangle { // foreground
        id: foreground
        visible: value > minimum
        x: 0;  y: 0
        width: Math.max(height,
               Math.min((value - minimum) / (maximum - minimum) * (parent.width - 0.2 * root.height),
                        parent.width - 0.2 * root.height)) // clip
        height: root.height
        color: "red"
    }

    PropertyAnimation {
        id: animation
        property: "width"
        target: foreground
        to: value - 1
        duration: timeOfProgessBar * 1000
        running: animationRunning

        onStarted: {
            timer.restart()
        }

        onStopped: {
            timer.stop()
        }
    }

    Timer {
        id: timer
        repeat: true
        running: false
        interval: 1000
        onTriggered: {
            value--;
        }
    }

}
