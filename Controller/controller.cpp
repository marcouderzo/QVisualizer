#include "Controller/controller.h"
#include "View/mainwindow.h"

#include <QDebug>

Controller::Controller()
{    
    m_QMediaPlayer = new QMediaPlayer();
    m_QAudioProbe = new QAudioProbe();

    m_QMediaPlayer->setVolume(60);

    auxMediaPlayer = new QMediaPlayer();

    m_QAudioProbe->setSource(m_QMediaPlayer);

    connect(m_QAudioProbe, SIGNAL(audioBufferProbed(QAudioBuffer)), this, SLOT(processBuffer(QAudioBuffer)));

    connect(auxMediaPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(setMetaData(QMediaPlayer::MediaStatus)));

    connect(m_QMediaPlayer, SIGNAL(positionChanged(qint64)), this, SIGNAL(positionChanged(qint64)));
    connect(this, SIGNAL(progSliderPositionChanged(qint64)), this, SLOT(onDurationSliderMoved(qint64)));

    m_soundWave = new SoundWave();
    m_FFTBars = new FFTBars();
    m_FFTCircle = new FFTCircle();
    m_OvertimeFFT = new OvertimeFFT();

    id = -1;

    m_OvertimeFFT->setTimeStep(10);
}

void Controller::setId(int b)
{
    id = b;
}

void Controller::setView(MainWindow* wi)
{
    w = wi;
    connect(this, SIGNAL(replacePoints(std::vector<double>)), w, SIGNAL(replacePoints(std::vector<double>)));
    connect(this, SIGNAL(sendHeights(std::vector<double>)), w, SIGNAL(sendHeights(std::vector<double>)));
    connect(this, SIGNAL(sendRadiuses(std::vector<double>)), w, SIGNAL(sendRadiuses(std::vector<double>)));
    connect(this, SIGNAL(sendBuffers(std::vector<double>,  std::vector<std::vector<double>>)), w, SIGNAL(sendBuffers(std::vector<double>,  std::vector<std::vector<double>>)));
    connect(this, SIGNAL(pushUpdateList(std::string)), w, SLOT(onPushUpdateList(std::string)));
    connect(w, SIGNAL(sendToMediaVector(std::string)), this, SLOT(onSendToMediaVector(std::string)));
    connect(w, SIGNAL(updateOvertimeFFTTimer(unsigned int)), this, SLOT(onUpdateOvertimeFFTTimer(unsigned int)));
    connect(w, SIGNAL(selectedMediaItem(unsigned int)), this, SLOT(onMediaListItemDoubleClicked(unsigned int)));
    connect(this, SIGNAL(updateTitleInWidget(std::string)), w, SIGNAL(updateTitleInWidget(std::string)));
    connect(this, SIGNAL(updateImageInWidget(const QImage&)), w, SIGNAL(updateImageInWidget(const QImage&)));
    connect(this, SIGNAL(updateCurrentRow(unsigned int)), w, SLOT(onUpdateCurrentRow(unsigned int)));
    connect(this, SIGNAL(updateOvertimeFFTAlphaBlending(float)), w, SIGNAL(updateOvertimeFFTAlphaBlending(float)));
    connect(this, SIGNAL(changeIncrementSpeed(float, float, float)), w, SIGNAL(sendIncrementSpeed(float, float, float)));
    connect(w, SIGNAL(removeMedia(unsigned int)), this, SLOT(onRemoveMediaButtonPressed(unsigned int)));
    connect(w, SIGNAL(swapMedia(unsigned int)), this, SLOT(onSwapMediaButtonPressed(unsigned int)));
    connect(this, SIGNAL(updateProperties(std::string, std::string, std::string, bool, std::string, std::string, unsigned int, unsigned int, unsigned int, unsigned int)), w, SIGNAL(updateProperties(std::string, std::string, std::string, bool, std::string, std::string, unsigned int, unsigned int, unsigned int, unsigned int)));
}

