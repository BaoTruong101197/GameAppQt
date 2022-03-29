#include "EasyMathsManager.h"
#include <QDebug>

EasyMathsManager::EasyMathsManager(DataGame *_data)
{
    m_data = _data;
}

void EasyMathsManager::addName()
{
    m_data->setName("Easy Maths");
}

void EasyMathsManager::addImg()
{
    m_data->setImg("Data/Img/Easymath.png");
}

void EasyMathsManager::startGame()
{
    m_data->setType(Enums::HMI_GAME_EASY_MATH);
    setScore(0);
    setLevel(1);
    m_nTime = 10;
    generateCalculator();

    emit sigNextLevel();
}

void EasyMathsManager::nextLevel()
{
    setTime(10);
    setScore(m_nScore + m_nLevel);
    setLevel(m_nLevel + 1);
    generateCalculator();

    emit sigNextLevel();
}

void EasyMathsManager::gameOver()
{
    updateData();
    emit sigGameOver();
}

void EasyMathsManager::updateData()
{
    if (m_data->highScore() < m_nScore) {
        m_data->setHighScore(m_nScore);
    }
}

int EasyMathsManager::getRandomNumber(const int &_min, const int &_max)
{
    return floor(((float) rand() / (RAND_MAX)) * (_max - _min) + _min);
}

QString EasyMathsManager::getRandomOperator()
{
    QVector<QString> operators = {"+", "-", "*"};
    m_nRandomOperator = floor(((float) rand() / (RAND_MAX)) * operators.size());
    return operators[m_nRandomOperator];
}

void EasyMathsManager::generateCalculator()
{
    int number1 = getRandomNumber(1 * m_nLevel, 5 * m_nLevel);
    int number2 = getRandomNumber(1 * m_nLevel, 5 * m_nLevel);
    QString op = QVariant(number1).toString() + " " + getRandomOperator() + " " + QVariant(number2).toString();
    switch (m_nRandomOperator) {
    case 0:
        m_nResult = number1 + number2;
        break;
    case 1:
        m_nResult = number1 - number2;
        break;
    case 2:
        m_nResult = number1 * number2;
        break;
    }
    setCalculator(op);
    getResult();
}

void EasyMathsManager::getResult()
{
     m_bRandomResult = ((float) rand() / (RAND_MAX)) >= 0.5;
    if (m_bRandomResult == false) {
        m_nResult = getRandomNumber(m_nResult - 10, m_nResult + 10);
    }
    setResult(m_nResult);
}

void EasyMathsManager::requestAnswearGame(const bool &_ans)
{
    if (m_bRandomResult == _ans) {
        nextLevel();
    } else {
        gameOver();
    }
}

void EasyMathsManager::requestRestartGame()
{
    startGame();
}

int EasyMathsManager::time()
{
    return m_nTime;
}

int EasyMathsManager::level()
{
    return m_nLevel;
}

int EasyMathsManager::result()
{
    return m_nResult;
}

int EasyMathsManager::score()
{
    return m_nScore;
}

QString EasyMathsManager::calculator()
{
    return m_strCalculator;
}

void EasyMathsManager::setTime(const int& _time)
{
    if (m_nTime != _time) {
        m_nTime = _time;
        if (m_nTime == 0) {
            emit gameOver();
        }
    }

    emit timeChanged();
}

void EasyMathsManager::setLevel(const int& _level)
{
    if (m_nLevel != _level) {
        m_nLevel = _level;
    }

    emit levelChanged();
}

void EasyMathsManager::setResult(const int &_result)
{
    if (m_nResult != _result) {
        m_nResult = _result;
    }

    emit resultChanged();
}

void EasyMathsManager::setScore(const int &_score)
{
    if (m_nScore != _score) {
        m_nScore = _score;
    }

    emit scoreChanged();
}

void EasyMathsManager::setCalculator(const QString &_calc)
{
    if (m_strCalculator != _calc) {
        m_strCalculator = _calc;
    }

    emit calculatorChanged();
}
