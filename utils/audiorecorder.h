#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QObject>
#include <QMediaRecorder>
#include <QAudioCaptureSource>
#include <QDesktopServices>
#include <QDir>

class AudioRecorder : public QObject
{
    Q_OBJECT
public:
    explicit AudioRecorder(QObject *parent = 0);
    
signals:
    
public slots:
    bool startRecording();
    void stopRecording();

private:
    QAudioCaptureSource *source;
    QMediaRecorder *recorder;
};

#endif // AUDIORECORDER_H
