#ifndef FILEMONITORPRINTER_H
#define FILEMONITORPRINTER_H
#include "filemonitor.h"
#include <iostream>

using namespace std;

class FileMonitorPrinter : public QObject
{
    Q_OBJECT

public:
    FileMonitorPrinter(FileMonitor &m_monitor)
    {
        //Соединяем сигналы и слоты для обработки сигналов об удалении/добавлении файлов в монитор
        connect(&m_monitor, &FileMonitor::fileAddedToMonitor, this, &FileMonitorPrinter::OnFileAddedToMonitor);
        connect(&m_monitor, &FileMonitor::fileDeletedFromMonitor, this, &FileMonitorPrinter::OnFileDeletedFromMonitor);
        connect(&m_monitor, &FileMonitor::fileChanged, this, &FileMonitorPrinter::OnFileChanged);
        connect(&m_monitor, &FileMonitor::fileCreated, this, &FileMonitorPrinter::OnFileCreated);
        connect(&m_monitor, &FileMonitor::fileDeleted, this, &FileMonitorPrinter::OnFileDeleted);
    }

public slots:
    void OnFileAddedToMonitor(StateFile file);                      //При добавлении файла в монитор
    void OnFileDeletedFromMonitor(StateFile file);                  //При удалении файла из монитора
    void OnFileChanged(const QString &file_name, qint64 file_size); //При изменении размера файла
    void OnFileCreated(const QString &file_name, qint64 file_size); //При физическом создании файла
    void OnFileDeleted(const QString &file_name);                   //При удалении файла

};

#endif
