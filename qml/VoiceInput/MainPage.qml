import QtQuick 1.1
import com.nokia.meego 1.0

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
        var json = eval('('+text+')');
        resultLabel.text = json.hypotheses[0].utterance;
        Qt.openUrlExternally("http://www.google.com/m/search?client=ms-nokia-meego&q="+json.hypotheses[0].utterance);
    }

    function recordingStarted(){
        recButton.text = "Stop"
    }

    function recordingStopped(){
        recButton.text = "Start"
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
