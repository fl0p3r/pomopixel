import QtQuick 2.15

Item {
    id: root

    property real progress: 0.0 // 0.0 to 1.0
    property int blockCount: 22
    property color activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
    property color inactiveColor: theme.darkBackground
    property color borderColor: theme.muted

    implicitWidth: 280
    implicitHeight: 18

    Rectangle {
        anchors.fill: parent
        color: "transparent"
        border.color: root.borderColor
        border.width: 1

        Row {
            anchors.fill: parent
            anchors.margins: 2
            spacing: 2

            Repeater {
                model: root.blockCount
                Rectangle {
                    width: Math.max(2, (parent.width - (root.blockCount - 1) * 2) / root.blockCount)
                    height: parent.height
                    color: (index / root.blockCount) < root.progress ? root.activeColor : root.inactiveColor
                }
            }
        }
    }
}
