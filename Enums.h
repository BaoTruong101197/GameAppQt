#ifndef ENUMS_H
#define ENUMS_H

#include <QObject>

class Enums : public QObject {
    Q_OBJECT
public:
    Enums();

    enum HMI_GAME {
        HMI_GAME_NONE = 0,
        HMI_GAME_EASY_MATH
    };

    enum HMI_VIEW {
        HMI_VIEW_NONE = 0,
        HMI_VIEW_WELCOME,
        HMI_VIEW_EASYMATH
    };

    enum ROLE_GAME {
        ROLE_GAME_TYPE = Qt::UserRole,
        ROLE_GAME_IMG,
        ROLE_GAME_NAME,
        ROLE_GAME_HIGHSCORE
    };

    Q_ENUM(HMI_GAME)
    Q_ENUM(HMI_VIEW)
    Q_ENUM(ROLE_GAME)

};

#endif // ENUMS_H
