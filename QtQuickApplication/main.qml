import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls
import QtQuick.Layouts
import Qt.labs.platform

Window {
    visible: true
    width: 640
    height: 360
    title: "QtQuickApplication"
   
    GridLayout{
        

        anchors.fill: parent
        rows: 1
        columns: 2

        Item {
            id: container

            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                id: background
                anchors.fill: parent
                color: "#1c2329"
            }

            Rectangle {
                id: fileContainer
                
                property alias fileDialog: fileDialog
                property alias filePathText: labelTest.text
                
                
                function changePath() {
                    fileContainer.filePathText = fileDialog.folder
                }

                width: 100
                height: 100
                color: "#00f7ff"

                Label {
                    id: labelTest
                    text: "No File Selected"
                }

                FileDialog {
                    id: fileDialog
                    onAccepted: {
                        fileContainer.changePath();
                    }
                    Component.onCompleted: visible = true;
                }

            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle {
                
                anchors.fill: parent
                color: "#1c2329"

                Button {
                    anchors.centerIn: parent
                    text: "Click me"
                    onClicked: {
                        text = helloText
                    }
                }

                
            }
            
        }


        
    }
}