//Credits: Qt examples: https://doc.qt.io/archives/qt-5.6/qtmultimedia-multimedia-audiorecorder-audiorecorder-cpp.html
qreal Controller::getPeakValue(const QAudioFormat &format)
{
    // Note: Only the most common sample formats are supported
    if (!format.isValid())
        return qreal(0);

    if (format.codec() != "audio/pcm")
        return qreal(0);

    switch (format.sampleType()) {
    case QAudioFormat::Unknown:
        break;
    case QAudioFormat::Float:
        if (format.sampleSize() != 32)
            return qreal(0);
        return qreal(1.00003);
    case QAudioFormat::SignedInt:
        if (format.sampleSize() == 32)
    #ifdef Q_OS_WIN
                return qreal(INT_MAX);
    #endif
    #ifdef Q_OS_UNIX
                return qreal(SHRT_MAX);
    #endif
        if (format.sampleSize() == 16)
            return qreal(SHRT_MAX);
        if (format.sampleSize() == 8)
            return qreal(CHAR_MAX);
        break;
    case QAudioFormat::UnSignedInt:
        if (format.sampleSize() == 32)
            return qreal(UINT_MAX);
        if (format.sampleSize() == 16)
            return qreal(USHRT_MAX);
        if (format.sampleSize() == 8)
            return qreal(UCHAR_MAX);
        break;
    }

    return qreal(0);
}

void Controller::processBuffer(const QAudioBuffer buffer)
{
    const qint16* data = buffer.data<qint16>();
    std::complex<double> aux[buffer.sampleCount()];
    for(int i=0; i<buffer.sampleCount(); i++)
    {
        qreal y = data[i]/getPeakValue(buffer.format());
        aux[i]=std::complex<double>(y);
    }

    if(id == 0)
    {
        std::vector<double> vect = m_soundWave->run(aux, static_cast<unsigned int>(buffer.sampleCount()), 4096, 1);
        emit updateSoundWaveBufferSize(buffer.sampleCount());
        emit replacePoints(vect);
    }

    if(id == 1)
    {
        std::vector<double> vect=m_FFTBars->run(aux, static_cast<unsigned int>(buffer.sampleCount()), 4096,1);
        emit sendHeights(vect);
    }

    if(id == 2)
    {
        std::vector<double> vect=m_FFTCircle->run(aux, static_cast<unsigned int>(buffer.sampleCount()), 4096,1);
        emit sendRadiuses(vect);
    }

    if(id == 3)
    {
       std::vector<double> vect=m_OvertimeFFT->run(aux,static_cast<unsigned int>(buffer.sampleCount()), 4096,1);
       std::vector<std::vector<double>> b = m_OvertimeFFT->getTimeBuffer();
       emit sendBuffers(vect, b);
    }
}

