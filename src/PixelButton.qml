import QtQuick 2.15

Item {
    id: root

    property string text: ""
    property bool isActive: false
    property color activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
    property color activeTextColor: theme.darkerBackground
    property color inactiveColor: theme.darkBackground
    property color inactiveTextColor: theme.foreground
    property color borderColor: isActive ? activeColor : theme.muted
    property int fontSize: 10

    signal clicked()

    implicitWidth: btnText.implicitWidth + 24
    implicitHeight: 34

    Rectangle {
        id: bg
        anchors.fill: parent
        anchors.topMargin: mouseArea.pressed ? 2 : 0
        anchors.leftMargin: mouseArea.pressed ? 1 : 0
        color: root.isActive ? root.activeColor : (mouseArea.containsMouse ? theme.lighterBackground : root.inactiveColor)
        border.color: root.borderColor
        border.width: 2
        radius: 0 // Sharp retro pixel edges

        Text {
            id: btnText
            anchors.centerIn: parent
            text: root.text
            font.family: "Press Start 2P"
            font.pixelSize: root.fontSize
            font.bold: true
            color: root.isActive ? root.activeTextColor : root.inactiveTextColor
            renderType: Text.NativeRendering
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onClicked: {
            root.clicked()
            backend.playClick()
        }
    }
}
