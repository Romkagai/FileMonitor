#include "filemonitor.h"
#include <QSet>

FileMonitor::FileMonitor(QObject* parent)
    : QObject(parent)
{
}

FileMonitor::~FileMonitor()
{
    for (int i = 0; i < m_files.size(); ++i){
        delete m_files[i];
    }
    m_files.clear();
}

void FileMonitor::addFile(StateFile *filename)
{
    m_files.append(filename);
}

void FileMonitor::deleteFile(StateFile *filename)
{
    m_files.removeOne(filename);
    delete filename;
}

const QList<StateFile *> &FileMonitor::getAllFiles() const
{
    return m_files;
}

void FileMonitor::UpdateStates()
{
    for (int i = 0; i < m_files.size(); ++i) {
        m_files[i]->updateState();
    }
}



