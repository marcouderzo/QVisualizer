#include "View/filemanagerwidget.h"
#include "Controller/controller.h"

FileManagerWidget::FileManagerWidget()
{
    resize(200, 100);
    importFileButton=new QPushButton("Import File");
    layout=new QVBoxLayout();
    pathBox=new QLineEdit();

    layout->addWidget(pathBox);
    layout->addWidget(importFileButton);

    setLayout(layout);

    connect(importFileButton, SIGNAL(clicked()), this, SLOT(onImportFileButtonPressed()));
    connect(this, SIGNAL(clearText()), pathBox, SLOT(clear()));
}

void FileManagerWidget::setController(Controller * c)
{
    ctrl=c;
}

void FileManagerWidget::onImportFileButtonPressed()
{
    emit sendToMediaVector(pathBox->text().toStdString());
    emit clearText();
}
