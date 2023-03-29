#include "filemonitor.h"
#include "statefile.h"
#include "filemonitorprinter.h"
#include <QCoreApplication>

using namespace std;


int main(int argc, char* argv[])
{
   QCoreApplication app(argc, argv);

   FileMonitor &TestMonitor = FileMonitor::Instance();               //Создаем монитор, автоматически инициализирующий таймер
   FileMonitorPrinter TestPrinter(TestMonitor);                     //Создаем для него принтер

   TestMonitor.addFile("E:\A.txt");                                 //Добавляем в монитор файлы.
   TestMonitor.addFile("E:\A.txt");                                 //Добавим такой же файл (проверим повторное добавление)
   TestMonitor.addFile("/Users/ludoviksoso/TestFileFolder/C.rtf");
   TestMonitor.addFile("LoremIpsum");                               //Уведомлений о добавлении файлов мы не увидим

   return app.exec();
}
