#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "utils/httpuploader.h"
#include "utils/audiorecorder.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    AudioRecorder recorder;

    qmlRegisterUncreatableType<HttpPostField>("HttpUp", 1, 0, "HttpPostField", "Can't touch this");
    qmlRegisterType<HttpPostFieldValue>("HttpUp", 1, 0, "HttpPostFieldValue");
    qmlRegisterType<HttpPostFieldFile>("HttpUp", 1, 0, "HttpPostFieldFile");
    qmlRegisterType<HttpUploader>("HttpUp", 1, 0, "HttpUploader");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/VoiceInput/main.qml"));
    QObject *root = dynamic_cast<QObject *>(viewer.rootObject());
    QObject *page = root->findChild<QObject *>("mainPage");

    QObject::connect(page, SIGNAL(startRecording()), &recorder, SLOT(startRecording()));
    QObject::connect(page, SIGNAL(stopRecording()), &recorder, SLOT(stopRecording()));
    QObject::connect(page, SIGNAL(requestPath()), &recorder, SLOT(requestFilePath()));
    QObject::connect(&recorder, SIGNAL(sendFilePath(QVariant)), page, SLOT(getFilePath(QVariant)));

    viewer.showExpanded();

    return app->exec();
}
