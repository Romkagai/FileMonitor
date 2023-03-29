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
   TestMonitor.addFile("/Users/ludoviksoso/TestFileFolder/A.rtf");
   TestMonitor.addFile("/Users/ludoviksoso/TestFileFolder/A.rtf");
   TestMonitor.addFile("/Users/ludoviksoso/TestFileFolder/C.rtf");  //Добавим такой же файл (проверим повторное добавление)
   TestMonitor.addFile("LoremIpsum");                               //Уведомлений о добавлении файлов мы не увидим

   QTimer timer;                  //Создаем объект Timer
   timer.setInterval(500);        //Соединяем таймер и монитор
   QObject::connect(&timer, &QTimer::timeout, &TestMonitor, &FileMonitor::updateStates);
   timer.start();                              //Уведомлений о добавлении файлов мы не увидим

   return app.exec();
}
