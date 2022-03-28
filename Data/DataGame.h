#ifndef DATAGAME_H
#define DATAGAME_H

#include <QString>
#include <QObject>
#include "Enums.h"

class DataGame : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Enums::HMI_GAME type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString img READ img WRITE setImg NOTIFY imgChanged)
    // Easy Maths
    Q_PROPERTY(int highScore READ highScore WRITE setHighScore NOTIFY highScoreChanged)
public:
    DataGame();
    ~DataGame();

    // READ
    QString name();
    int highScore();
    Enums::HMI_GAME type();
    QString img();

    // WRITE
    void setName(const QString& _name);
    void setHighScore(const int& _highScore);
    void setType(const Enums::HMI_GAME& _type);
    void setImg(const QString& _img);

signals:
    // NOTIFY
    void nameChanged();
    void highScoreChanged();
    void typeChanged();
    void imgChanged();

private:

    QString m_strName {""};
    int m_nHighScore {0};
    Enums::HMI_GAME m_eType;
    QString m_strImg;
};

#endif // DATAGAME_H
