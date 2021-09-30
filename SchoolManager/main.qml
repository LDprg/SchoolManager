import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item{
        anchors.fill: parent
        anchors.margins: 10

        TabBar{
            id:tabBar
            width: parent.width

            TabButton{
                text: "Home"
            }

            TabButton{
                text: "Stundenplan"
            }

            TabButton{
                text: "Aufgaben"
            }

            TabButton{
                text: "Einstellungen"
                onClicked: msgDiag.open()
            }
        }

        StackLayout {
            id: stackLayout
            anchors.margins: 5
            anchors.top: tabBar.bottom
            currentIndex:  tabBar.currentIndex

            Item{
                id: home

                Text {
                    id: lbAktuelleStunde
                    y: 10
                    text: qsTr("Aktuelle Stunde: ")
                }

                ComboBox {
                    id: cbAktuelleStunde
                    anchors.top: lbAktuelleStunde.top
                    anchors.left: lbAktuelleStunde.right
                    model: [ "FSST", "GGP", "HWE", "PBE", "WIR", "MTRS", "BESP", "AM", "NW", "DIC", "LA", "D", "E", "KSN", "OTHER" ]
                }

                Text {
                    id: lbDokument
                    anchors.margins: 20
                    anchors.top: lbAktuelleStunde.bottom
                    text: qsTr("Dokumenttyp: ")
                }

                ComboBox {
                    id: cbDokument
                    objectName: "cbDokument"
                    anchors.top: lbDokument.top
                    anchors.left: lbDokument.right

                    signal create(type: string);
                }

                Button{
                    id: btDokument
                    anchors.top: cbDokument.top
                    anchors.left: cbDokument.right
                    text: "Create Document"
                    onClicked: cbDokument.create(cbDokument.currentText)
                }
            }

            Item{
            }

            Item{
            }

            Item{
            }
        }
    }
}
