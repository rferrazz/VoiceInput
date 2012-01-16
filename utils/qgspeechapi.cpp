#include "qgspeechapi.h"

QGSpeechApi::QGSpeechApi(QObject *parent) :
    QObject(parent)
{
    http = new QHttp("https://www.google.com");
}

void QGSpeechApi::sendRequest(QString file){//segfault
    QFileInfo finfo(file);
    QHttpRequestHeader header("POST", "/speech-api/v1/recognize?xjerr=1&client=chromium&lang=it-IT");
    header.setValue("Accept","*/*");
    header.setValue("Host", "www.google.com");
    header.setValue("Content-Type", "audio/x-flac; rate=16000");
    QString size = QString::number(finfo.size());
    header.setValue("Content-Length", size);
    QFile ffile(file);
    http->request(header, &ffile);
    QObject::connect(http, SIGNAL(requestFinished(int,bool)), this, SLOT(readResponse(int, bool)));
}

void QGSpeechApi::readResponse(int id, bool error){
    if(error)
        return;
    QByteArray response = http->readAll();
    emit result(response);
}
