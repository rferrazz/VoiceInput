#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "utils/audiorecorder.h"
#include "utils/qgspeechapi.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    AudioRecorder recorder;
    QGSpeechApi googleApi(this);

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/VoiceInput/main.qml"));
    QObject *root = (QObject *)viewer.rootObject();
    QObject *page = root->findChild<QObject *>("mainPage");

    QObject::connect(page, SIGNAL(startRecording()), &recorder, SLOT(startRecording()));
    QObject::connect(page, SIGNAL(stopRecording()), &recorder, SLOT(stopRecording()));
    QObject::connect(page, SIGNAL(requestPath()), &recorder, SLOT(requestFilePath()));
    QObject::connect(&recorder, SIGNAL(sendFilePath(QVariant)), page, SLOT(getFilePath(QVariant)));
    QObject::connect(page, SIGNAL(sendToGoogle(QString)), &googleApi, SLOT(sendRequest(QString)));
    QObject::connect(&googleApi, SIGNAL(result(QVariant)), page, SLOT(response(QVariant)));

    viewer.showExpanded();

    return app->exec();
}
