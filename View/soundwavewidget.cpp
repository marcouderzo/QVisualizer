#include "View/soundwavewidget.h"

SoundWaveWidget::SoundWaveWidget()
{
    m_wave.reserve(2304);
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
    for(unsigned int i=0; i<m_wave.size(); i++)
    {
        glVertex2d(-1+xOffset, m_wave[i]);
        xOffset+=2.0/static_cast<double>(m_wave.size());
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
