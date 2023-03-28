#include "filemonitorprinter.h"

//При добавлении файла в монитор будем прописывать сообщение и коннекты для него
void FileMonitorPrinter::OnFileAddedToMonitor(StateFile file)
{
    cout << "File: " << file.getFileName().toStdString() << " has been added to monitor, it's size: " << file.getSize() << " bytes." << endl;
    if (file.getExistStatus()) {
        cout << "File exists!" << endl << endl;
    }
    else {cout << "File does not exist!" << endl << endl; }
}

//При удалении файла из монитора будем прописывать сообщение и коннекты для него
void FileMonitorPrinter::OnFileDeletedFromMonitor(StateFile file)
{
    cout << "File: " << file.getFileName().toStdString() << " has been deleted from monitor" << endl;
}

//При изменении файла выводим уведомление об изменении файла и его новый размер
void FileMonitorPrinter::OnFileChanged(const QString &file_name, qint64 file_size)
{
    cout << "> Size of file "<<  file_name.toStdString() << " has been changed, new size: " << file_size << " bytes." << endl << endl;
}

//При физическом создании файла выводим уведомление о создании файла и его размер
void FileMonitorPrinter::OnFileCreated(const QString &file_name, qint64 file_size)
{
    cout << "> File "<<  file_name.toStdString() << " was created, it's size:" << file_size << " bytes." << endl << endl;
}

//При физическом удалении файла выводим уведомление об удалении файла
void FileMonitorPrinter::OnFileDeleted(const QString &file_name)
{
    cout << "> File "<<  file_name.toStdString() << " was deleted." << endl << endl;
}
