#include "AppMain.h"

AppMain::AppMain()
{
    m_listGame.clear();
    m_dataModel = new DataModel(nullptr);
}

AppMain *AppMain::getInstance()
{
    static AppMain* instance = nullptr;
    if (nullptr == instance) {
        instance = new AppMain();
    }
    return instance;
}

void AppMain::createView()
{
    m_appWindow = AppWindow::getInstance();
    if (nullptr == m_view) {
        m_view = new QQuickView();
    }
    qmlRegisterType<Enums>("Enums", 1, 0, "Enums");

    if (m_view == nullptr)
        return;

    m_view->rootContext()->setContextProperty("myAppMain", this);
    m_view->rootContext()->setContextProperty("dataModel", m_dataModel);
    m_view->rootContext()->setContextProperty("easyMath", m_easeMath);

    m_appWindow->onCreateWindow(m_view);
}

void AppMain::initAppMain()
{
    qDebug() << "init AppMain";
    m_easeMath = GamesFactory::getIntance()->getIntanceGames<EasyMathsManager>(m_easyMathData);
    m_dataModel->addDataGame(m_easyMathData);
    m_listGame.push_back(m_easeMath);
    m_easyMathData->setHighScore(0);
    addNameForGames();
    addImgForGames();

    createView();
}

void AppMain::addNameForGames()
{
    for (const auto index : m_listGame) {
        index->addName();
    }
}

void AppMain::addImgForGames()
{
    for (const auto index : m_listGame) {
        index->addImg();
    }
}

int AppMain::currentView()
{
    return m_nCurrentView;
}

void AppMain::setCurrentView(const int &_view)
{
    if (m_nCurrentView != _view) {
        m_nCurrentView = _view;
        switch (m_nCurrentView) {
        case Enums::HMI_VIEW_EASYMATH:
            m_easeMath->startGame();
            break;
        }
    }

    emit currentViewChanged();
}

int AppMain::countOfGames()
{
    return m_listGame.size();
}