void Controller::setMetaData(QMediaPlayer::MediaStatus status)
{
    if(status==QMediaPlayer::LoadedMedia)
    {
        FileAudio* file;
        if(helperFilePath.find(".mp3")!= std::string::npos)
            file= new MP3File(helperFilePath);
        else if(helperFilePath.find(".wav")!= std::string::npos)
            file=new WAVFile(helperFilePath);
        else if(helperFilePath.find(".opus")!= std::string::npos)
            file=new OPUSFile(helperFilePath);
        else{
            emit formatNotValid();
            return;
        }


        //C:/Users/marco/Downloads/Mike Perry  The Ocean ft Shy Martin Official Video.mp3
        //C:/Users/marco/Downloads/Florence and the Machine - Jenny of Oldstones.mp3
        //C:/Users/marco/Downloads/Florence and The Machine - Jenny of Oldstones.opus
        //C:/Users/marco/Downloads/Bob Dylan - Knockin' On Heaven's Door.wav

        int i=0;
        if(m_mediaVector.getSize()!=0)
        {
            qDebug()<<m_mediaVector.getSize();
            for(MediaVector<FileAudio*>::ConstIterator it = m_mediaVector.begin(); it != ++m_mediaVector.end(); ++it)
            {
                qDebug()<<"i'm iterating a bit" << i;
                //qDebug()<< "title:"<<QString(it->getTitle().c_str())<<"album:" << QString(it->getAlbum().c_str());
                if(*(*it) == *file){
                    qDebug()<<"Hey that's a clonyclony";
                    FileAudio* auxFile = (*it)->clone();
                    m_mediaVector.push(&auxFile);
                    helperFilePath.empty();
                    emit pushUpdateList((*it)->getTitle());
                    qDebug()<<"I cloned it!";
                    return;
                }
                qDebug()<<"after if";
                i++;
            }
        }

        const QStringList availableMetaData = auxMediaPlayer->availableMetaData();
        qDebug()<<availableMetaData;

        try
        {
            file->setDuration(auxMediaPlayer->duration());
        }
        catch(Exceptions::OutOfRangeDuration)
        {
            emit durationError();
            return;
        }

        if(MP3File* cFile = dynamic_cast<MP3File*>(file))
        {
            for(auto el : availableMetaData)
            {
                if(el==QMediaMetaData::Title)
                    file->setTitle(auxMediaPlayer->metaData(QMediaMetaData::Title).toString().toStdString());

                if(el==QMediaMetaData::Author)
                        cFile->setArtist(auxMediaPlayer->metaData(QMediaMetaData::Author).toString().toStdString());

                if(el==QMediaMetaData::AlbumTitle)
                        cFile->setAlbum(auxMediaPlayer->metaData(QMediaMetaData::AlbumTitle).toString().toStdString());

                if(el==QMediaMetaData::ThumbnailImage)
                        cFile->setCoverArt(auxMediaPlayer->metaData(QMediaMetaData::ThumbnailImage).value<QImage>());

                if(el==QMediaMetaData::Genre)
                        cFile->setGenre(auxMediaPlayer->metaData(QMediaMetaData::Genre).toString().toStdString());

                if(el==QMediaMetaData::Mood)
                        cFile->setMood(auxMediaPlayer->metaData(QMediaMetaData::Mood).toString().toStdString());

                if(el==QMediaMetaData::Year)
                        cFile->setYear(auxMediaPlayer->metaData(QMediaMetaData::Year).toUInt());

                if(el==QMediaMetaData::AudioBitRate)
                        cFile->setBitrate(auxMediaPlayer->metaData(QMediaMetaData::AudioBitRate).toUInt());

                if(el==QMediaMetaData::SampleRate)
                        cFile->setSampleRate(auxMediaPlayer->metaData(QMediaMetaData::SampleRate).toUInt());

                if(el==QMediaMetaData::ChannelCount)
                        cFile->setChannelCount(auxMediaPlayer->metaData(QMediaMetaData::ChannelCount).toUInt());
            }
        }

        else if(WAVFile* cFile = dynamic_cast<WAVFile*>(file))
        {
            for(auto el : availableMetaData)
            {
                if(el==QMediaMetaData::Title)
                    file->setTitle(auxMediaPlayer->metaData(QMediaMetaData::Title).toString().toStdString());

                if(el==QMediaMetaData::Author)
                        cFile->setArtist(auxMediaPlayer->metaData(QMediaMetaData::Author).toString().toStdString());

                if(el==QMediaMetaData::AlbumTitle)
                        cFile->setAlbum(auxMediaPlayer->metaData(QMediaMetaData::AlbumTitle).toString().toStdString());

                if(el==QMediaMetaData::Genre)
                        cFile->setGenre(auxMediaPlayer->metaData(QMediaMetaData::Genre).toString().toStdString());

                if(el==QMediaMetaData::Year)
                        cFile->setYear(auxMediaPlayer->metaData(QMediaMetaData::Year).toUInt());

                if(el==QMediaMetaData::AudioBitRate)
                        cFile->setBitrate(auxMediaPlayer->metaData(QMediaMetaData::AudioBitRate).toUInt());

                if(el==QMediaMetaData::SampleRate)
                        cFile->setSampleRate(auxMediaPlayer->metaData(QMediaMetaData::SampleRate).toUInt());

                if(el==QMediaMetaData::ChannelCount)
                        cFile->setChannelCount(auxMediaPlayer->metaData(QMediaMetaData::ChannelCount).toUInt());
            }
        }

        else if(OPUSFile* cFile =dynamic_cast<OPUSFile*>(file))
        {
            for(auto el : availableMetaData)
            {
                if(el==QMediaMetaData::SampleRate)
                        cFile->setSampleRate(auxMediaPlayer->metaData(QMediaMetaData::SampleRate).toUInt());

                if(el==QMediaMetaData::ChannelCount)
                        cFile->setChannelCount(auxMediaPlayer->metaData(QMediaMetaData::ChannelCount).toUInt());
            }
        }

        if(file->getTitle()=="")
        {
            auto slashpos = helperFilePath.find_last_of('/');
            auto dotpos = helperFilePath.find_last_of('.');
            file->setTitle(helperFilePath.substr(slashpos+1, dotpos-slashpos-1));
        }

        helperFilePath.empty();

        m_mediaVector.push(&file);
        emit pushUpdateList(file->getTitle());
    }
}

