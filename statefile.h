#include <QString>
#include <QFileInfo>
#include <QSet>

#ifndef STATEFILE_H
#define STATEFILE_H

#include <QString>

class StateFile : public QObject
{
    Q_OBJECT

public:
    StateFile(const QString& filename);
    void updateState(); //нужно ли явно описать как слот для удобства чтения? если описывать как слот обязательно ли добавлять public?
    QString getFileName() const;
    qint64 getSize() const;
    bool getExistStatus() const;


signals:
    void fileCreated(); //Если файл создали
    void fileChanged(); //Если файл изменили
    void fileRemoved(); //Если файл удалили
    void fileStable();  //Если с файлом все в порядке

private:
    QString m_fileName;
    qint64  m_Size;
    bool    m_isExist;
};

#endif
