#include "filemonitorprinter.h"

//При добавлении файла в монитор будем прописывать сообщение и коннекты для него
void FileMonitorPrinter::OnFileAddedToMonitor(StateFile *file)
{
    cout << "Файл:" << file->getFileName().toStdString().c_str() << " был добавлен под наблюдение, его размер: " << file->getSize() << endl;
    cout << "Файл существует? 1 - Да, 0 - Нет: " << file->getExistStatus() << endl << endl;
    connect(file, &StateFile::fileChanged, this, &FileMonitorPrinter::OnFileChanged);
    connect(file, &StateFile::fileCreated, this, &FileMonitorPrinter::OnFileCreated);
    connect(file, &StateFile::fileDeleted, this, &FileMonitorPrinter::OnFileDeleted);
}

//При удалении файла из монитора будем прописывать сообщение и коннекты для него
void FileMonitorPrinter::OnFileDeletedFromMonitor(StateFile *file)
{
    cout << "Файл:" << file->getFileName().toStdString().c_str() << " был удален из под наблюдения";
    connect(file, &StateFile::fileChanged, this, &FileMonitorPrinter::OnFileChanged);
    connect(file, &StateFile::fileCreated, this, &FileMonitorPrinter::OnFileCreated);
    connect(file, &StateFile::fileDeleted, this, &FileMonitorPrinter::OnFileDeleted);
}

//При изменении файла выводим уведомление об изменении файла и его новый размер
void FileMonitorPrinter::OnFileChanged(const QString &file_name, qint64 file_size)
{
    cout << "Размер файла "<<  file_name.toStdString().c_str() << " изменен, новый размер:" << file_size;
}

//При физическом создании файла выводим уведомление о создании файла и его размер
void FileMonitorPrinter::OnFileCreated(const QString &file_name, qint64 file_size)
{
    cout << "Файл "<<  file_name.toStdString().c_str() << " был создан, его размер:" << file_size;
}

//При физическом удалении файла выводим уведомление об удалении файла
void FileMonitorPrinter::OnFileDeleted(const QString &file_name)
{
    cout << "Файл "<<  file_name.toStdString().c_str() << " был удален";
}
