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
    ~AudioRecorder();
    
signals:
    void sendFilePath(QVariant path);
    
public slots:
    void startRecording();
    void stopRecording();
    void requestFilePath();

private:
    QAudioCaptureSource *source;
    QMediaRecorder *recorder;
    QString audioFile;
};

#endif // AUDIORECORDER_H
