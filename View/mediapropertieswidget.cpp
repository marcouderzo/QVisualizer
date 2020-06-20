#include "mediapropertieswidget.h"

MediaPropertiesWidget::MediaPropertiesWidget()
{
    setFixedSize(220, 310);
    layout = new QGridLayout();

    QLabel* titleLabel= new QLabel("Title: ");
    QLabel* artistLabel= new QLabel("Artist: ");
    QLabel* albumLabel= new QLabel("Album: ");
    QLabel* losslessLabel= new QLabel("Lossless: ");

    m_title.setText("No Media Selected");
    m_artist.setText("No Media Selected");
    m_album.setText("No Media Selected");
    m_lossless.setText("No Media Selected");

    layout->addWidget(titleLabel,0,0);
    layout->addWidget(&m_title,0,1);
    layout->addWidget(artistLabel,1,0);
    layout->addWidget(&m_artist,1,1);
    layout->addWidget(albumLabel,2,0);
    layout->addWidget(&m_album,2,1);
    layout->addWidget(losslessLabel,3,0);
    layout->addWidget(&m_lossless,3,1);

    setLayout(layout);
}


void MediaPropertiesWidget::setController(Controller * c)
{
    ctrl=c;
}

void MediaPropertiesWidget::onUpdateProperties(const std::string& title, const std::string& artist, const std::string& album, bool lossless)
{
     if(title=="")
         m_title.setText("No Title Available");
     else
         m_title.setText(title.c_str());
     if(artist=="")
         m_artist.setText("No Artist Available");
     else
         m_artist.setText(artist.c_str());
     if(album=="")
         m_album.setText("No Title Available");
     else
         m_album.setText(artist.c_str());
     if(lossless)
         m_lossless.setText("True");
     else
         m_lossless.setText("False");
}

void MediaPropertiesWidget::onSetDefaultEvent()
{
    m_title.setText("No Media Selected");
    m_artist.setText("No Media Selected");
    m_album.setText("No Media Selected");
    m_lossless.setText("No Media Selected");
}
