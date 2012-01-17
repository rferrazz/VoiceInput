#include "qgspeechapi.h"
#include <QDebug>

QGSpeechApi::QGSpeechApi(QObject *parent) :
    QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    request = new QNetworkRequest(QUrl("https://www.google.com/speech-api/v1/recognize?xjerr=1&client=chromium&lang=it-IT"));
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readResponse(QNetworkReply*)));
}

void QGSpeechApi::sendRequest(QString file){
    QFileInfo finfo(file);
    QByteArray size = QByteArray::number(finfo.size());
    QFile *ffile = new QFile(file);
    ffile->open(QFile::ReadOnly);
    request->setRawHeader("Accept","*/*");
    request->setRawHeader("Host", "www.google.com");
    request->setRawHeader("Content-Type", "audio/x-flac; rate=16000");
    request->setRawHeader("Content-Length", size);
    manager->post(*request, ffile);
}

void QGSpeechApi::readResponse(QNetworkReply *reply){
    QByteArray response = reply->readAll();
    emit result(response);
}
