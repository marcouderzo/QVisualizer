#include "mediapropertieswidget.h"

MediaPropertiesWidget::MediaPropertiesWidget()
{
    setFixedSize(405, 315);
    layout = new QGridLayout();

    QLabel* titleLabel= new QLabel("Title: ");
    QLabel* artistLabel= new QLabel("Artist: ");
    QLabel* albumLabel= new QLabel("Album: ");
    QLabel* losslessLabel= new QLabel("Lossless: ");
    QLabel* genreLabel= new QLabel("Genre: ");
    QLabel* moodLabel= new QLabel("Mood: ");
    QLabel* yearLabel= new QLabel("Year: ");
    QLabel* bitrateLabel= new QLabel("Bitrate (bit): ");
    QLabel* samplerateLabel= new QLabel("Sample Rate: ");
    QLabel* channelcountLabel= new QLabel("Channel(s): ");

    m_title.setText("No Media Selected");
    m_artist.setText("No Media Selected");
    m_album.setText("No Media Selected");
    m_lossless.setText("No Media Selected");
    m_genre.setText("No Media Selected");;
    m_mood.setText("No Media Selected");
    m_year.setText("No Media Selected");;
    m_bitrate.setText("No Media Selected");
    m_samplerate.setText("No Media Selected");
    m_channelcount.setText("No Media Selected");

    layout->addWidget(titleLabel,0,0);
    layout->addWidget(&m_title,0,1);
    layout->addWidget(artistLabel,1,0);
    layout->addWidget(&m_artist,1,1);
    layout->addWidget(albumLabel,2,0);
    layout->addWidget(&m_album,2,1);
    layout->addWidget(losslessLabel,3,0);
    layout->addWidget(&m_lossless,3,1);
    layout->addWidget(genreLabel,4,0);
    layout->addWidget(&m_genre,4,1);
    layout->addWidget(moodLabel,5,0);
    layout->addWidget(&m_mood,5,1);
    layout->addWidget(yearLabel,6,0);
    layout->addWidget(&m_year,6,1);
    layout->addWidget(bitrateLabel,7,0);
    layout->addWidget(&m_bitrate,7,1);
    layout->addWidget(samplerateLabel,8,0);
    layout->addWidget(&m_samplerate,8,1);
    layout->addWidget(channelcountLabel,9,0);
    layout->addWidget(&m_channelcount,9,1);

    setLayout(layout);
}


void MediaPropertiesWidget::setController(Controller * c)
{
    ctrl=c;
}

void MediaPropertiesWidget::onUpdateProperties(const std::string& title, const std::string& artist, const std::string& album, bool lossless, const std::string& genre, const std::string& mood, unsigned int year, unsigned int bitrate, unsigned int samplerate, unsigned int channelcount)
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
         m_album.setText("No Album Available");
     else
         m_album.setText(album.c_str());

     if(lossless)
         m_lossless.setText("True");
     else
         m_lossless.setText("False");

     if(genre=="")
         m_genre.setText("No Genre Available");
     else
         m_genre.setText(genre.c_str());

     if(mood=="")
         m_mood.setText("No Mood Available");
     else
         m_mood.setText(mood.c_str());

     if(year==0)
         m_year.setText("No Year Available");
     else
         m_year.setText(QString::number(year));

     if(bitrate==0)
         m_bitrate.setText("No Bitrate Available");
     else
         m_bitrate.setText(QString::number(bitrate));

     if(samplerate==0)
         m_samplerate.setText("No Sample Rate Available");
     else
         m_samplerate.setText(QString::number(samplerate));

     if(channelcount==0)
         m_channelcount.setText("No Channel(s) Available");
     else
         m_channelcount.setText(QString::number(channelcount));
}

void MediaPropertiesWidget::onSetDefaultEvent()
{
    m_title.setText("No Media Selected");
    m_artist.setText("No Media Selected");
    m_album.setText("No Media Selected");
    m_lossless.setText("No Media Selected");
    m_genre.setText("No Media Selected");;
    m_mood.setText("No Media Selected");
    m_bitrate.setText("No Media Selected");
    m_samplerate.setText("No Media Selected");
    m_channelcount.setText("No Media Selected");
}
