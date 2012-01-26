#include "audiorecorder.h"
#include <QUrl>

AudioRecorder::AudioRecorder(QObject *parent) :
    QObject(parent)
{
    source = new QAudioCaptureSource(this);
    recorder = new QMediaRecorder(source, this);
    QString folder = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
    audioFile = folder+"VoiceInputRecord.flac";
    recorder->setOutputLocation(QUrl(audioFile));
    QObject::connect(recorder, SIGNAL(stateChanged(QMediaRecorder::State)), this, SLOT(getRecordingState(QMediaRecorder::State)));
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
    encoderSettings.setChannelCount(1);
    encoderSettings.setSampleRate(44000);
    // for FLAC encoding:
    encoderSettings.setCodec("audio/FLAC");
    encoderSettings.setEncodingMode(QtMultimediaKit::ConstantQualityEncoding);
    encoderSettings.setQuality(QtMultimediaKit::EncodingQuality(QtMultimediaKit::VeryLowQuality));
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

void AudioRecorder::getRecordingState(QMediaRecorder::State state){
    if(state == QMediaRecorder::StoppedState){
        emit stopped();
        return;
    }
    emit started();
}
