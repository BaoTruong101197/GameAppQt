#ifndef APPMAIN_H
#define APPMAIN_H
#include <QObject>
#include <QQuickView>
#include <QDebug>
#include <QQmlContext>
#include <QVector>

#include "Games/GamesFactory.h"
#include "Games/EasyMathsManager.h"
#include "AppWindow.h"
#include "Data/DataModel.h"
#include "Games/GamesAbstract.h"

class AppMain : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentView READ currentView WRITE setCurrentView NOTIFY currentViewChanged)
private:
    AppMain();

public:
    // method
    static AppMain *getInstance();
    void createView();
    void initAppMain();
    void addNameForGames();
    void addImgForGames();

    // invokable function
    Q_INVOKABLE int countOfGames();

    int currentView();

public slots:
    void setCurrentView(const int& _view);

signals:
    void createWindow();
    void currentViewChanged();

private:
    EasyMathsManager* m_easeMath {nullptr};
    GamesFactory* m_gameFactory {GamesFactory::getIntance()};
    AppWindow* m_appWindow {nullptr};
    QQuickView* m_view {nullptr};
    int m_nCurrentView {Enums::HMI_VIEW_WELCOME};
    DataModel* m_dataModel;
    DataGame* m_easyMathData {new DataGame()};
    QVector<GamesAbstract* > m_listGame;
};

#endif // APPMAIN_H
