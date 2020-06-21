#include "View/fftcirclewidget.h"

FFTCircleWidget::FFTCircleWidget()
{
    m_radiuses.reserve(2048);
    painter = new QPainter();
    pen = new QPen();
}

void FFTCircleWidget::initializeGL()
{
   initializeOpenGLFunctions();
}

void FFTCircleWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void FFTCircleWidget::paintGL()
{
    makeCurrent();

    painter-> begin(this);
    painter-> setRenderHint(QPainter::HighQualityAntialiasing);

    unsigned int k = 0;
    int w = width()/2;
    int h = height()/2;

    for(int i=0; i<32; i++){

        pen-> setColor(Qt::white);
        double aux = (m_radiuses[k] + m_radiuses[k + 1] + m_radiuses[k + 2]) / 3;
        aux *= w;
        k += 3;
        painter-> setPen(*pen);

        QRect* rect = new QRect(400, 400, 100 + static_cast<int>(aux), 100 + static_cast<int>(aux));
        rect->moveCenter(QPoint(w, h));

        painter-> drawArc(*rect, i*180, 180);

        painter-> drawLine(w, h, static_cast<int>(w + ((50 + aux / 2) * cos(180.0 / 16.0 * i * M_PI / 180.0))), static_cast<int>(h - ((50 + aux/2) * sin(180.0 / 16.0 * i * M_PI / 180.0))));
        painter-> drawLine(w, h, static_cast<int>(w + ((50 + aux / 2) * cos(180.0 / 16.0 * (i + 1) * M_PI / 180.0))), static_cast<int>(h - ((50 + aux/2) * sin(180.0 / 16.0 * (i + 1) * M_PI / 180.0))));
    }
    painter->end();
}

void FFTCircleWidget::onSendRadiusesEvent(const std::vector<double>& radiuses)
{
    m_radiuses.clear();
    for(unsigned int i=0; i<2048; i++)
        m_radiuses.push_back(radiuses[i]);
    update();
}
