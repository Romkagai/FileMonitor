#include <QString>
#include <QFileInfo>
#include <QFile>

#ifndef STATEFILE_H
#define STATEFILE_H

class StateFile : public QObject
{
    Q_OBJECT

public:
    StateFile(const QString& filename);     //Конструктор
    QString getFileName() ;                 //Геттер для имени
    qint64  getSize() ;                     //Геттер для размера
    bool    getExistStatus();               //Геттер для статуса существования

    int updateState();                              //Функция на обновление информации о файле

    StateFile(const StateFile& temp);               //Перегрузка оператора копирования
    StateFile& operator =(const StateFile& temp);   //Перегрузка оператора присваивания
    bool operator==(const StateFile& temp) const;   //Перегрузка оператора сравнения

private:
    QString m_fileName;     //Имя файла
    qint64  m_Size;         //Размер файла
    bool    m_isExist;      //Статус существования
};

#endif
