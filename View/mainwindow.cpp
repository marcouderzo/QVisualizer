#include "View/mainwindow.h"
#include "Controller/controller.h"

MainWindow::MainWindow(QWidget *parent)
{
    m_soundWaveWidget = new SoundWaveWidget();
    m_soundWaveWidget->setMinimumSize(QSize(400,300));

    m_FFTBarsWidget=new FFTBarsWidget();
    m_FFTBarsWidget->setMinimumSize(QSize(400,300));

    m_FFTCircleWidget = new FFTCircleWidget();
    m_FFTCircleWidget->setMinimumSize(QSize(400,300));

    m_OvertimeFFTWidget = new OvertimeFFTWidget();
    m_OvertimeFFTWidget->setMinimumSize(QSize(400,300));

    m_MetaDataWidget = new MetaDataWidget();
    m_MetaDataWidget->setMinimumSize(QSize(400,200));


    m_FileManagerWidget = new FileManagerWidget();
    m_FileManagerWidget->setController(c);

    m_MediaPropertiesWidget = new MediaPropertiesWidget();
    m_MediaPropertiesWidget->setController(c);
    m_MediaPropertiesWidget->hide();

    groupBox = new QGroupBox();

    setupButton = new QPushButton("Use SoundCard Input");

    SoundWaveButton = new QRadioButton("SoundWave");
    FFTBarsButton = new QRadioButton("FFTBars");
    FFTCircleButton = new QRadioButton("FFTCircle");
    OvertimeFFTButton = new QRadioButton("OvertimeFFT");

    mediaList = new QListWidget();

    //buttons
    fileManagerButton=new QPushButton("Manage Files");
    playButton=new QPushButton("Play");
    playButton->setIcon(QIcon(":resources/resources/playIcon.png"));
    pauseButton=new QPushButton("Pause");
    pauseButton->setIcon(QIcon(":resources/resources/pauseIcon.png"));
    nextButton=new QPushButton("Next");
    nextButton->setIcon(QIcon(":resources/resources/nextIcon.png"));
    prevButton=new QPushButton("Prev");
    prevButton->setIcon(QIcon(":resources/resources/previousIcon.png"));
    progSlider=new QSlider(Qt::Horizontal);
    progSlider->setRange(0, 200);
    volumeSlider=new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0,100);
    volumeSlider->setSliderPosition(60);

    swapButton = new QPushButton("Swap Selected With Next");
    removeButton = new QPushButton("Remove Selected From List");
    propertiesButton = new QPushButton("Show Current Item's MetaData ");

    // MainWindow Labels

    QLabel* durationSliderLabel = new QLabel("Duration");
    QLabel* volumeSliderLabel = new QLabel("Volume");

    QLabel* SWRemapFactorSliderLabel= new QLabel("Remap Factor");

    QLabel* FFTBSensitivitySliderLabel= new QLabel("Sensitivity");
    QLabel* FFTBSmoothingAmtSliderLabel= new QLabel("Smoothing Amount");

    QLabel* FFTCSensitivitySliderLabel= new QLabel("Sensitivity");
    QLabel* FFTCSmoothingAmtSliderLabel= new QLabel("Smoothing Amount");

    QLabel* OTFFTSmoothingAmtLabel= new QLabel("Smoothing Type");
    QLabel* OTFFTUpdateFrequencyLabel= new QLabel("Update Terrain Samples Every (10-100) ms");
    QLabel* OTFFTDynamicTimeSmoothingSliderLabel = new QLabel("Keep Smoothing (DynamicFade only)");
    QLabel* OTFFTAlphaBlendingSliderLabel = new QLabel("Alpha Blending");

    QLabel* OTFFTRGBStartSlidersLabel = new QLabel("Gradient Start Color (Red-Green-Blue)");
    QLabel* OTFFTRGBEndSlidersLabel = new QLabel("Gradient End Color (Red-Green-Blue)");
    QLabel* r_start_label = new QLabel("R ");
    QLabel* g_start_label = new QLabel(" G ");
    QLabel* b_start_label = new QLabel(" B ");

    QLabel* r_end_label = new QLabel("R ");
    QLabel* g_end_label = new QLabel(" G ");
    QLabel* b_end_label = new QLabel(" B ");
    QLabel* increment_label = new QLabel("[R][G][B] Increment Factor (0.01 - 1.0)");

    soundWaveRemapFactorSlider= new QSlider(Qt::Horizontal);
    soundWaveRemapFactorSlider->setRange(1,10);
    soundWaveRemapFactorSlider->setValue(6);
    soundWaveSettingsLayout = new QVBoxLayout();
    soundWaveSettingsPlaceHolder = new QWidget();
    soundWaveSettingsLayout->addWidget(SWRemapFactorSliderLabel);
    soundWaveSettingsLayout->addWidget(soundWaveRemapFactorSlider);
    soundWaveSettingsPlaceHolder->setLayout(soundWaveSettingsLayout);
    soundWaveSettingsPlaceHolder->hide();

    FFTBarsSensitivitySlider = new QSlider(Qt::Horizontal);
    FFTBarsSensitivitySlider->setInvertedAppearance(true);
    FFTBarsSensitivitySlider->setRange(160,900);
    FFTBarsSensitivitySlider->setValue(350);

    FFTBarsSettingsPlaceHolder = new QWidget();
    FFTBarsSettingsLayout = new QVBoxLayout();
    FFTBarsSmoothingGroup = new QButtonGroup();
    FFTBarsStandardSmoothing = new QRadioButton("Standard");
    FFTBarsEnhancedSmoothing = new QRadioButton("Enhanced");
    FFTBarsSmoothingGroup->addButton(FFTBarsStandardSmoothing);
    FFTBarsSmoothingGroup->addButton(FFTBarsEnhancedSmoothing);
    FFTBarsSmoothingGroup->setId(FFTBarsStandardSmoothing, 1);
    FFTBarsSmoothingGroup->setId(FFTBarsEnhancedSmoothing, 2);
    FFTBarsStandardSmoothing->setChecked(true);

    FFTBarsSettingsLayout->addWidget(FFTBSensitivitySliderLabel);
    FFTBarsSettingsLayout->addWidget(FFTBarsSensitivitySlider);
    FFTBarsSettingsLayout->addWidget(FFTBSmoothingAmtSliderLabel);
    FFTBarsSettingsLayout->addWidget(FFTBarsStandardSmoothing);
    FFTBarsSettingsLayout->addWidget(FFTBarsEnhancedSmoothing);
    FFTBarsSettingsPlaceHolder->setLayout(FFTBarsSettingsLayout);
    FFTBarsSettingsPlaceHolder->hide();

    FFTCircleSensitivitySlider = new QSlider(Qt::Horizontal);
    FFTCircleSensitivitySlider->setRange(120,600);
    FFTCircleSensitivitySlider->setValue(300);
    FFTCircleSensitivitySlider->setInvertedAppearance(true);

    FFTCircleSettingsPlaceHolder = new QWidget();
    FFTCircleSettingsLayout= new QVBoxLayout();
    FFTCircleSettingsLayout->addWidget(FFTCSensitivitySliderLabel);
    FFTCircleSettingsLayout->addWidget(FFTCircleSensitivitySlider);
    FFTCircleSettingsLayout->addWidget(FFTCSmoothingAmtSliderLabel);
    FFTCircleSettingsPlaceHolder->setLayout(FFTCircleSettingsLayout);
    FFTCircleSettingsPlaceHolder->hide();

    OvertimeFFTSmoothingGroup=new QButtonGroup();
    OvertimeFFTNoTimeSmoothing=new QRadioButton("No Time Smoothing");
    OvertimeFFTStandardTimeSmoothing=new QRadioButton("Standard Time Smoothing");
    OvertimeFFTDynamicFadeTimeSmoothing= new QRadioButton("DynamicFade Time Smoothing");
    OvertimeFFTDynamicSmoothLimitSlider = new QSlider(Qt::Horizontal);
    OvertimeFFTDynamicSmoothLimitSlider->setRange(0, 90);
    OvertimeFFTDynamicSmoothLimitSlider->setValue(60);
    OvertimeFFTDynamicSmoothLimitSlider->setInvertedAppearance(true);
    OvertimeFFTSmoothingGroup->addButton(OvertimeFFTNoTimeSmoothing);
    OvertimeFFTSmoothingGroup->addButton(OvertimeFFTStandardTimeSmoothing);
    OvertimeFFTSmoothingGroup->addButton(OvertimeFFTDynamicFadeTimeSmoothing);
    OvertimeFFTSmoothingGroup->setId(OvertimeFFTStandardTimeSmoothing, 0);
    OvertimeFFTSmoothingGroup->setId(OvertimeFFTStandardTimeSmoothing, 1);
    OvertimeFFTSmoothingGroup->setId(OvertimeFFTDynamicFadeTimeSmoothing, 2);
    OvertimeFFTNoTimeSmoothing->setChecked(true);

    OvertimeFFTAlphaBlendingSlider = new QSlider(Qt::Horizontal);
    OvertimeFFTAlphaBlendingSlider->setRange(10, 30);
    OvertimeFFTAlphaBlendingSlider->setValue(20);

    OvertimeFFTUpdateFrequencyEditor= new QLineEdit();
    OvertimeFFTSettingsPlaceHolder = new QWidget();

    startRedValueEdit = new QSlider(Qt::Horizontal);
    startRedValueEdit->setRange(0,100);
    startGreenValueEdit = new QSlider(Qt::Horizontal);
    startGreenValueEdit->setRange(0,100);
    startBlueValueEdit = new QSlider(Qt::Horizontal);
    startBlueValueEdit->setRange(0,100);

    endRedValueEdit = new QSlider(Qt::Horizontal);
    endRedValueEdit->setRange(0,100);
    endGreenValueEdit = new QSlider(Qt::Horizontal);
    endGreenValueEdit->setRange(0,100);
    endBlueValueEdit = new QSlider(Qt::Horizontal);
    endBlueValueEdit->setRange(0,100);

    redIncrementSpeedEdit = new QLineEdit();
    redIncrementSpeedEdit->setText("0.01");
    greenIncrementSpeedEdit = new QLineEdit();
    greenIncrementSpeedEdit->setText("0.01");
    blueIncrementSpeedEdit = new QLineEdit();
    blueIncrementSpeedEdit->setText("0.01");

    rgbIncrementLayout=new QHBoxLayout();
    rgbIncrementLayout->addWidget(redIncrementSpeedEdit);
    rgbIncrementLayout->addWidget(greenIncrementSpeedEdit);
    rgbIncrementLayout->addWidget(blueIncrementSpeedEdit);

    rgbStartGradientLayout = new QHBoxLayout();
    rgbStartGradientLayout->addWidget(r_start_label);
    rgbStartGradientLayout->addWidget(startRedValueEdit);
    rgbStartGradientLayout->addWidget(g_start_label);
    rgbStartGradientLayout->addWidget(startGreenValueEdit);
    rgbStartGradientLayout->addWidget(b_start_label);
    rgbStartGradientLayout->addWidget(startBlueValueEdit);

    rgbEndGradientLayout = new QHBoxLayout();
    rgbEndGradientLayout->addWidget(r_end_label);
    rgbEndGradientLayout->addWidget(endRedValueEdit);
    rgbEndGradientLayout->addWidget(g_end_label);
    rgbEndGradientLayout->addWidget(endGreenValueEdit);
    rgbEndGradientLayout->addWidget(b_end_label);
    rgbEndGradientLayout->addWidget(endBlueValueEdit);

    QPushButton* applyRGBIncrementButton = new QPushButton("Apply RGB Increment Factor");

    OvertimeFFTSettingsLayout = new QVBoxLayout();
    OvertimeFFTSettingsLayout->addWidget(OTFFTSmoothingAmtLabel);
    OvertimeFFTSettingsLayout->addWidget(OvertimeFFTNoTimeSmoothing);
    OvertimeFFTSettingsLayout->addWidget(OvertimeFFTStandardTimeSmoothing);
    OvertimeFFTSettingsLayout->addWidget(OvertimeFFTDynamicFadeTimeSmoothing);
    OvertimeFFTSettingsLayout->addWidget(OTFFTDynamicTimeSmoothingSliderLabel);
    OvertimeFFTSettingsLayout->addWidget(OvertimeFFTDynamicSmoothLimitSlider);
    OvertimeFFTSettingsLayout->addWidget(OTFFTAlphaBlendingSliderLabel);
    OvertimeFFTSettingsLayout->addWidget(OvertimeFFTAlphaBlendingSlider);
    OvertimeFFTSettingsLayout->addWidget(OTFFTRGBStartSlidersLabel);
    OvertimeFFTSettingsLayout->addItem(rgbStartGradientLayout);
    OvertimeFFTSettingsLayout->addWidget(OTFFTRGBEndSlidersLabel);
    OvertimeFFTSettingsLayout->addItem(rgbEndGradientLayout);
    OvertimeFFTSettingsLayout->addWidget(increment_label);
    OvertimeFFTSettingsLayout->addItem(rgbIncrementLayout);
    OvertimeFFTSettingsLayout->addWidget(applyRGBIncrementButton);
    OvertimeFFTSettingsLayout->addWidget(OTFFTUpdateFrequencyLabel);
    OvertimeFFTSettingsLayout->addWidget(OvertimeFFTUpdateFrequencyEditor);
    OvertimeFFTSettingsPlaceHolder->setLayout(OvertimeFFTSettingsLayout);
    OvertimeFFTSettingsPlaceHolder->hide();

    buttonGroup = new QButtonGroup();

    buttonGroup-> addButton(SoundWaveButton);
    buttonGroup-> addButton(FFTBarsButton);
    buttonGroup-> addButton(FFTCircleButton);
    buttonGroup-> addButton(OvertimeFFTButton);

    buttonGroup-> setId(SoundWaveButton, 0);
    buttonGroup-> setId(FFTBarsButton, 1);
    buttonGroup-> setId(FFTCircleButton, 2);
    buttonGroup-> setId(OvertimeFFTButton, 3);


    stackedGLWidget=new QStackedWidget();
    stackedGLWidget->setMinimumSize(QSize(400,300));

    stackedGLWidget->addWidget(m_soundWaveWidget);
    stackedGLWidget->addWidget(m_FFTBarsWidget);
    stackedGLWidget->addWidget(m_FFTCircleWidget);
    stackedGLWidget->addWidget(m_OvertimeFFTWidget);

    graphicsLayout=new QVBoxLayout();
    graphicsLayout->setSpacing(1);

    graphicsLayout->addWidget(stackedGLWidget);
    graphicsLayout->addWidget(m_MetaDataWidget);

    playerButtonsLayout = new QHBoxLayout();

    playerButtonsLayout->addWidget(playButton);
    playerButtonsLayout->addWidget(pauseButton);
    playerButtonsLayout->addWidget(prevButton);
    playerButtonsLayout->addWidget(nextButton);

    controlsLayout = new QVBoxLayout();

    controlsLayout->addWidget(fileManagerButton);
    controlsLayout->addWidget(setupButton);
    controlsLayout->addLayout(playerButtonsLayout);
    controlsLayout->addWidget(durationSliderLabel);
    controlsLayout->addWidget(progSlider);
    controlsLayout->addWidget(volumeSliderLabel);
    controlsLayout->addWidget(volumeSlider);
    controlsLayout->addWidget(swapButton);
    controlsLayout->addWidget(removeButton);
    controlsLayout->addWidget(propertiesButton);
    controlsLayout->addWidget(mediaList);
    controlsLayout->addWidget(SoundWaveButton);
    controlsLayout->addWidget(soundWaveSettingsPlaceHolder);
    controlsLayout->addWidget(FFTBarsButton);
    controlsLayout->addWidget(FFTBarsSettingsPlaceHolder);
    controlsLayout->addWidget(FFTCircleButton);
    controlsLayout->addWidget(FFTCircleSettingsPlaceHolder);
    controlsLayout->addWidget(OvertimeFFTButton);
    controlsLayout->addWidget(OvertimeFFTSettingsPlaceHolder);

    controlsLayoutPlaceHolder = new QWidget();
    controlsLayoutPlaceHolder->setLayout(controlsLayout);
    controlsLayoutPlaceHolder->setMinimumWidth(100);
    controlsLayoutPlaceHolder->setMaximumWidth(350);

    mainLayout=new QHBoxLayout();
    mainLayout->addLayout(graphicsLayout);
    mainLayout->addWidget(controlsLayoutPlaceHolder);

    setLayout(mainLayout);

    connect(fileManagerButton, SIGNAL(clicked()), m_FileManagerWidget, SLOT(show()));
    connect(SoundWaveButton, SIGNAL(toggled(bool)), this, SLOT(onSoundWaveButtonClicked(bool)));
    connect(SoundWaveButton, SIGNAL(toggled(bool)), this, SLOT(identifyButton()));
    connect(FFTBarsButton, SIGNAL(toggled(bool)), this, SLOT(onFFTBarsButtonClicked(bool)));
    connect(FFTBarsButton, SIGNAL(toggled(bool)), this, SLOT(identifyButton()));
    connect(FFTCircleButton, SIGNAL(toggled(bool)), this, SLOT(onFFTCircleButtonClicked(bool)));
    connect(FFTCircleButton, SIGNAL(toggled(bool)), this, SLOT(identifyButton()));
    connect(OvertimeFFTButton, SIGNAL(toggled(bool)), this, SLOT(onOvertimeFFTButtonClicked(bool)));
    connect(OvertimeFFTButton, SIGNAL(toggled(bool)), this, SLOT(identifyButton()));

    connect(this, SIGNAL(replacePoints(std::vector<double>)), m_soundWaveWidget, SLOT(onSendWaveEvent(const std::vector<double>&)));
    connect(this, SIGNAL(sendHeights(std::vector<double>)), m_FFTBarsWidget, SLOT(onSendHeightsEvent(const std::vector<double>&)));
    connect(this, SIGNAL(sendRadiuses(std::vector<double>)), m_FFTCircleWidget, SLOT(onSendRadiusesEvent(const std::vector<double>&)));
    connect(this, SIGNAL(sendBuffers(std::vector<double>,  std::vector<std::vector<double>>)), m_OvertimeFFTWidget, SLOT(onSendBuffersEvent(const std::vector<double>&,  const std::vector<std::vector<double>>&)));
    connect(m_FileManagerWidget, SIGNAL(sendToMediaVector(std::string)), this, SIGNAL(sendToMediaVector(std::string)));


    connect(propertiesButton, SIGNAL(clicked()), this, SLOT(onPropertiesButtonClicked()));
    connect(this, SIGNAL(updateProperties(std::string, std::string, std::string, bool)), m_MediaPropertiesWidget, SLOT(onUpdateProperties(const std::string&, const std::string&,const std::string&, bool)));

    connect(this, SIGNAL(updateTitleInWidget(std::string)), m_MetaDataWidget, SLOT(onUpdateTitleInWidget(const std::string&)));
    connect(this, SIGNAL(updateImageInWidget(const QImage&)), m_MetaDataWidget, SLOT(onUpdateImageInWidget(const QImage&)));

    connect(this,SIGNAL(updateOvertimeFFTAlphaBlending(float)), m_OvertimeFFTWidget, SLOT(onUpdateAlphaBlending(float)));

    connect(mediaList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onItemDoubleClicked(QListWidgetItem*)));

    connect(FFTBarsStandardSmoothing, SIGNAL(toggled(bool)), this, SLOT(identifyFFTBarsSmoothing()));
    connect(FFTBarsEnhancedSmoothing, SIGNAL(toggled(bool)), this, SLOT(identifyFFTBarsSmoothing()));

    connect(OvertimeFFTNoTimeSmoothing, SIGNAL(toggled(bool)), this, SLOT(identifyOvertimeFFTSmoothing()));
    connect(OvertimeFFTStandardTimeSmoothing, SIGNAL(toggled(bool)), this, SLOT(identifyOvertimeFFTSmoothing()));
    connect(OvertimeFFTDynamicFadeTimeSmoothing, SIGNAL(toggled(bool)), this, SLOT(identifyOvertimeFFTSmoothing()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(onRemoveButtonPressed()));
    connect(swapButton, SIGNAL(clicked()), this, SLOT(onSwapMediaButtonPressed()));
    connect(applyRGBIncrementButton, SIGNAL(clicked()), this, SLOT(onApplyRGBIncrementButtonClicked()));
    connect(startRedValueEdit, SIGNAL(valueChanged(int)), this, SLOT(onPaletteSliderMoved()));
    connect(startGreenValueEdit, SIGNAL(valueChanged(int)), this, SLOT(onPaletteSliderMoved()));
    connect(startBlueValueEdit, SIGNAL(valueChanged(int)), this, SLOT(onPaletteSliderMoved()));
    connect(endRedValueEdit, SIGNAL(valueChanged(int)), this, SLOT(onPaletteSliderMoved()));
    connect(endGreenValueEdit, SIGNAL(valueChanged(int)), this, SLOT(onPaletteSliderMoved()));
    connect(endBlueValueEdit, SIGNAL(valueChanged(int)), this, SLOT(onPaletteSliderMoved()));


}

