// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.nokia.meego 1.0

Dialog {
    id: registrationDialog
    title: Label {
        text: "Speak now"
    }
    content: Column {
        Button {
            text: "Stop"
            onClicked: { registrationDialog.close() }
        }
    }
}
