#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include "utils/httpuploader.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    qmlRegisterUncreatableType<HttpPostField>("HttpUp", 1, 0, "HttpPostField", "Can't touch this");
    qmlRegisterType<HttpPostFieldValue>("HttpUp", 1, 0, "HttpPostFieldValue");
    qmlRegisterType<HttpPostFieldFile>("HttpUp", 1, 0, "HttpPostFieldFile");
    qmlRegisterType<HttpUploader>("HttpUp", 1, 0, "HttpUploader");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/VoiceInput/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
