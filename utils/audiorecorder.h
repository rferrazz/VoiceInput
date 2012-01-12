#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <QObject>

class AudioRecorder : public QObject
{
    Q_OBJECT
public:
    explicit AudioRecorder(QObject *parent = 0);
    
signals:
    
public slots:
    void startRecording();
    void stopRecording();
    
};

#endif // AUDIORECORDER_H
