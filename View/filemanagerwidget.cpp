#include "View/filemanagerwidget.h"
#include "Controller/controller.h"
#include "exceptions.h"

FileManagerWidget::FileManagerWidget():importFileButton(new QPushButton("Import File")), pathBox(new QLineEdit()), layout(new QVBoxLayout())
{
    resize(200, 100);
    
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