void Controller::onSendToMediaVector(const std::string& s)
{
    std::ifstream file(s.c_str());

    if(file.fail())
    {
        emit fileDoesNotExist();
        return;
    }

    auxMediaPlayer->setMedia(QUrl::fromLocalFile(QString::fromUtf8(s.c_str())));
    helperFilePath = s;
}

void Controller::onSoundWaveRemapFactorSliderChanged(int amt)
{
    m_soundWave->setRemapFactor(amt);
}

void Controller::onFFTBarsSensitivitySliderChanged(int amt)
{
    m_FFTBars->setSensitivity(amt);
}

void Controller::onFFTBarsSmoothingAmtChanged(int amt)
{
    m_FFTBars->setSmoothing(amt);
}

void Controller::onOvertimeFFTSmoothingAmtChanged(int id)
{
    m_OvertimeFFT->setSmoothing(id);
}

void Controller::onUpdateOvertimeFFTTimer(unsigned int ms)
{
   try
   {
        m_OvertimeFFT->setTimeStep(ms);
   }
   catch(Exceptions::OutOfRangeTimerValue)
   {
        emit outOfRangeTimer();
   }
}

void Controller::onMediaListItemDoubleClicked(unsigned int index)
{
   FileAudio* file = m_mediaVector[index];
   m_QMediaPlayer->setMedia(QUrl::fromLocalFile(QString::fromUtf8(file->getFilePath().c_str())));

   emit updateTitleInWidget(file->getTitle());

   if(MP3File* cFile = dynamic_cast<MP3File*>(file))
       emit updateArtistInWidget(cFile->getArtist());
   else if(WAVFile* cFile = dynamic_cast<WAVFile*>(file))
       emit updateArtistInWidget(cFile->getArtist());
   else
       emit updateArtistInWidget("");

   if(MP3File* cFile = dynamic_cast<MP3File*>(file))
       emit updateImageInWidget(cFile->getCoverArt());
   else
       emit updateImageInWidget(QImage(nullptr));


   emit updateProgSliderRange(static_cast<int>(file->getDuration()));

   if(MP3File* cFile = dynamic_cast<MP3File*>(file))
       emit updateProperties(cFile->getTitle(),
                             cFile->getArtist(),
                             cFile->getAlbum(),
                             cFile->isLossless(),
                             cFile->getGenre(),
                             cFile->getMood(),
                             cFile->getYear(),
                             cFile->getBitrate(),
                             cFile->getSampleRate(),
                             cFile->getChannelCount());

   else if(WAVFile* cFile = dynamic_cast<WAVFile*>(file))
       emit updateProperties(cFile->getTitle(),
                             cFile->getArtist(),
                             cFile->getAlbum(),
                             cFile->isLossless(),
                             cFile->getGenre(),
                             "",
                             cFile->getYear(),
                             cFile->getBitrate(),
                             cFile->getSampleRate(),
                             cFile->getChannelCount());

   else if(OPUSFile* cFile = dynamic_cast<OPUSFile*>(file))
       emit updateProperties(cFile->getTitle(),
                             "",
                             "",
                             cFile->isLossless(),
                             "",
                             "",
                             0,
                             0,
                             cFile->getSampleRate(),
                             cFile->getChannelCount());
}

