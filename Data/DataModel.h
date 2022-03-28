#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QVector>
#include <QAbstractListModel>
#include "Enums.h"
#include "DataGame.h"

class DataModel : public QAbstractListModel
{
    Q_OBJECT
public:
    DataModel(QObject *parent = nullptr);
    ~DataModel() override;
    enum RoleNames {
        typeRole = Qt::UserRole,
        imgRole,
        nameRole,
        highScoreRole
    };
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    void addDataGame(DataGame* _data);
    Q_INVOKABLE QVariant getDataFromRole(const int& _type, const int& role) const;
protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QVector<DataGame*> m_dataModel;
};

#endif // DATAMODEL_H

