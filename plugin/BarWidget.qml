import QtQuick
import Quickshell
import Quickshell.Io
import qs.Ui

BarWidget {
    id: root
    moduleName: "pomopixel"

    implicitWidth: button.implicitWidth
    implicitHeight: button.implicitHeight

    Process {
        id: launcher
        command: ["pomopixel"]
    }

    WidgetButton {
        id: button
        anchors.fill: parent
        bar: root.bar
        text: "🍅"
        tooltipText: "Launch Pomopixel"
        onPressed: function(buttonCode) {
            launcher.running = true
        }
    }
}
