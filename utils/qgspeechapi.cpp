#include "qgspeechapi.h"
#include <QDebug>

QGSpeechApi::QGSpeechApi(QObject *parent) :
    QObject(parent)
{
    QUrl *requestUrl = new QUrl("http://www.google.com/speech-api/v1/recognize");
    requestUrl->addEncodedQueryItem("xjerr", "1");
    requestUrl->addEncodedQueryItem("client", "chromium");
    requestUrl->addEncodedQueryItem("pfilter", "2");
    requestUrl->addEncodedQueryItem("max_results", "10");
    requestUrl->addEncodedQueryItem("continue", "true");
    requestUrl->addEncodedQueryItem("lang", QLocale::system().name().toAscii());
    manager = new QNetworkAccessManager(this);
    request = new QNetworkRequest(*requestUrl);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(readResponse(QNetworkReply*)));
}

void QGSpeechApi::sendRequest(QString file){
    QFileInfo finfo(file);
    QByteArray size = QByteArray::number(finfo.size());
    QFile *ffile = new QFile(file);
    ffile->open(QFile::ReadOnly);
    request->setRawHeader("Accept","*/*");
    request->setRawHeader("Connection", "Keep-Alive");
    request->setRawHeader("Host", "www.google.com");
    request->setRawHeader("Content-Type", "audio/x-flac; rate=16000");
    request->setRawHeader("Content-Length", size);
    manager->post(*request, ffile);
}

void QGSpeechApi::readResponse(QNetworkReply *reply){
    QByteArray response = reply->readAll();
    emit result(response);
}
