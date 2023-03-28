#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "statefile.h"
#include <QTimer>

class FileMonitor : public QObject
{
    Q_OBJECT

public:
    FileMonitor();
    bool addFile(const QString &filename);              //Добавляем файл в QList
    bool deleteFile(const QString &filename);           //Удаляем файл из QList

public slots:
    void updateStates();                                //Функция для обновления всех файлов

signals:
    void fileAddedToMonitor(StateFile file);                        //Посылаем сигнал, когда файл добавлен под наблюдение
    void fileDeletedFromMonitor(StateFile file);                    //Посылаем сигнал, когда файл удален из под наблюдения
    void fileCreated(const QString &m_fileName, qint64 m_Size);     //Сигнал если файл создали
    void fileChanged(const QString &m_fileName, qint64 m_Size);     //Сигнал если файл изменили
    void fileDeleted(const QString &m_fileName);                    //Сигнал если файл удалили

private:
    QList<StateFile> m_files;  //Список файлов
};

#endif