void MainWindow::identifyButton()
{
    idchecked = buttonGroup-> checkedId();
    emit widgetSelected(idchecked);
}

void MainWindow::setController(Controller* ctrl)
{
    c = ctrl;
    connect(setupButton, SIGNAL(pressed()), c, SLOT(onSetupButtonPressed()));
    connect(this, SIGNAL(widgetSelected(int)), c, SLOT(setId(int)));
    connect(soundWaveRemapFactorSlider, SIGNAL(valueChanged(int)), c, SLOT(onSoundWaveRemapFactorSliderChanged(int)));

    connect(FFTBarsSensitivitySlider, SIGNAL(valueChanged(int)), c, SLOT(onFFTBarsSensitivitySliderChanged(int)));
    connect(this, SIGNAL(sendFFTBarsSmoothing(int)), c, SLOT(onFFTBarsSmoothingAmtChanged(int)));

    connect(FFTCircleSensitivitySlider, SIGNAL(valueChanged(int)), c, SLOT(onFFTCircleSensitivitySliderChanged(int)));

    connect(this, SIGNAL(sendOvertimeFFTSmoothing(int)), c, SLOT(onOvertimeFFTSmoothingAmtChanged(int)));
    connect(OvertimeFFTUpdateFrequencyEditor, SIGNAL(returnPressed()), this, SLOT(onUpdateOvertimeFFTTimer()));
    connect(OvertimeFFTAlphaBlendingSlider, SIGNAL(valueChanged(int)), c, SLOT(onOvertimeFFTAlphaBlendingChanged(int)));
    connect(OvertimeFFTDynamicSmoothLimitSlider, SIGNAL(valueChanged(int)), c, SLOT(onOvertimeFFTDynamicSmoothLimitChanged(int)));

    connect(playButton, SIGNAL(clicked()), c, SLOT(onPlayButtonPressed()));
    connect(pauseButton, SIGNAL(clicked()), c, SLOT(onPauseButtonPressed()));
    connect(prevButton, SIGNAL(clicked()), this, SLOT(onPrevButtonPressed()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(onNextButtonPressed()));
    connect(this, SIGNAL(nextMedia(unsigned int)), c, SLOT(onNextButtonPressed(unsigned int)));
    connect(this, SIGNAL(previousMedia(unsigned int)), c, SLOT(onPrevButtonPressed(unsigned int)));
    connect(c, SIGNAL(updateCurrentRow(unsigned int)), this, SLOT(onUpdateCurrentRow(unsigned int)));

    connect(c, SIGNAL(updateArtistInWidget(std::string)), m_MetaDataWidget, SLOT(onUpdateArtistInWidget(const std::string&)));

    connect(c, SIGNAL(positionChanged(qint64)), this, SLOT(onPositionChanged(qint64)));
    connect(volumeSlider, SIGNAL(valueChanged(int)), c, SLOT(onVolumeChanged(int)));
    connect(c, SIGNAL(updateProgSliderRange(int)), this, SLOT(onUpdateProgSliderRange(int)));
    connect(progSlider, SIGNAL(sliderMoved(int)), this, SLOT(helper_progSliderPositionChanged(int)));
    connect(this, SIGNAL(progSliderPositionChanged(qint64)), c, SIGNAL(progSliderPositionChanged(qint64)));
    connect(this, SIGNAL(sendPalette(float,float,float,float,float,float)), c, SLOT(onPaletteChanged(float,float,float,float,float,float)));
    connect(c, SIGNAL(paletteChanged(float,float,float,float,float,float)), m_OvertimeFFTWidget, SLOT(onPaletteChanged(float,float,float,float,float,float)));
    connect(this, SIGNAL(changeIncrementSpeed(float, float, float)), c, SLOT(onChangeIncrementSpeed(float, float, float)));
    connect(this, SIGNAL(sendIncrementSpeed(float, float, float)), m_OvertimeFFTWidget, SLOT(onIncrementSpeedChanged(float, float, float)));
    connect(c, SIGNAL(outOfRangeTimer()), this, SLOT(onOutOfRangeTimer()));
    connect(c, SIGNAL(formatNotValid()), this, SLOT(onFormatNotValid()));
    connect(c, SIGNAL(fileDoesNotExist()), this, SLOT(onFileDoesNotExist()));

}

void MainWindow::onSoundWaveButtonClicked(bool checked)
{
    if(checked)
    {
        stackedGLWidget->setCurrentWidget(m_soundWaveWidget);
        soundWaveSettingsPlaceHolder->show();
    }
    else soundWaveSettingsPlaceHolder->hide();
}

void MainWindow::onFFTBarsButtonClicked(bool checked)
{
    if(checked)
    {
        stackedGLWidget->setCurrentWidget(m_FFTBarsWidget);
        FFTBarsSettingsPlaceHolder->show();
    }
    else FFTBarsSettingsPlaceHolder->hide();
}

void MainWindow::onFFTCircleButtonClicked(bool checked)
{
    if(checked)
    {
        stackedGLWidget->setCurrentWidget(m_FFTCircleWidget);
        FFTCircleSettingsPlaceHolder->show();
    }
    else FFTCircleSettingsPlaceHolder->hide();
}

void MainWindow::onOvertimeFFTButtonClicked(bool checked)
{
    if(checked)
    {
        stackedGLWidget->setCurrentWidget(m_OvertimeFFTWidget);
        OvertimeFFTSettingsPlaceHolder->show();
    }
    else OvertimeFFTSettingsPlaceHolder->hide();
}

void MainWindow::onPushUpdateList(const std::string& title)
{
    mediaList->addItem(QString::fromUtf8(title.c_str()));
}

void MainWindow::onUpdateOvertimeFFTTimer()
{
    emit updateOvertimeFFTTimer(OvertimeFFTUpdateFrequencyEditor->text().toUInt());
}

void MainWindow::identifyFFTBarsSmoothing()
{
    emit sendFFTBarsSmoothing(FFTBarsSmoothingGroup->checkedId());
}

void MainWindow::identifyOvertimeFFTSmoothing()
{
    emit sendOvertimeFFTSmoothing((OvertimeFFTSmoothingGroup->checkedId()));
}

void MainWindow::onItemDoubleClicked(QListWidgetItem* item)
{
    int index = mediaList->row(item);
    mediaList->setCurrentRow(index);
    emit selectedMediaItem(static_cast<unsigned int>(index));
}

void MainWindow::onPrevButtonPressed()
{
    int index = mediaList->currentRow();
    emit previousMedia(static_cast<unsigned int>(index));
}

void MainWindow::onNextButtonPressed()
{
    int index = mediaList->currentRow();
    emit nextMedia(static_cast<unsigned int>(index));
}

void MainWindow::onUpdateCurrentRow(unsigned int index)
{
    mediaList->setCurrentRow(static_cast<int>(index));
}

void MainWindow::onPositionChanged(qint64 t)
{
    progSlider->setValue(static_cast<int>(t/1000));
}

void MainWindow::onUpdateProgSliderRange(int d)
{
    progSlider->setRange(0, d);
}

void MainWindow::helper_progSliderPositionChanged(int i)
{
    emit progSliderPositionChanged(static_cast<qint64>(i));
}

void MainWindow::onRemoveButtonPressed()
{
    int index = mediaList->currentRow();
    emit removeMedia(static_cast<unsigned int>(index));
    mediaList->takeItem(index);
}

void MainWindow::onSwapMediaButtonPressed()
{
    int index = mediaList->currentRow();
    emit swapMedia(static_cast<unsigned int>(index));
    QListWidgetItem* toSwap = mediaList->takeItem(index);
    mediaList->insertItem(index+1, toSwap);
}

void MainWindow::onPaletteSliderMoved()
{
    float rs = startRedValueEdit->value();
    float gs = startGreenValueEdit->value();
    float bs = startBlueValueEdit->value();
    float re = endRedValueEdit->value();
    float ge = endGreenValueEdit->value();
    float be = endBlueValueEdit->value();

    emit sendPalette(rs,gs,bs,re,ge,be);
}

void MainWindow::onApplyRGBIncrementButtonClicked()
{
    float r_increment = redIncrementSpeedEdit->text().toFloat();
    float g_increment = greenIncrementSpeedEdit->text().toFloat();
    float b_increment = blueIncrementSpeedEdit->text().toFloat();

    emit changeIncrementSpeed(r_increment, g_increment, b_increment);
}

void MainWindow::onFormatNotValid()
{
    QMessageBox msgBox;
    msgBox.critical(nullptr, "Error", "Format not valid");
    msgBox.setFixedSize(500,200);
}

void MainWindow::onOutOfRangeTimer()
{
    QMessageBox msgBox;
    msgBox.critical(nullptr, "Error", "Out of range timer");
    msgBox.setFixedSize(500,200);
}

void MainWindow::onFileDoesNotExist()
{
    QMessageBox msgBox;
    msgBox.critical(nullptr, "Error", "File does not exist");
    msgBox.setFixedSize(500,200);
}

void MainWindow::onPropertiesButtonClicked()
{
    m_MediaPropertiesWidget->show();
}
