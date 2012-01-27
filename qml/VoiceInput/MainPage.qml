import QtQuick 1.1
import com.nokia.meego 1.0

import "VoiceActions.js" as VA

Page {
    tools: commonTools
    property string filePath: ""
    signal startRecording()
    signal stopRecording()
    signal requestPath()
    signal sendToGoogle(string path)

    function getFilePath(path){
        filePath = path;
    }

    function response(text){
        console.log(text);
        headerBar.loading = false;
        if(VA.evalutateAndExecute(text) == -1)
            resultLabel.text = qsTr("Voice not recognized");
    }

    function recordingStarted(){
        recButton.text = qsTr("Stop");
        resultLabel.text = "";
    }

    function recordingStopped(){
        recButton.text = qsTr("Start");
        headerBar.loading = true;
    }

    HeaderBar {
        id: headerBar
        title: "VoiceInput"
    }

    Column {
        anchors.centerIn: parent
        spacing: 16
        Button{
            id: recButton
            text: qsTr("Start");
            checkable: true
            onClicked: {
                if(checked)
                    startRecording();
                else{
                    stopRecording();
                    requestPath();
                    sendToGoogle(filePath);
                }
            }
        }
        Label {
            id: resultLabel
            text: ""
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
