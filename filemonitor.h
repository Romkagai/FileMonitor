#ifndef FILEMONITOR_H
#define FILEMONITOR_H

#include <QSet>
#include "statefile.h"

class FileMonitor : public QObject
{
    Q_OBJECT

public:
    FileMonitor(QObject* parent = nullptr);
    ~FileMonitor();

    //функции пока что войды - надо будет переделать под бул, продумать условия наличия/отсутствия файлов
    void addFile(StateFile *filename); //вернет false если файл не получится добавить (уже присутствует)
    void deleteFile(StateFile *filename); //вернет false если файл не получится удалить (отсутствует изначально)

    const QList<StateFile*> &getAllFiles() const;

    //обновляем данные по файлам
    void UpdateStates();

signals:
    void MonitorFileCreated(const QString& filename, qint64 size);
    void MonitorFileChanged(const QString& filename, qint64 size);
    void MonitorFileRemoved(const QString& filename);

private:
    QList<StateFile*> m_files;
};

#endif // FILEMONITOR_H
