#include "audiorecorder.h"
#include <QUrl>

AudioRecorder::AudioRecorder(QObject *parent) :
    QObject(parent)
{
    source = new QAudioCaptureSource(this);
    recorder = new QMediaRecorder(source, this);
    QString folder = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
    audioFile = QDir::toNativeSeparators(folder+"VoiceInputRecord.flac");
    recorder->setOutputLocation(QUrl(audioFile));
}

AudioRecorder::~AudioRecorder(){
    delete recorder;
    delete source;
}

void AudioRecorder::startRecording(){
    if(recorder->state() != QMediaRecorder::StoppedState)
        return;
    source->setAudioInput(source->defaultAudioInput());
    QAudioEncoderSettings encoderSettings;
    encoderSettings.setCodec("audio/FLAC");
    encoderSettings.setBitRate(16000);
    recorder->setEncodingSettings(encoderSettings);
    recorder->record();
}

void AudioRecorder::stopRecording(){
    if(recorder->state() == QMediaRecorder::RecordingState)
        recorder->stop();
}

void AudioRecorder::requestFilePath(){
    emit sendFilePath(QVariant(audioFile));
}
