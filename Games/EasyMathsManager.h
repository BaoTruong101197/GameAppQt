#ifndef EASYMATHSMANAGER_H
#define EASYMATHSMANAGER_H

#include <QObject>
#include <QString>
#include <cmath>
#include <QVector>
#include "GamesAbstract.h"
#include "Enums.h"
#include "Data/DataGame.h"

using namespace std;

class EasyMathsManager : public QObject, public GamesAbstract
{
    Q_OBJECT
    Q_PROPERTY(int time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(int level READ level WRITE setLevel NOTIFY levelChanged)
    Q_PROPERTY(int result READ result WRITE setResult NOTIFY resultChanged)
    Q_PROPERTY(int score READ score WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(QString calculator READ calculator WRITE setCalculator NOTIFY calculatorChanged)
public:
    EasyMathsManager(DataGame* _data);

    void addName() Q_DECL_OVERRIDE;
    void addImg() Q_DECL_OVERRIDE;
    void startGame() Q_DECL_OVERRIDE;
    void nextLevel() Q_DECL_OVERRIDE;
    void gameOver() Q_DECL_OVERRIDE;

    // METHOD
    void updateData();
    int getRandomNumber(const int& _min, const int& _max);
    QString getRandomOperator();
    void generateCalculator();
    void getResult();

    Q_INVOKABLE void requestAnswearGame(const bool& _ans);
    Q_INVOKABLE void requestRestartGame();

    // READ
    int time();
    int level();
    int result();
    int score();
    QString calculator();

public slots:
    // WRITE
    void setTime(const int& _time);
    void setLevel(const int& _level);
    void setResult(const int& _result);
    void setScore(const int& _score);
    void setCalculator(const QString& _calc);

signals:
    void timeChanged();
    void levelChanged();
    void resultChanged();
    void scoreChanged();
    void calculatorChanged();

    // to qml
    void sigNextLevel();
    void sigGameOver();

private:
    DataGame* m_data {nullptr};
    int m_nTime {10};
    int m_nLevel {1};
    int m_nResult {0};
    int m_nScore {0};
    int m_nRandomOperator {-1};
    QString m_strCalculator {""};
    bool m_bRandomResult {false};
};

#endif // EASYMATHSMANAGER_H
