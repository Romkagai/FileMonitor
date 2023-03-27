#include <QString>
#include <QFileInfo>

#ifndef STATEFILE_H
#define STATEFILE_H


class StateFile : public QObject
{
    Q_OBJECT

public:
    StateFile(const QString& filename); //Конструктор
    QString getFileName() const;        //Геттер для имени
    qint64  getSize() const;            //Геттер для размера
    bool    getExistStatus() const;     //Геттер для статуса существования

public slots:
    void updateState();                 //Слот на обновление информации о файле

signals:
    void fileCreated(const QString &m_fileName, qint64 m_Size);     //Если файл создали
    void fileChanged(const QString &m_fileName, qint64 m_Size);     //Если файл изменили
    void fileDeleted(const QString &m_fileName);                    //Если файл удалили

private:
    QString m_fileName;     //Имя файла
    qint64  m_Size;         //Размер файла
    bool    m_isExist;      //Статус существования
};

#endif
