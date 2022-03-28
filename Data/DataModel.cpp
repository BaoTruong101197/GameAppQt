#include "DataModel.h"
#include <QDebug>

DataModel::DataModel(QObject *parent) : QAbstractListModel(parent)
{

}

DataModel::~DataModel()
{

}

bool DataModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), row, row + count  - 1);
    endInsertRows();
    return true;
}

bool DataModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    endRemoveRows();
    return true;
}

void DataModel::addDataGame(DataGame *_data)
{
    if (m_dataModel.contains(_data))
        return;

    m_dataModel.push_back(_data);
}

QVariant DataModel::getDataFromRole(const int &_type, const int &role) const
{
    QVariant result;
    for (const auto index : m_dataModel) {
        if (index->type() == _type) {
            switch(role) {
            case nameRole:
                result = index->name();
                break;
            case highScoreRole:
                result = index->highScore();
                break;
            case imgRole:
                result = index->img();
                break;
            default:
                break;
            }
        }
    }
    return result;
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    return m_dataModel.size();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    QVariant result;
    if( (0 <= row) && (m_dataModel.size() > row))
    {
        switch(role) {
        case typeRole:
            result = m_dataModel.at(row)->type();
            break;
        case nameRole:
            result = m_dataModel.at(row)->name();
            break;
        case highScoreRole:
            result = m_dataModel.at(row)->highScore();
            break;
        case imgRole:
            result = m_dataModel.at(row)->img();
            break;
        default:
            break;
        }
    }
    return result;
}

QHash<int, QByteArray> DataModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[typeRole] = "type";
    roles[nameRole] = "name";
    roles[highScoreRole] = "highScrore";
    roles[imgRole] = "img";
    return roles;
}
