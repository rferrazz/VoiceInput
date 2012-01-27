import QtQuick 1.1
import com.nokia.meego 1.0

import clipadapter 1.0
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
        VA.evalutateAndExecute(text);
    }

    function recordingStarted(){
        recButton.text = "Stop"
    }

    function recordingStopped(){
        recButton.text = "Start"
    }

    QClipboard {
        id: clipboard
    }

    HeaderBar {
        title: "VoiceInput"
    }

    Column {
        anchors.centerIn: parent
        spacing: 16
        Button{
            id: recButton
            text: "Start"
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
        }
    }
}
