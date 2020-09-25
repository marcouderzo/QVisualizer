#ifndef FILEMANAGERWIDGET_H
#define FILEMANAGERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>

class Controller;

class FileManagerWidget: public QWidget
{
Q_OBJECT
public:
    FileManagerWidget();
    void setController(Controller*);
private:
    Controller* ctrl;
    QFileDialog* fileDialog;
    QPushButton* importFileButton;
    QPushButton* showDialogButton;
    QLabel* filenameLabel;
    QVBoxLayout* layout;
    std::string m_file;

signals:
    void sendToMediaVector(const std::string&);
    void clearText();

public slots:
    void onImportFileButtonPressed();
    void onSelectNewFileButtonPressed();

};

#endif // FILEMANAGERWIDGET_H
