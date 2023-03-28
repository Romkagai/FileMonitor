#include "filemonitor.h"

FileMonitor::FileMonitor(QObject* parent) //Конструктор
    : QObject(parent)
{
}

FileMonitor::~FileMonitor() //Деструктор
{
    for (int i = 0; i < m_files.size(); ++i){
        delete m_files[i];
    }
    m_files.clear();
}

bool FileMonitor::addFile(const QString & filename)
{
    StateFile *newFile = new StateFile(filename);
    if (m_files.contains(newFile)){
        return false;
    }

    m_files.append(newFile);               //Добавляем файл
    emit fileAddedToMonitor(newFile);      //Посылаем сигнал о создании файла
    return true;
}

bool FileMonitor::deleteFile(const QString & filename)
{
    StateFile *oldFile = new StateFile(filename);

    if (m_files.contains(oldFile)){
        m_files.removeOne(oldFile);
        emit fileDeletedFromMonitor(oldFile);
        return true;
    }
    return false;
}

QList<StateFile*> FileMonitor::getAllFiles()
{
    return m_files;                         //Геттер на список файлов
}

void FileMonitor::updateStates()
{
    for (int i = 0; i < m_files.size(); ++i) {      //Для каждого файла
        m_files[i]->updateState();                  //Обновляем статус
    }
}




