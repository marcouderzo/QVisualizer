#include "View/overtimefftwidget.h"

OvertimeFFTWidget::OvertimeFFTWidget()
{
    m_heights.reserve(100);
    for(unsigned long long i=0; i<100; i++) m_heights[i]=0;

    r_start = 0.7f;
    g_start = 0.7f;
    b_start = 1.0f;

    r_end = 0.0f;
    g_end = 0.5f;
    b_end = 1.0f;

    r_increment = 0.01f;
    g_increment = 0.01f;
    b_increment = 0.01f;


    alphaBlending=0.17f;
}

void OvertimeFFTWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OvertimeFFTWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OvertimeFFTWidget::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    glColor4f(1.0f, 1.0f, 1.0f, 0.2f);

    GLdouble xOffset=0.0;
    for(unsigned long long i=0; i<99; i++)
    {
        glVertex2d(-1.0+xOffset, m_heights[i]);
        xOffset+=2.0/static_cast<double>(m_heights.size()-1);
        glVertex2d(-1.0+xOffset, m_heights[i+1]);
    }

    glEnd();

    glBegin(GL_LINES);

    xOffset=0.0;
    GLdouble t_xOffset=0.01;
    GLdouble yOffset=0.01;

    //Start Color
    GLfloat r=r_start;
    GLfloat g=g_start;
    GLfloat b=b_start;

    for(unsigned int k=0; k<m_timeBuffer.size(); k++)
    {
        glColor4f(r, g, b, alphaBlending);


        if(r_operation=='+'){
            if(r <= r_end)
                r+=r_increment;
        }
        else if(r >= r_end)
            r-=r_increment;

        if(g_operation=='+'){
            if(g <= g_end)
                g+=g_increment;
        }
        else if(g >= g_end)
            g-=g_increment;

        if(b_operation=='+'){
            if(b <= b_end)
                b+=b_increment;
        }
        else if(b >= b_end)
            b-=b_increment;

        xOffset=0;
        for(unsigned int i=0; i<99; i++)
        {
            glVertex2d(-1.0+t_xOffset+xOffset, yOffset+m_timeBuffer[k][i]);
            xOffset+=0.02;
            glVertex2d(-1.0+t_xOffset+xOffset, yOffset+m_timeBuffer[k][i+1]);
        }

        t_xOffset+=0.01;
        yOffset+=0.01;
    }

    glEnd();

    glFlush();
}

void OvertimeFFTWidget::onSendBuffersEvent(const std::vector<double>& heights, const std::vector<std::vector<double>>& t)
{
    m_heights.clear();
    for(unsigned int i=0; i<100; i++)
        m_heights.push_back(heights[i]);

    m_timeBuffer.clear();
    for(auto el : t)
        m_timeBuffer.push_back(el);

    update();
}

void OvertimeFFTWidget::onUpdateAlphaBlending(float amt)
{
    alphaBlending=amt;
}

void OvertimeFFTWidget::onPaletteChanged(float rs, float gs, float bs, float re, float ge, float be)
{
    r_start= rs;
    g_start= gs;
    b_start= bs;
    r_end= re;
    g_end= ge;
    b_end= be;

    if(r_end >= r_start) r_operation='+';
    else r_operation= '-';

    if(g_end >= g_start) g_operation='+';
    else g_operation= '-';

    if(b_end >= b_start) b_operation='+';
    else b_operation= '-';
}

void OvertimeFFTWidget::onIncrementSpeedChanged(float ri, float gi, float  bi)
{
    r_increment=ri;
    g_increment=gi;
    b_increment=bi;
}
