#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMediaPlayer>
#include <QAudioProbe>
#include <QObject>
#include <QMediaMetaData>

#include <QComboBox>
#include <QAudioRecorder>

#include <fstream>

#include "Model/soundwave.h"
#include "Model/fft.h"
#include "Model/fftbars.h"
#include "Model/fftcircle.h"
#include "Model/overtimeFFT.h"
#include "Model/fileaudio.h"
#include "Model/mp3file.h"
#include "Model/wavfile.h"
#include "Model/opusfile.h"
#include "mediavector.h"

#include "exceptions.h"

class MainWindow;

class Controller : public QObject
{
Q_OBJECT

private:
    QMediaPlayer* m_QMediaPlayer;
    QAudioProbe* m_QAudioProbe;

    QMediaPlayer* auxMediaPlayer;

    SoundWave* m_soundWave;
    FFTBars* m_FFTBars;
    FFTCircle* m_FFTCircle;
    OvertimeFFT* m_OvertimeFFT;
    MainWindow* w;

    MediaVector m_mediaVector;

    int id;

    std::string helperFilePath;

public:
    Controller();
    qreal getPeakValue(const QAudioFormat& format);
    void setView(MainWindow*);

signals:
    void outOfRangeTimer();
    void formatNotValid();
    void replacePoints(std::vector<double>);
    void updateSoundWaveBufferSize(int);
    void sendHeights(std::vector<double>);
    void sendRadiuses(std::vector<double>);
    void sendBuffers(std::vector<double>, std::vector<std::vector<double>>);
    void pushUpdateList(std::string);
    void updateTitleInWidget(std::string);
    void updateImageInWidget(const QImage&);
    void updateCurrentRow(unsigned int);
    void updateOvertimeFFTAlphaBlending(float);
    void positionChanged(qint64);
    void updateProgSliderRange(int);
    void progSliderPositionChanged(qint64);
    void paletteChanged(float, float, float, float, float, float);
    void changeIncrementSpeed(float, float, float);
    void updateArtistInWidget(std::string);
    void fileDoesNotExist();
    void updateProperties(std::string, std::string, std::string, bool, std::string, std::string, unsigned int, unsigned int, unsigned int, unsigned int);
    void setDefault();
    void durationError();

public slots:
    void setMetaData(QMediaPlayer::MediaStatus);
    void onSendToMediaVector(const std::string&);
    void onSoundWaveRemapFactorSliderChanged(int);
    void onFFTBarsSensitivitySliderChanged(int);
    void onFFTBarsSmoothingAmtChanged(int);
    void onOvertimeFFTSmoothingAmtChanged(int);
    void onUpdateOvertimeFFTTimer(unsigned int);
    void onMediaListItemDoubleClicked(unsigned int);
    void onPlayButtonPressed();
    void onPauseButtonPressed();
    void onPrevButtonPressed(unsigned int);
    void onNextButtonPressed(unsigned int);
    void onOvertimeFFTAlphaBlendingChanged(int);
    void onVolumeChanged(int);
    void onRemoveMediaButtonPressed(unsigned int);
    void onSwapMediaButtonPressed(unsigned int);
    void onPaletteChanged(float,float,float,float,float,float);
    void onChangeIncrementSpeed(float, float, float);
    void onFFTCircleSensitivitySliderChanged(int);
    void onOvertimeFFTDynamicSmoothLimitChanged(int);
    void onDurationSliderMoved(qint64);

private slots:
    void processBuffer(const QAudioBuffer);
    void setId(int);

};

#endif // CONTROLLER_H
