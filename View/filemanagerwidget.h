#ifndef FILEMANAGERWIDGET_H
#define FILEMANAGERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLineEdit>

class Controller;

class FileManagerWidget: public QWidget
{
Q_OBJECT
public:
    FileManagerWidget();
    void setController(Controller*);
private:
    Controller* ctrl;
    QPushButton* importFileButton;
    QLineEdit* pathBox;
    QVBoxLayout* layout;

signals:
    void sendToMediaVector(const std::string&);
    void clearText();

public slots:
    void onImportFileButtonPressed();

};

#endif // FILEMANAGERWIDGET_H
