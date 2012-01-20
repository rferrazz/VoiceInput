#ifndef QGSPEECHAPI_H
#define QGSPEECHAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFileInfo>
#include <QBuffer>
#include <QVariant>

class QGSpeechApi : public QObject
{
    Q_OBJECT
public:
    explicit QGSpeechApi(QObject *parent = 0);
    
signals:
    void result(QVariant text);
    
public slots:
    void sendRequest(QString file);
    void readResponse(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QUrl *requestUrl;
    
};

#endif // QGSPEECHAPI_H
