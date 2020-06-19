#include <QApplication>
#include <QFile>

#include "View/mainwindow.h"
#include "Controller/controller.h"

//Test Paths
//C:/Users/marco/Downloads/Adrenalize - Wherever The Light Ends.mp3
//C:/Users/marco/Downloads/NDR8  SKYTTERS  Im In Love.mp3
//C:/Users/marco/Downloads/Pink Floyd - Wish You Were Here.mp3
//C:/Users/marco/Downloads/Bassjackers & KSHMR ft Sidnie Tipton - Extreme.mp3

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    Controller c;

    w.setController(&c);
    c.setView(&w);

    /*
    QFile File(":resources/resources/stylesheet.css");
    File.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(File.readAll());
    a.setStyleSheet(styleSheet);
    */

    w.resize(1200,700);
    w.show();

    a.setWindowIcon(QIcon(":resources/resources/QVisualizerIcon.png"));

    return a.exec();

}
