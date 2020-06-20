#ifndef MEDIAPROPERTIESWIDGET_H
#define MEDIAPROPERTIESWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

#include "Controller/controller.h"

class MediaPropertiesWidget: public QWidget
{
Q_OBJECT
public:
    MediaPropertiesWidget();
    void setController(Controller*);
private:
    Controller* ctrl;

    QGridLayout* layout;

    QLabel m_title;
    QLabel m_artist;
    QLabel m_album;
    QLabel m_lossless;

public slots:

    void onUpdateProperties(const std::string&, const std::string&, const std::string&, bool);

};

#endif // MEDIAPROPERTIESWIDGET_H
