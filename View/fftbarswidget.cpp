#include "View/fftbarswidget.h"

FFTBarsWidget::FFTBarsWidget()
{
    m_heights.reserve(100);
}

void FFTBarsWidget::initializeGL()
{
    initializeOpenGLFunctions();
}

void FFTBarsWidget::paintGL()
{
    makeCurrent();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    GLdouble xOffset=0.0;

    for(unsigned long long i=0; i<100; i++)
    {
        glVertex2d(-1.0+xOffset, -1.0);
        glVertex2d(-1.0+xOffset, m_heights[i]);
        glVertex2d(-0.99+xOffset, m_heights[i]);
        glVertex2d(-0.99+xOffset, -1.0);

        xOffset+=0.02;
    }

    glEnd();

    glFlush();
}

void FFTBarsWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void FFTBarsWidget::onSendHeightsEvent(const std::vector<double>& heights)
{
    m_heights.clear();
    for(auto el : heights)
        m_heights.push_back(el);
    update();
}
