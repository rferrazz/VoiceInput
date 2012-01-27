var text = "";

function evalutateAndExecute(response){
    var json = eval('('+response+')');
    if(json.status != 0)
        return -1;
    text = json.hypotheses[0].utterance;
    var slices = text.split(" ");
    switch(slices[0]){
        case qsTr("google"):
            Qt.openUrlExternally("http://www.google.com/m/search?client=ms-nokia-meego&q="+recreateString(slices,1));
            break;

        case qsTr("youtube"):
            Qt.openUrlExternally("http://m.youtube.com/#/results?q="+recreateString(slices,1));
            break;

        case qsTr("copy"):
            clipboard.setText(recreateString(slices, 1));
            resultLabel.text = qsTr("Copied to clipboard!");
            break;
    }
    return 0;
}

function recreateString(slices, from){
    var result = ""
    for(var i = from; i < slices.length; i++){
        result+=slices[i];
        result+=" "
    }
    return result;
}