void Controller::onPlayButtonPressed()
{
    m_QMediaPlayer->play();
}

void Controller::onPauseButtonPressed()
{
    m_QMediaPlayer->pause();
}

void Controller::onPrevButtonPressed(unsigned int current)
{
    m_QMediaPlayer->stop();

    if(m_mediaVector.getSize() == 0) return;
    if(current==0) return;

    FileAudio* file = m_mediaVector[current-1];

    m_QMediaPlayer->setMedia(QUrl::fromLocalFile(QString::fromUtf8(file->getFilePath().c_str())));
    emit updateTitleInWidget(file->getTitle());

    if(MP3File* cFile = dynamic_cast<MP3File*>(file))
        emit updateImageInWidget(cFile->getCoverArt());
    else
        emit updateImageInWidget(QImage(nullptr));

    emit updateProgSliderRange(static_cast<int>(file->getDuration()));
    emit updateCurrentRow(current-1);

    m_QMediaPlayer->play();
}

void Controller::onNextButtonPressed(unsigned int current)
{
    m_QMediaPlayer->stop();

    if(m_mediaVector.getSize() == 0) return;
    if(current == m_mediaVector.getSize()-1) return;

    FileAudio* file = m_mediaVector[current+1];

    m_QMediaPlayer->setMedia(QUrl::fromLocalFile(QString::fromUtf8(file->getFilePath().c_str())));
    emit updateTitleInWidget(file->getTitle());

    if(MP3File* cFile =dynamic_cast<MP3File*>(file))
        emit updateImageInWidget(cFile->getCoverArt());
    else
        emit updateImageInWidget(QImage(nullptr));

    emit updateProgSliderRange(static_cast<int>(file->getDuration()));
    emit updateCurrentRow(current+1);

    m_QMediaPlayer->play();
}

void Controller::onOvertimeFFTAlphaBlendingChanged(int amt)
{
    emit updateOvertimeFFTAlphaBlending(amt/100.0f);
}

void Controller::onVolumeChanged(int volume)
{
    m_QMediaPlayer->setVolume(volume);
}

void Controller::onRemoveMediaButtonPressed(unsigned int index)
{
    if(m_mediaVector.getSize() == 0 ) return;

    std::string aux = m_QMediaPlayer->currentMedia().canonicalUrl().toString().toStdString();

    #ifdef Q_OS_WIN
        aux.erase(0, 8);
    #endif

    #ifdef Q_OS_UNIX
        aux.erase(0, 7);
    #endif

    if(aux == m_mediaVector[index]->getFilePath())
    {
        m_QMediaPlayer->stop();
        m_QMediaPlayer->setMedia(nullptr);
        emit setDefault();
    }

    m_mediaVector.pop(index);
}

void Controller::onSwapMediaButtonPressed(unsigned int index)
{
    m_mediaVector.swap(index, index+1);
}

void Controller::onPaletteChanged(float rs, float gs, float bs, float re, float ge, float be)
{
    emit paletteChanged(rs/100.0f, gs/100.0f, bs/100.0f, re/100.0f, ge/100.0f, be/100.0f);
}

void Controller::onChangeIncrementSpeed(float r_increment, float g_increment, float b_increment)
{
    if(r_increment < 0.0f || r_increment > 1.0f) r_increment= 0.01f;
    if(g_increment < 0.0f || g_increment > 1.0f) g_increment= 0.01f;
    if(b_increment < 0.0f || b_increment > 1.0f) b_increment= 0.01f;

    emit changeIncrementSpeed(r_increment, g_increment, b_increment);
}

void Controller::onFFTCircleSensitivitySliderChanged(int amt)
{
    m_FFTCircle->setSensitivity(amt);
}

void Controller::onOvertimeFFTDynamicSmoothLimitChanged(int amt)
{
    m_OvertimeFFT->setSmoothLimit(static_cast<unsigned int>(amt));
}

void Controller::onDurationSliderMoved(qint64 s)
{
    m_QMediaPlayer->setPosition(s*1000);
}

