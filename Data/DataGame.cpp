#include "DataGame.h"

DataGame::DataGame()
{

}

DataGame::~DataGame()
{

}

QString DataGame::name()
{
    return m_strName;
}

int DataGame::highScore()
{
    return m_nHighScore;
}

Enums::HMI_GAME DataGame::type()
{
    return m_eType;
}

QString DataGame::img()
{
    return m_strImg;
}

void DataGame::setName(const QString &_name)
{
    if (m_strName != _name) {
        m_strName = _name;
    }
    emit nameChanged();
}

void DataGame::setHighScore(const int &_highScore)
{
    if (m_nHighScore != _highScore) {
        m_nHighScore = _highScore;
    }
    emit highScoreChanged();
}

void DataGame::setType(const Enums::HMI_GAME &_type)
{
    if (m_eType != _type) {
        m_eType = _type;
    }

    emit typeChanged();
}

void DataGame::setImg(const QString &_img)
{
    if (m_strImg != _img) {
        m_strImg = _img;
    }

    emit imgChanged();
}
