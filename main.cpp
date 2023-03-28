#include "filemonitor.h"
#include "statefile.h"
#include "filemonitorprinter.h"
#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include <QDebug>

using namespace std;

//написать отдельный файл для хранения путей к файлам//

int main(int argc, char* argv[])
{
   QCoreApplication app(argc, argv);

   //StateFile *TestFile1 = new StateFile("/Users/ludoviksoso/TestFileFolder/A.rtf");
   //StateFile *TestFile2 = new StateFile("/Users/ludoviksoso/TestFileFolder/B.rtf");
   //StateFile *TestFile3 = new StateFile("/Users/ludoviksoso/TestFileFolder/C.rtf");
   //StateFile *TestFile4 = new StateFile("LoremIpsum");

   //для монитора написать функцию, запускающую таймер TestMonitor.watch()//

   FileMonitor TestMonitor; //Создаем объект типа FileMonitor

   FileMonitorPrinter TestPrinter(TestMonitor); //Создаем объект - консольный принтер

   TestMonitor.addFile("/Users/ludoviksoso/TestFileFolder/A.rtf");  //Добавляем в монитор файлы.
   TestMonitor.addFile("/Users/ludoviksoso/TestFileFolder/B.rtf");  //Можно добавлять файлы и до определения принтера, однако
   TestMonitor.addFile("/Users/ludoviksoso/TestFileFolder/C.rtf");  //Уведомлений о добавлении файлов мы не увидим
   TestMonitor.addFile("LoremIpsum");

   QTimer timer;                    //Создаем объект Timer
   timer.setInterval(500);         //Обновляем каждые 5 секунд

   QObject::connect(&timer, &QTimer::timeout, &TestMonitor, &FileMonitor::updateStates); //Соединяем таймер и монитор

   timer.start();   //Запускаем таймер

   //Поставить таймер на пару минут (позже)
   //QTimer::singleShot(0, &app, SLOT(quit()));
   return app.exec();
}
