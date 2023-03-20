#include "statefile.h"
#include <QFile>
#include <QFileInfo>

StateFile::StateFile(const QString& filename)
{
    m_fileName = filename;          //Задаем имя файла
    QFile file(m_fileName);         //Создаем объект QFile и
    m_Size = file.size();           //Определяем размер
    m_isExist = file.exists();      //И факт существования
}

void StateFile::updateState()       //Функция на обновление данных о файле
{
    QFile file(m_fileName);
    bool exists = file.exists();    //Существует ли файл сейчас?
    if (exists && !m_isExist) {     //Если сейчас существует, а до этого нет - сигнал о создании(!)
        m_Size = file.size();
        m_isExist = true;
        emit fileCreated(m_fileName, m_Size);
    }
    else if (exists && file.size() != m_Size) { //Если сейчас существует, а размер не совпадает - сигнал об изменении(!)
        m_Size = file.size();
        emit fileChanged(m_fileName, m_Size);
    }
    else if (!exists && m_isExist) {            //Если сейчас не существует, а до этого существовал - сигнал об удалении(!)
        m_isExist = false;
        emit fileDeleted(m_fileName);
    }
}

QString StateFile::getFileName() const      //Геттер имени
{
    return m_fileName;
}

qint64 StateFile::getSize() const           //Геттер размера
{
    return m_Size;
}

bool StateFile::getExistStatus() const      //Геттер существования
{
    return m_isExist;
}


