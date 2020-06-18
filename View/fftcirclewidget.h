#ifndef FFTCIRCLEWIDGET_H
#define FFTCIRCLEWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPainter>
#define _USE_MATH_DEFINES
#include <math.h>

class FFTCircleWidget: public QOpenGLWidget, protected QOpenGLFunctions
{
Q_OBJECT
public:
    FFTCircleWidget();

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;

private:
    std::vector<double> m_radiuses;
    QPainter* painter;
    QPen* pen;

public slots:
    void onSendRadiusesEvent(const std::vector<double>&);

};

#endif // FFTCIRCLEWIDGET_H
