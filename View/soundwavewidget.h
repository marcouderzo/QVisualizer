#ifndef SOUNDWAVEWIDGET_H
#define SOUNDWAVEWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class SoundWaveWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    SoundWaveWidget();

protected:
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;

private:
    std::vector<double> m_wave;
    unsigned int bufferSize;

public slots:
     void onSendWaveEvent(const std::vector<double>&);
     void onUpdateSoundWaveBufferSize(unsigned int);

};

#endif // SOUNDWAVEWIDGET_H
