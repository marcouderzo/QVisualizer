#include "View/soundwavewidget.h"

SoundWaveWidget::SoundWaveWidget()
{
    bufferSize = 2304;
    m_wave.reserve(bufferSize);
}

void SoundWaveWidget::initializeGL()
{
    initializeOpenGLFunctions();
}

void SoundWaveWidget::paintGL()
{
    makeCurrent();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    GLdouble xOffset=0.0;
    for(unsigned int i=0; i<3840; i++)
    {
        glVertex2d(-1+xOffset, m_wave[i]);
        xOffset+=2.0/static_cast<double>(bufferSize);
        glVertex2d(-1+xOffset, m_wave[i+1]);
    }
    glEnd();

    glFlush();
}

void SoundWaveWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void SoundWaveWidget::onSendWaveEvent(const std::vector<double>& vect)
{
    m_wave.clear();
    for(auto el : vect)
        m_wave.push_back(el);
    update();
}

void SoundWaveWidget::onUpdateSoundWaveBufferSize(unsigned int size)
{
    if(size != bufferSize)
        bufferSize = size;
}
