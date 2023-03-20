#ifndef FILEMONITOR_H
#define FILEMONITOR_H
#include "statefile.h"

class FileMonitor : public QObject
{
    Q_OBJECT

public:
    FileMonitor(QObject* parent = nullptr); //Конструктор
    ~FileMonitor();                         //Деструктор

    //Функции добавления и удаления типа void потому что файл (его имя)
    //мы в любом случае можем добавить под наблюдение, но
    //будем отображать факт существования файла при его добавлении в монитор

    void addFile(StateFile *filename);              //Добавляем файл в QList
    void deleteFile(StateFile *filename);           //Удаляем файл из QList
    const QList<StateFile*> &getAllFiles() const;   //Геттер для всех файлов

public slots:
    void UpdateStates();

signals:
    void fileAddedToMonitor(StateFile *file);       //Посылаем сигнал, когда файл добавлен под наблюдение
    void fileDeletedFromMonitor(StateFile *file);   //Посылаем сигнал, когда файл удален из под наблюдения

private:
    QList<StateFile*> m_files;  //Список файлов
};

#endif
