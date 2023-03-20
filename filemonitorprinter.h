#ifndef FILEMONITORPRINTER_H
#define FILEMONITORPRINTER_H
#include <QDebug>
#include "filemonitor.h"

class FileMonitorPrinter : public QObject
{
    Q_OBJECT

public:
    FileMonitorPrinter(FileMonitor &monitor) : m_monitor(monitor)
    {
        //Соединяем сигналы и слоты для обработки сигналов об удалении/добавлении файлов в монитор
        connect(&m_monitor, &FileMonitor::fileAddedToMonitor, this, &FileMonitorPrinter::OnFileAddedToMonitor);
        connect(&m_monitor, &FileMonitor::fileDeletedFromMonitor, this, &FileMonitorPrinter::OnFileDeletedFromMonitor);

        //Соединяем сигналы и слоты для уже существующих в мониторе файлов
        for (auto& stateFile : m_monitor.getAllFiles()) {
                 connect(stateFile, &StateFile::fileChanged, this, &FileMonitorPrinter::OnFileChanged);
                 connect(stateFile, &StateFile::fileCreated, this, &FileMonitorPrinter::OnFileCreated);
                 connect(stateFile, &StateFile::fileDeleted, this, &FileMonitorPrinter::OnFileDeleted);
             }
    }

public slots:
    void OnFileAddedToMonitor(StateFile* file);     //При добавлении файла в монитор
    void OnFileDeletedFromMonitor(StateFile* file); //При удалении файла из монитора

    void OnFileChanged(const QString &file_name, qint64 file_size); //При изменении размера файла
    void OnFileCreated(const QString &file_name, qint64 file_size); //При физическом создании файла
    void OnFileDeleted(const QString &file_name);                   //При удалении файла

private:
    FileMonitor& m_monitor; //Монитор для принтера

};

#endif
