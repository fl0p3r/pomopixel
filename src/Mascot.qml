import QtQuick 2.15
import "MascotSprites.js" as SpriteData

Item {
    id: root

    property string mascotType: "claude_critter" // "claude_critter", "blob", "tux", "ghost"
    property bool isResting: false
    property color primaryColor: theme.magenta ? theme.magenta : "#FF7EB6"
    property color secondaryColor: theme.accent ? theme.accent : "#FF79C6"
    property color darkEyeColor: theme.darkerBackground ? theme.darkerBackground : "#14141E"
    property int pixelScale: 4
    property int animFrame: 0

    implicitWidth: 32 * pixelScale
    implicitHeight: 32 * pixelScale

    Timer {
        id: animTimer
        interval: root.isResting ? 450 : 250
        running: true
        repeat: true
        onTriggered: {
            root.animFrame = (root.animFrame + 1) % 4
            canvas.requestPaint()
        }
    }

    onMascotTypeChanged: {
        root.animFrame = 0
        canvas.requestPaint()
    }
    onIsRestingChanged: {
        root.animFrame = 0
        canvas.requestPaint()
    }
    onPrimaryColorChanged: canvas.requestPaint()
    onSecondaryColorChanged: canvas.requestPaint()

    Canvas {
        id: canvas
        anchors.centerIn: parent
        width: 32 * root.pixelScale
        height: 32 * root.pixelScale

        onPaint: {
            var ctx = getContext("2d")
            ctx.imageSmoothingEnabled = false
            ctx.clearRect(0, 0, width, height)

            var m = root.mascotType
            var rest = root.isResting
            var f = root.animFrame % 4

            var key = m + "_" + (rest ? "rest" : "focus") + "_" + f
            var sprite = SpriteData.Sprites[key]
            if (!sprite) {
                key = m + "_" + (rest ? "rest" : "focus") + "_0"
                sprite = SpriteData.Sprites[key]
            }
            if (!sprite) return

            var ps = root.pixelScale

            // Dynamic color palette adapting live to theme
            var pal = {
                '.': null,
                'P': root.primaryColor,
                'D': Qt.darker(root.primaryColor, 1.25),
                'L': Qt.lighter(root.primaryColor, 1.3),
                'R': theme.red ? theme.red : "#FF4070",
                'E': theme.accent ? theme.accent : "#E0D8FF",
                'W': "#F8F8FF",
                'K': root.darkEyeColor,
                'B': "#20202C",
                'Y': theme.yellow ? theme.yellow : "#F5A623",
                'O': Qt.darker(theme.yellow ? theme.yellow : "#F5A623", 1.25),
                'C': theme.cyan ? theme.cyan : "#89B4FA",
                'T': "#4A4A5E",
                'Z': theme.accent ? theme.accent : "#89B4FA",
                'A': theme.orange ? theme.orange : "#D97757",
                'G': theme.blue ? theme.blue : "#8BE9FD"
            }

            for (var y = 0; y < 32; y++) {
                var row = sprite[y]
                for (var x = 0; x < 32; x++) {
                    var ch = row[x]
                    if (ch !== '.') {
                        var col = pal[ch]
                        if (col) {
                            ctx.fillStyle = col
                            ctx.fillRect(x * ps, y * ps, ps, ps)
                        }
                    }
                }
            }
        }
    }
}
