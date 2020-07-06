#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OvertimeFFTWidget: public QOpenGLWidget, protected QOpenGLFunctions
{
Q_OBJECT
public:
    OvertimeFFTWidget();

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;

public slots:
     void onSendBuffersEvent(const std::vector<double>&, const std::vector<std::vector<double>>&);
     void onUpdateAlphaBlending(float);
     void onPaletteChanged(float,float,float,float,float,float);
     void onIncrementSpeedChanged(float, float, float);

private:
    std::vector<double> m_heights;
    std::vector<std::vector<double>> m_timeBuffer;

    float r_start;
    float g_start;
    float b_start;
    float r_end;
    float g_end;
    float b_end;
    float r_increment;
    float g_increment;
    float b_increment;

    char r_operation;
    char g_operation;
    char b_operation;

    float alphaBlending;
};


