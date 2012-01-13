#include "audiorecorder.h"

AudioRecorder::AudioRecorder(QObject *parent) :
    QObject(parent)
{
    source = new QAudioCaptureSource(this);
    recorder = new QMediaRecorder(source, this);
    QString folder = QDesktopServices::storageLocation(QDesktopServices.CacheLocation);
    recorder->setOutputLocation(QUrl(QDir::toNativeSeparators(folder+"\VoiceInputRecord")));
}

AudioRecorder::~AudioRecorder(){
    delete recorder;
    delete source;
}

bool AudioRecorder::startRecording(){
    if(recorder->state() != QMediaRecorder::StoppedState)
        return false;
    source->setAudioInput(source->defaultAudioInput());
    QAudioEncoderSettings encoderSettings;
    encoderSettings.setCodec("audio/flac");
    recorder->setEncodingSettings(encoderSettings);
    recorder->record();
    return true;
}

void AudioRecorder::stopRecording(){
    if(recorder->State() == QMediaRecorder::RecordingState)
        recorder->stop();
}
