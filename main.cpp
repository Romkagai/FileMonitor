#include "filemonitor.h"
#include "statefile.h"
#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include <QDebug>

using namespace std;

void Output(){
    qDebug() << "РАЗМЕР ФАЙЛА ИЗМЕНИЛСЯ";
}


int main(int argc, char* argv[])
{
   QCoreApplication app(argc, argv);

   StateFile *TestFile1 = new StateFile("E:\A.txt");
   StateFile *TestFile2 = new StateFile("E:\G0.txt");
   StateFile *TestFile3 = new StateFile("E:\G0.txt");
   StateFile *TestFile4 = new StateFile("LoremIpsum");

   StateFile TestFile("E:\A.txt");

   FileMonitor TestMonitor;

   TestMonitor.addFile(TestFile1);
   TestMonitor.addFile(TestFile2);
   TestMonitor.addFile(TestFile3);
   TestMonitor.addFile(TestFile4);

   QList<StateFile*> allFiles = TestMonitor.getAllFiles();

   for (int i = 0; i < allFiles.size(); ++i) {
       qDebug() << "Name: " << allFiles[i]->getFileName();
       qDebug() << "Size: " << allFiles[i]->getSize();
       qDebug() << "IsExist: " << allFiles[i]->getExistStatus();
   }



   QTimer timer;
   timer.setInterval(5000);


   QObject::connect(&timer, &QTimer::timeout, &TestFile, &StateFile::updateState);
   QObject::connect(&TestFile, &StateFile::fileChanged, Output);

   timer.start();




   //QTimer::singleShot(0, &app, SLOT(quit()));
   return app.exec();
}
