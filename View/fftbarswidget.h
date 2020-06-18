#ifndef FFTBARSWIDGET_H
#define FFTBARSWIDGET_H

//#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class FFTBarsWidget: public QOpenGLWidget, protected QOpenGLFunctions
{
Q_OBJECT
public:
    FFTBarsWidget();

protected:
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;

public slots:
     void onSendHeightsEvent(const std::vector<double>&);

private:
    std::vector<double> m_heights;
};

#endif // FFTBARSWIDGET_H
