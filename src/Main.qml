import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: window
    visible: true
    width: config.windowWidth > 0 ? config.windowWidth : 360
    height: config.windowHeight > 0 ? config.windowHeight : 580
    minimumWidth: 320
    maximumWidth: 420
    minimumHeight: 520
    maximumHeight: 680

    title: "Pomopixel"
    flags: Qt.Window | (config.alwaysOnTop ? Qt.WindowStaysOnTopHint : 0)
    color: theme.darkBackground

    // Keyboard Shortcuts
    Item {
        focus: true
        Keys.onSpacePressed: backend.toggle()
        Keys.onPressed: function(event) {
            if (event.key === Qt.Key_R) {
                backend.reset()
                event.accepted = true
            } else if (event.key === Qt.Key_S) {
                backend.skip()
                event.accepted = true
            } else if (event.key === Qt.Key_1) {
                backend.setMode(0)
                event.accepted = true
            } else if (event.key === Qt.Key_2) {
                backend.setMode(1)
                event.accepted = true
            } else if (event.key === Qt.Key_3) {
                backend.setMode(2)
                event.accepted = true
            } else if (event.key === Qt.Key_M) {
                config.nextMascot()
                backend.playClick()
                event.accepted = true
            } else if (event.key === Qt.Key_Q || event.key === Qt.Key_Escape) {
                window.close()
                event.accepted = true
            }
        }
    }

    // Outer Retro Border Frame
    Rectangle {
        id: rootFrame
        anchors.fill: parent
        anchors.margins: 6
        color: theme.darkBackground
        border.color: config.customAccent !== "" ? config.customAccent : theme.accent
        border.width: 2

        Column {
            anchors.fill: parent
            anchors.margins: 14
            spacing: 12

            // ==========================================
            // 1. HEADER: Title
            // ==========================================
            Text {
                id: mainTitle
                anchors.horizontalCenter: parent.horizontalCenter
                text: "POMODORO"
                font.family: "Press Start 2P"
                font.pixelSize: 18
                font.bold: true
                color: theme.magenta ? theme.magenta : theme.accent
                renderType: Text.NativeRendering
            }

            // Mode Selection Tabs (FOCUS, BREAK, LONG)
            Row {
                id: tabsRow
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 8

                PixelButton {
                    text: "FOCUS"
                    fontSize: 8
                    implicitWidth: 84
                    implicitHeight: 28
                    isActive: backend.mode === 0
                    activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
                    onClicked: backend.setMode(0)
                }

                PixelButton {
                    text: "BREAK"
                    fontSize: 8
                    implicitWidth: 84
                    implicitHeight: 28
                    isActive: backend.mode === 1
                    activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
                    onClicked: backend.setMode(1)
                }

                PixelButton {
                    text: "LONG"
                    fontSize: 8
                    implicitWidth: 84
                    implicitHeight: 28
                    isActive: backend.mode === 2
                    activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
                    onClicked: backend.setMode(2)
                }
            }

            // ==========================================
            // 2. MAIN RETRO CARD (Matching Reference)
            // ==========================================
            Rectangle {
                id: card
                width: parent.width
                height: 380
                color: theme.darkerBackground
                border.color: config.customAccent !== "" ? config.customAccent : theme.accent
                border.width: 2

                Column {
                    anchors.fill: parent
                    anchors.margins: 12
                    spacing: 10

                    // Current mode title
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: backend.modeName
                        font.family: "Press Start 2P"
                        font.pixelSize: 10
                        color: theme.foreground
                        renderType: Text.NativeRendering
                    }

                    // Huge Pixel Timer Display (e.g. 25:00)
                    Text {
                        id: timerText
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: backend.formattedTime
                        font.family: "Press Start 2P"
                        font.pixelSize: 26
                        font.bold: true
                        color: theme.brightForeground
                        renderType: Text.NativeRendering
                    }

                    // Segmented Pixel Progress Bar
                    PixelProgressBar {
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: parent.width - 24
                        progress: backend.progress
                        activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
                    }

                    // Completed Cycles Today
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "TODAY: " + backend.completedCycles
                        font.family: "Press Start 2P"
                        font.pixelSize: 9
                        color: theme.muted
                        renderType: Text.NativeRendering
                    }

                    // Mascot Container
                    Item {
                        width: parent.width
                        height: 150

                        Mascot {
                            id: mascot
                            anchors.centerIn: parent
                            mascotType: config.mascot
                            isResting: backend.isMascotResting
                            pixelScale: 5
                        }

                        // Mascot click cycles to next mascot
                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: {
                                config.nextMascot()
                                backend.playClick()
                            }
                        }
                    }

                    // Mascot Status Text
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: backend.isMascotResting ? "ZZZ... REST" : (backend.isRunning ? "FOCUSING..." : "READY TO WORK")
                        font.family: "Press Start 2P"
                        font.pixelSize: 9
                        color: backend.isMascotResting ? theme.accent : (backend.isRunning ? theme.green : theme.foreground)
                        renderType: Text.NativeRendering
                    }

                    // Mascot switch hint
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "[click mascot or 'M' to switch]"
                        font.family: "Press Start 2P"
                        font.pixelSize: 6
                        color: theme.muted
                        renderType: Text.NativeRendering
                    }
                }
            }

            // ==========================================
            // 3. BOTTOM CONTROL BUTTONS
            // ==========================================
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 10

                PixelButton {
                    text: backend.isRunning ? "PAUSE" : "START"
                    fontSize: 9
                    implicitWidth: 92
                    implicitHeight: 34
                    isActive: true
                    activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
                    activeTextColor: theme.darkerBackground
                    onClicked: backend.toggle()
                }

                PixelButton {
                    text: "RESET"
                    fontSize: 9
                    implicitWidth: 84
                    implicitHeight: 34
                    isActive: false
                    onClicked: backend.reset()
                }

                PixelButton {
                    text: "SKIP"
                    fontSize: 9
                    implicitWidth: 80
                    implicitHeight: 34
                    isActive: false
                    onClicked: backend.skip()
                }
            }

            // Keyboard hints footer
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Space: Play/Pause  R: Reset  S: Skip  1-3: Mode"
                font.family: "Press Start 2P"
                font.pixelSize: 5
                color: theme.muted
                renderType: Text.NativeRendering
            }
        }
    }
}
