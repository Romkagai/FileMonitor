#include "filemonitor.h"

FileMonitor::FileMonitor()
{
    QTimer* timer = new QTimer(this);                                       //Будем объявлять таймер сразу при создании
    connect(timer, &QTimer::timeout, this, &FileMonitor::updateStates);     //Монитора
    timer->start();
}

bool FileMonitor::addFile(const QString & filename)     //Добавление файла в монитор
{
    StateFile newFile(filename);            //Создаем новый файл
    if (m_files.contains(newFile)){         //Если он уже есть в списке
        return false;                       //Ничего не делаем
    }
    m_files.append(newFile);                //Иначе добавляем файл
    emit fileAddedToMonitor(newFile);       //Посылаем сигнал о добавлении файла
    return true;
}

bool FileMonitor::deleteFile(const QString & filename) //Удаление файла из монитора
{
    StateFile oldFile(filename);                //Создаем файл для проверки
    if (m_files.contains(oldFile)){             //Если он есть в списке
        m_files.removeOne(oldFile);             //То удаляем его
        emit fileDeletedFromMonitor(oldFile);   //Посылаем сигнал об удалении файла из монитора
        return true;
    }
    return false;                               //Если его нет, то и удалять нечего
}

void FileMonitor::updateStates() //Функция на обновление всех файлов
{
    for (int i = 0; i < m_files.size(); ++i) {      //Для каждого файла
        switch (m_files[i].updateState())           //Проверяем данные о нем
        {
        case 0:                                     //Ничего не изменилось - ничего не делаем
            break;
        case 1:
            emit fileCreated(m_files[i].getFileName(), m_files[i].getSize());   //Файл создан - см. StateFile.cpp
            break;
        case 2:
           emit fileChanged(m_files[i].getFileName(), m_files[i].getSize());    //Файл изменен - см. StateFile.cpp
           break;
        case 3:
           emit fileDeleted(m_files[i].getFileName());                          //Файл удален - см. StateFile.cpp
           break;
        };
    }
}
