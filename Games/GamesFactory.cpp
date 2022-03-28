#include "GamesFactory.h"
#include <QDebug>

GamesFactory::GamesFactory()
{
}

GamesFactory *GamesFactory::getIntance()
{
    static GamesFactory* instance = nullptr;

    if (nullptr == instance) {
        instance = new GamesFactory();
    }
    return instance;
}

