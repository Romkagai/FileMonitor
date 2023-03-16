#include "statefile.h"
#include <QFile>
#include <QFileInfo>

StateFile::StateFile(const QString& filename)

{
    m_fileName = filename;
    QFile file(m_fileName);
    m_Size = file.size();
    m_isExist = file.exists();
}

void StateFile::updateState() //функция на обновление данных о файле
{
    QFile file(m_fileName);
    bool exists = file.exists();    //существует ли файл сейчас?
    if (exists && !m_isExist) {     //если сейчас существует, а до этого нет - сигнал о создании
        m_Size = file.size();
        m_isExist = true;
        emit fileCreated(); //нужно ли отслеживание создания файла (при условии что добавлять можно только существующие файлы)
    }
    else if (exists && file.size() != m_Size) { //если сейчас существует, а размер не совпадает - сигнал об изменении
        m_Size = file.size();
        emit fileChanged();
    }
    else if (exists && file.size() == m_Size){
        emit fileStable();
    }
    else if (!exists && m_isExist) {    //если сейчас не существует, а до этого существовал - сигнал об удалении
        m_isExist = false;
        emit fileRemoved();
    }
}


QString StateFile::getFileName() const
{
    return m_fileName;
}

qint64 StateFile::getSize() const
{
    return m_Size;
}

bool StateFile::getExistStatus() const
{
    return m_isExist;
}


