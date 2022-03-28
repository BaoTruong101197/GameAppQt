#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QObject>
#include <QQuickView>

class AppWindow : public QObject
{
    Q_OBJECT
public:
    static AppWindow *getInstance();
    void onCreateWindow(QQuickView* _view);

private:
    AppWindow();

    QQuickView* m_view;
};

#endif // APPWINDOW_H
