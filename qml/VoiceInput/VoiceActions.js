var text = "";

function evalutateAndExecute(response){
    var json = eval('('+response+')');
    text = json.hypotheses[0].utterance;
    var slices = text.split(" ");
    switch(slices[0]){
        case "google":
            Qt.openUrlExternally("http://www.google.com/m/search?client=ms-nokia-meego&q="+recreateString(slices,1));
            break;

        case "youtube":
            Qt.openUrlExternally("http://m.youtube.com/#/results?q="+recreateString(slices,1));
            break;

        case "copia":
            clipboard.setText(recreateString(slices, 1));
            console.log("Copiato!!!");
            break;
    }
}

function recreateString(slices, from){
    var result = ""
    for(var i = from; i < slices.length; i++){
        result+=slices[i];
        result+=" "
    }
    return result;
}
