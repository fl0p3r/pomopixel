import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: window
    visible: true
    width: config.windowWidth > 0 ? config.windowWidth : 360
    height: config.windowHeight > 0 ? config.windowHeight : 580
    minimumWidth: 280
    minimumHeight: 440

    // UI scale calculated dynamically from window dimensions for crisp HiDPI / 2.5K / 4K displays
    readonly property real uiScale: Math.max(0.8, Math.min(2.5, Math.min(window.width / 360.0, window.height / 580.0)))

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
        anchors.margins: Math.max(4, Math.round(6 * uiScale))
        color: theme.darkBackground
        border.color: config.customAccent !== "" ? config.customAccent : theme.accent
        border.width: Math.max(1, Math.round(2 * uiScale))

        Item {
            id: container
            anchors.fill: parent
            anchors.margins: Math.max(8, Math.round(12 * uiScale))

            // ==========================================
            // 1. HEADER: Title & Mode Selection Tabs
            // ==========================================
            Column {
                id: headerColumn
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                spacing: Math.max(6, Math.round(10 * uiScale))

                Text {
                    id: mainTitle
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "POMODORO"
                    font.family: "Press Start 2P"
                    font.pixelSize: Math.max(12, Math.round(18 * uiScale))
                    font.bold: true
                    color: theme.magenta ? theme.magenta : theme.accent
                    renderType: Text.NativeRendering
                }

                Row {
                    id: tabsRow
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: Math.max(4, Math.round(8 * uiScale))

                    PixelButton {
                        text: "FOCUS"
                        fontSize: Math.max(6, Math.round(8 * uiScale))
                        implicitWidth: Math.max(64, Math.round(84 * uiScale))
                        implicitHeight: Math.max(22, Math.round(28 * uiScale))
                        isActive: backend.mode === 0
                        activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
                        onClicked: backend.setMode(0)
                    }

                    PixelButton {
                        text: "BREAK"
                        fontSize: Math.max(6, Math.round(8 * uiScale))
                        implicitWidth: Math.max(64, Math.round(84 * uiScale))
                        implicitHeight: Math.max(22, Math.round(28 * uiScale))
                        isActive: backend.mode === 1
                        activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
                        onClicked: backend.setMode(1)
                    }

                    PixelButton {
                        text: "LONG"
                        fontSize: Math.max(6, Math.round(8 * uiScale))
                        implicitWidth: Math.max(64, Math.round(84 * uiScale))
                        implicitHeight: Math.max(22, Math.round(28 * uiScale))
                        isActive: backend.mode === 2
                        activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
                        onClicked: backend.setMode(2)
                    }
                }
            }

            // ==========================================
            // 3. BOTTOM: Control Buttons & Shortcuts
            // ==========================================
            Column {
                id: bottomColumn
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                spacing: Math.max(6, Math.round(8 * uiScale))

                Row {
                    id: bottomButtonsRow
                    anchors.horizontalCenter: parent.horizontalCenter
                    spacing: Math.max(6, Math.round(10 * uiScale))

                    PixelButton {
                        text: backend.isRunning ? "PAUSE" : "START"
                        fontSize: Math.max(7, Math.round(9 * uiScale))
                        implicitWidth: Math.max(72, Math.round(94 * uiScale))
                        implicitHeight: Math.max(26, Math.round(34 * uiScale))
                        isActive: true
                        activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
                        activeTextColor: theme.darkerBackground
                        onClicked: backend.toggle()
                    }

                    PixelButton {
                        text: "RESET"
                        fontSize: Math.max(7, Math.round(9 * uiScale))
                        implicitWidth: Math.max(66, Math.round(84 * uiScale))
                        implicitHeight: Math.max(26, Math.round(34 * uiScale))
                        isActive: false
                        onClicked: backend.reset()
                    }

                    PixelButton {
                        text: "SKIP"
                        fontSize: Math.max(7, Math.round(9 * uiScale))
                        implicitWidth: Math.max(64, Math.round(80 * uiScale))
                        implicitHeight: Math.max(26, Math.round(34 * uiScale))
                        isActive: false
                        onClicked: backend.skip()
                    }
                }

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Space: Play/Pause  R: Reset  S: Skip  1-3: Mode"
                    font.family: "Press Start 2P"
                    font.pixelSize: Math.max(5, Math.round(6 * uiScale))
                    color: theme.muted
                    renderType: Text.NativeRendering
                }
            }

            // ==========================================
            // 2. MAIN RETRO CARD (Responsively fills center)
            // ==========================================
            Rectangle {
                id: card
                anchors.top: headerColumn.bottom
                anchors.topMargin: Math.max(8, Math.round(10 * uiScale))
                anchors.bottom: bottomColumn.top
                anchors.bottomMargin: Math.max(8, Math.round(10 * uiScale))
                anchors.left: parent.left
                anchors.right: parent.right

                color: theme.darkerBackground
                border.color: config.customAccent !== "" ? config.customAccent : theme.accent
                border.width: Math.max(1, Math.round(2 * uiScale))

                Item {
                    id: cardInner
                    anchors.fill: parent
                    anchors.margins: Math.max(6, Math.round(10 * uiScale))

                    // Top Info Group (Mode, Big Timer, Progress, Cycles)
                    Column {
                        id: cardTopInfo
                        anchors.top: parent.top
                        anchors.left: parent.left
                        anchors.right: parent.right
                        spacing: Math.max(4, Math.round(8 * uiScale))

                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: backend.modeName
                            font.family: "Press Start 2P"
                            font.pixelSize: Math.max(8, Math.round(10 * uiScale))
                            color: theme.foreground
                            renderType: Text.NativeRendering
                        }

                        Text {
                            id: timerText
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: backend.formattedTime
                            font.family: "Press Start 2P"
                            font.pixelSize: Math.max(18, Math.round(26 * uiScale))
                            font.bold: true
                            color: theme.brightForeground
                            renderType: Text.NativeRendering
                        }

                        PixelProgressBar {
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: Math.max(160, parent.width - Math.round(24 * uiScale))
                            progress: backend.progress
                            activeColor: config.customAccent !== "" ? config.customAccent : theme.accent
                        }

                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: "TODAY: " + backend.completedCycles
                            font.family: "Press Start 2P"
                            font.pixelSize: Math.max(7, Math.round(9 * uiScale))
                            color: theme.muted
                            renderType: Text.NativeRendering
                        }
                    }

                    // Bottom Info Group (Status text + hint)
                    Column {
                        id: cardBottomInfo
                        anchors.bottom: parent.bottom
                        anchors.left: parent.left
                        anchors.right: parent.right
                        spacing: Math.max(2, Math.round(4 * uiScale))

                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: backend.isMascotResting ? "ZZZ... REST" : (backend.isRunning ? "FOCUSING..." : "READY TO WORK")
                            font.family: "Press Start 2P"
                            font.pixelSize: Math.max(7, Math.round(9 * uiScale))
                            color: backend.isMascotResting ? theme.accent : (backend.isRunning ? theme.green : theme.foreground)
                            renderType: Text.NativeRendering
                        }

                        Text {
                            anchors.horizontalCenter: parent.horizontalCenter
                            text: "[click mascot or 'M' to switch]"
                            font.family: "Press Start 2P"
                            font.pixelSize: Math.max(5, Math.round(6 * uiScale))
                            color: theme.muted
                            renderType: Text.NativeRendering
                        }
                    }

                    // Mascot Container (Fills middle space dynamically)
                    Item {
                        id: mascotContainer
                        anchors.top: cardTopInfo.bottom
                        anchors.topMargin: Math.max(4, Math.round(6 * uiScale))
                        anchors.bottom: cardBottomInfo.top
                        anchors.bottomMargin: Math.max(4, Math.round(6 * uiScale))
                        anchors.left: parent.left
                        anchors.right: parent.right

                        Mascot {
                            id: mascot
                            anchors.centerIn: parent
                            mascotType: config.mascot
                            isResting: backend.isMascotResting
                            pixelScale: Math.max(2, Math.min(10, Math.floor(Math.min(parent.width - 16, parent.height - 8) / 32)))
                        }

                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: {
                                config.nextMascot()
                                backend.playClick()
                            }
                        }
                    }
                }
            }
        }
    }
}
