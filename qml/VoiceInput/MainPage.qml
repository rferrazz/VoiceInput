import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    tools: commonTools

    HeaderBar {
        title: "VoiceInput"
    }

    Column {
        anchors.centerIn: parent
        spacing: 16
        Button{
            text: "Web search"
            onClicked: {
                registrationDialog.open()
            }
        }
        Button {
            text: "Send SMS"
            onClicked: {
                registrationDialog.open()
            }
        }
    }

    RegistrationDialog {
        id: registrationDialog
    }
}
