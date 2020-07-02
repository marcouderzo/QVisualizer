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
    QLabel m_genre;
    QLabel m_mood;
    QLabel m_year;
    QLabel m_bitrate;
    QLabel m_samplerate;
    QLabel m_channelcount;

public slots:

    void onUpdateProperties(const std::string&title, const std::string&artist, const std::string&album, bool lossless, const std::string&genre, const std::string&mood, unsigned int year, unsigned int bitrate, unsigned int samplerate, unsigned int channelcount);
    void onSetDefaultEvent();

};

#endif // MEDIAPROPERTIESWIDGET_H
