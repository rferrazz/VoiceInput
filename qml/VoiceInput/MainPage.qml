import QtQuick 1.1
import com.nokia.meego 1.0

Page {
    tools: commonTools
    property string filePath: ""
    signal startRecording()
    signal stopRecording()
    signal requestPath()
    signal sendToGoogle(string path)

    function startRec(){
        registrationDialog.open();
        startRecording();
        //TODO: ricordare l'azione da eseguire con il testo risultante
    }

    function getFilePath(path){
        filePath = path;
    }

    function response(text){
        console.log(text);
        var json = eval('('+text+')');
        resultLabel.text = json.hypotheses[0].utterance;
    }

    HeaderBar {
        title: "VoiceInput"
    }

    Column {
        anchors.centerIn: parent
        spacing: 16
        Button{
            text: "Test"
            onClicked: {
                startRec();
            }
        }
        Label {
            id: resultLabel
            text: ""
        }
    }

    RegistrationDialog {
        id: registrationDialog
        onStopPressed: {
            stopRecording();
            requestPath();
            sendToGoogle(filePath);
        }
    }
}
