#ifndef GAMESABSTRACT_H
#define GAMESABSTRACT_H

#include <QObject>

class GamesAbstract
{
public:
    GamesAbstract();
    virtual ~GamesAbstract();

    virtual void addName() = 0;
    virtual void addImg() = 0;
    virtual void startGame() = 0;
    virtual void nextLevel() = 0;
    virtual void gameOver() = 0;
};

#endif // GAMESABSTRACT_H
