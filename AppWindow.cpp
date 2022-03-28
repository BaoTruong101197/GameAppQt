#include "AppWindow.h"

AppWindow::AppWindow()
{
    m_view = nullptr;
}

void AppWindow::onCreateWindow(QQuickView* _view)
{
    if (nullptr == _view)
        return;

    _view->setResizeMode(QQuickView::SizeRootObjectToView);
    _view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    _view->setGeometry(0, 0, 1920, 950);
    _view->show();
}

AppWindow *AppWindow::getInstance()
{
    static AppWindow *_instance = nullptr;

    if (nullptr == _instance) {
        _instance = new AppWindow();
    }
    return _instance;
}
