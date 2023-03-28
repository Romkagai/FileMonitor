#include "statefile.h"

StateFile::StateFile(const QString& filename)
{
    m_fileName = filename;          //Задаем имя файла
    QFile file(m_fileName);         //Создаем объект QFile
    m_Size = file.size();           //Определяем размер
    m_isExist = file.exists();      //И факт существования
}

QString StateFile::getFileName()        //Геттер имени
{
    return m_fileName;
}

qint64 StateFile::getSize()             //Геттер размера
{
    return m_Size;
}

bool StateFile::getExistStatus()        //Геттер существования
{
    return m_isExist;
}

int StateFile::updateState()            //Функция для обновления данных о файле
{
    QFile file(m_fileName);
    bool exists = file.exists();                //Существует ли файл сейчас?
    if (exists && !m_isExist) {                 //Если сейчас существует, а до этого нет - сигнал о создании (возвращаем первый случай)
        m_Size = file.size();
        m_isExist = true;
        return 1;
    }
    else if (exists && file.size() != m_Size) { //Если сейчас существует, а размер не совпадает - сигнал об изменении (возвращаем второй случай)
        m_Size = file.size();
        return 2;
    }
    else if (!exists && m_isExist) {            //Если сейчас не существует, а до этого существовал - сигнал об удалении(возвращаем третий случай)
        m_isExist = false;
        return 3;
    }
    return 0;                                   //Если ничего не произошло, вернем 0
}

StateFile::StateFile(const StateFile& tmp) //Перегрузка оператора копирования
{
    m_fileName = tmp.m_fileName;
    m_Size = tmp.m_Size;
    m_isExist = tmp.m_isExist;
}

bool StateFile::operator==(const StateFile& tmp) const //Перегрузка оператора сравнения
{
    return m_fileName == tmp.m_fileName &&
           m_Size == tmp.m_Size &&
           m_isExist == tmp.m_isExist;
}

StateFile& StateFile::operator =(const StateFile& tmp) //Перегрузка оператора присваивания
{
    m_fileName = tmp.m_fileName;
    m_isExist = tmp.m_isExist;
    m_Size = tmp.m_Size;
    return *this;
}
