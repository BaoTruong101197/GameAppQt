#ifndef GAMESFACTORY_H
#define GAMESFACTORY_H

#include <QVector>
#include "GamesAbstract.h"
#include "Data/DataGame.h"

class GamesFactory
{
private:
    GamesFactory();

public:

    template<class T>

    T *getIntanceGames(DataGame* _dataGame) {
        static T* _instance = nullptr;
        if (nullptr == _instance) {
            _instance = new T(_dataGame);
        }
        return _instance;
    }

    static GamesFactory *getIntance();

private:
};

#endif // GAMESFACTORY_H
