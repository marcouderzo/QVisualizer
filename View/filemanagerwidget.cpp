#include "View/filemanagerwidget.h"
#include "Controller/controller.h"
#include "exceptions.h"
#include <QDebug>

FileManagerWidget::FileManagerWidget():fileDialog(new QFileDialog()), importFileButton(new QPushButton("Import Selected File")), showDialogButton(new QPushButton("Select New File")), filenameLabel(new QLabel("No File has been selected yet.")), layout(new QVBoxLayout())
{
    resize(200, 100);
    layout->addWidget(filenameLabel);
    layout->addWidget(showDialogButton);
    layout->addWidget(importFileButton);
    setLayout(layout);
    connect(importFileButton, SIGNAL(clicked()), this, SLOT(onImportFileButtonPressed()));
    connect(showDialogButton, SIGNAL(clicked()), this, SLOT(onSelectNewFileButtonPressed()));
}

void FileManagerWidget::setController(Controller * c)
{
    ctrl=c;
}

void FileManagerWidget::onImportFileButtonPressed()
{

    emit sendToMediaVector(m_file);
    filenameLabel->clear();
}

void FileManagerWidget::onSelectNewFileButtonPressed()
{
    std::string file = QFileDialog::getOpenFileUrl().toString().toStdString();
    #ifdef Q_OS_WIN
        file.erase(0, 8);
    #endif

    #ifdef Q_OS_UNIX
        file.erase(0, 7);
    #endif
    m_file = file;
    filenameLabel->setText(QString::fromUtf8(m_file.c_str()));
}
