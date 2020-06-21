#include <QApplication>

#include "View/mainwindow.h"
#include "Controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    Controller c;

    w.setController(&c);
    c.setView(&w);
    w.show();

    a.setWindowIcon(QIcon(":resources/resources/QVisualizerIcon.png"));

    return a.exec();

}
