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

void FileMonitor::addFile(StateFile *filename)
{
    m_files.append(filename);               //Добавляем файл
    emit fileAddedToMonitor(filename);      //Посылаем сигнал о создании файла
}

void FileMonitor::deleteFile(StateFile *filename)
{
    m_files.removeOne(filename);            //Удаляем файл
    emit fileDeletedFromMonitor(filename);  //Посылаем сигнал об удалении файла
    delete filename;
}

const QList<StateFile *> &FileMonitor::getAllFiles() const
{
    return m_files;                         //Геттер на список файлов
}

void FileMonitor::UpdateStates()
{
    for (int i = 0; i < m_files.size(); ++i) {      //Для каждого файла
        m_files[i]->updateState();                  //Обновляем статус
    }
}



