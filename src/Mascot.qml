import QtQuick 2.15

Item {
    id: root

    property string mascotType: "claude_critter" // "claude_critter", "blob", "tux", "ghost"
    property bool isResting: false
    property color primaryColor: theme.magenta
    property color secondaryColor: theme.accent
    property color darkEyeColor: theme.darkerBackground
    property color lightEyeColor: theme.brightForeground
    property int pixelScale: 4
    property int animFrame: 0

    implicitWidth: 16 * pixelScale * 2.5
    implicitHeight: 16 * pixelScale * 2.5

    // Animation timer for idle / walk / breathing
    Timer {
        id: animTimer
        interval: root.isResting ? 600 : 350
        running: true
        repeat: true
        onTriggered: {
            root.animFrame = (root.animFrame + 1) % 4
            canvas.requestPaint()
        }
    }

    onMascotTypeChanged: canvas.requestPaint()
    onIsRestingChanged: {
        root.animFrame = 0
        canvas.requestPaint()
    }
    onPrimaryColorChanged: canvas.requestPaint()
    onSecondaryColorChanged: canvas.requestPaint()

    Canvas {
        id: canvas
        anchors.centerIn: parent
        width: 24 * root.pixelScale
        height: 24 * root.pixelScale

        onPaint: {
            var ctx = getContext("2d")
            ctx.imageSmoothingEnabled = false
            ctx.clearRect(0, 0, width, height)

            var ps = root.pixelScale
            var f = root.animFrame
            var rest = root.isResting

            function drawPixel(x, y, color) {
                ctx.fillStyle = color
                ctx.fillRect(x * ps, y * ps, ps, ps)
            }

            function drawRect(x, y, w, h, color) {
                ctx.fillStyle = color
                ctx.fillRect(x * ps, y * ps, w * ps, h * ps)
            }

            // Offset to center 16-20 grid in 24 canvas
            var ox = 4
            var oy = 4 + (rest ? 1 : (f % 2 === 0 ? 0 : -1))

            // ==========================================
            // 1. CLAUDE CRITTER (Terracotta Alien/Critter)
            // ==========================================
            if (root.mascotType === "claude_critter") {
                var cColor = theme.orange ? theme.orange : "#D97757"
                var eyeCol = root.darkEyeColor

                // Body head
                drawRect(ox + 2, oy + 0, 11, 2, cColor)
                drawRect(ox + 2, oy + 2, 11, 2, cColor)

                // Arms / side ears
                drawRect(ox + 0, oy + 4, 15, 3, cColor)
                drawRect(ox + 2, oy + 7, 11, 1, cColor)

                if (!rest) {
                    // Focus: Eyes open (two vertical dark slits)
                    drawRect(ox + 4, oy + 2, 1, 2, eyeCol)
                    drawRect(ox + 10, oy + 2, 1, 2, eyeCol)

                    // 4 Feet walking animation
                    if (f % 2 === 0) {
                        drawRect(ox + 3, oy + 8, 1, 2, cColor)
                        drawRect(ox + 5, oy + 8, 1, 2, cColor)
                        drawRect(ox + 9, oy + 8, 1, 2, cColor)
                        drawRect(ox + 11, oy + 8, 1, 2, cColor)
                    } else {
                        drawRect(ox + 3, oy + 8, 1, 1, cColor)
                        drawRect(ox + 5, oy + 8, 1, 2, cColor)
                        drawRect(ox + 9, oy + 8, 1, 1, cColor)
                        drawRect(ox + 11, oy + 8, 1, 2, cColor)
                    }
                } else {
                    // Rest: Eyes closed (horizontal slits --)
                    drawRect(ox + 4, oy + 3, 2, 1, eyeCol)
                    drawRect(ox + 9, oy + 3, 2, 1, eyeCol)

                    // Sitting feet
                    drawRect(ox + 3, oy + 8, 2, 1, cColor)
                    drawRect(ox + 10, oy + 8, 2, 1, cColor)
                }
            }

            // ==========================================
            // 2. DUMPLING BLOB (Pink Cute Tamagotchi)
            // ==========================================
            else if (root.mascotType === "blob") {
                var bColor = theme.magenta ? theme.magenta : "#FF8DA1"
                var blush = theme.red ? theme.red : "#FF5588"

                // Ears/horns
                drawRect(ox + 4, oy + 0, 2, 1, bColor)
                drawRect(ox + 8, oy + 0, 2, 1, bColor)

                // Head/Body
                drawRect(ox + 3, oy + 1, 8, 1, bColor)
                drawRect(ox + 2, oy + 2, 10, 6, bColor)
                drawRect(ox + 3, oy + 8, 8, 1, bColor)

                if (!rest) {
                    // Round eyes
                    drawRect(ox + 4, oy + 4, 1, 2, root.darkEyeColor)
                    drawRect(ox + 9, oy + 4, 1, 2, root.darkEyeColor)
                    // Blush
                    drawRect(ox + 2, oy + 5, 1, 1, blush)
                    drawRect(ox + 11, oy + 5, 1, 1, blush)
                    // Tiny smile
                    drawRect(ox + 6, oy + 6, 2, 1, root.darkEyeColor)
                } else {
                    // Closed sleeping eyes
                    drawRect(ox + 3, oy + 4, 2, 1, root.darkEyeColor)
                    drawRect(ox + 9, oy + 4, 2, 1, root.darkEyeColor)
                    // Sleep blush
                    drawRect(ox + 2, oy + 5, 2, 1, blush)
                    drawRect(ox + 10, oy + 5, 2, 1, blush)
                }
            }

            // ==========================================
            // 3. LINUX TUX (Pixel Penguin)
            // ==========================================
            else if (root.mascotType === "tux") {
                var black = "#222228"
                var white = "#F0F0F5"
                var yellow = theme.yellow ? theme.yellow : "#F1FA8C"

                // Head
                drawRect(ox + 4, oy + 0, 6, 1, black)
                drawRect(ox + 3, oy + 1, 8, 3, black)
                // Belly
                drawRect(ox + 3, oy + 4, 8, 5, black)
                drawRect(ox + 5, oy + 3, 4, 5, white)

                // Beak
                drawRect(ox + 6, oy + 3, 2, 1, yellow)

                // Eyes
                if (!rest) {
                    drawRect(ox + 5, oy + 2, 1, 1, black)
                    drawRect(ox + 8, oy + 2, 1, 1, black)
                } else {
                    drawRect(ox + 5, oy + 2, 2, 1, black)
                    drawRect(ox + 7, oy + 2, 2, 1, black)
                }

                // Flippers / Feet
                drawRect(ox + 4, oy + 9, 2, 1, yellow)
                drawRect(ox + 8, oy + 9, 2, 1, yellow)

                if (!rest) {
                    // Typing on a tiny pixel laptop!
                    var lapCol = theme.accent
                    drawRect(ox + 5, oy + 7, 4, 1, lapCol)
                    drawRect(ox + 6, oy + 6, 2, 1, lapCol)
                }
            }

            // ==========================================
            // 4. PACMAN GHOST
            // ==========================================
            else if (root.mascotType === "ghost") {
                var gColor = rest ? (theme.blue ? theme.blue : "#8BE9FD") : (theme.red ? theme.red : "#FF5555")

                // Dome head
                drawRect(ox + 4, oy + 0, 6, 1, gColor)
                drawRect(ox + 2, oy + 1, 10, 1, gColor)
                drawRect(ox + 1, oy + 2, 12, 6, gColor)

                // Wavy bottom skirts
                if (f % 2 === 0) {
                    drawRect(ox + 1, oy + 8, 2, 2, gColor)
                    drawRect(ox + 5, oy + 8, 4, 2, gColor)
                    drawRect(ox + 11, oy + 8, 2, 2, gColor)
                } else {
                    drawRect(ox + 2, oy + 8, 3, 2, gColor)
                    drawRect(ox + 7, oy + 8, 2, 2, gColor)
                    drawRect(ox + 11, oy + 8, 1, 2, gColor)
                }

                // Eyes
                if (!rest) {
                    // Big white eyes
                    drawRect(ox + 3, oy + 2, 3, 4, "#FFFFFF")
                    drawRect(ox + 8, oy + 2, 3, 4, "#FFFFFF")
                    // Blue pupils looking left/right
                    var pupX = (f % 4 < 2) ? 0 : 1
                    drawRect(ox + 3 + pupX, oy + 3, 2, 2, "#1E1E2E")
                    drawRect(ox + 8 + pupX, oy + 3, 2, 2, "#1E1E2E")
                } else {
                    // Vulnerable wavy mouth
                    drawRect(ox + 3, oy + 3, 2, 1, "#F1FA8C")
                    drawRect(ox + 9, oy + 3, 2, 1, "#F1FA8C")
                    drawRect(ox + 4, oy + 5, 1, 1, "#FFFFFF")
                    drawRect(ox + 6, oy + 5, 2, 1, "#FFFFFF")
                    drawRect(ox + 9, oy + 5, 1, 1, "#FFFFFF")
                }
            }

            // ==========================================
            // Floating "Z z z" animation during rest
            // ==========================================
            if (rest) {
                var zCol = theme.accent
                var zOffset = (f * 2) % 4
                // Small z
                drawRect(ox + 14, oy - 1 - zOffset, 2, 1, zCol)
                drawRect(ox + 15, oy - 0 - zOffset, 1, 1, zCol)
                drawRect(ox + 14, oy + 1 - zOffset, 2, 1, zCol)

                // Big Z
                drawRect(ox + 16, oy - 4 - zOffset, 3, 1, zCol)
                drawRect(ox + 17, oy - 3 - zOffset, 1, 1, zCol)
                drawRect(ox + 16, oy - 2 - zOffset, 3, 1, zCol)
            }
        }
    }
}
