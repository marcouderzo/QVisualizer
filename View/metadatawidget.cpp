#include "View/metadatawidget.h"

MetaDataWidget::MetaDataWidget()
{
    painter = new QPainter();
    coverArt =  QImage(QVisualizerLogo);
    title = "Welcome to QVisualizer!";
    artist = "";
}

void MetaDataWidget::initializeGL()
{
    initializeOpenGLFunctions();
}

void MetaDataWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MetaDataWidget::paintGL()
{
    makeCurrent();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    painter->begin(this);
    painter->setRenderHint(QPainter::HighQualityAntialiasing);
    painter->setRenderHint(QPainter::TextAntialiasing);

    int x=coverArt.width();
    int y=coverArt.height();
    while(x>=CoverRectX && y>=CoverRectY)
    {
        x/=2;
        y/=2;
    }

    titleRect= QRect(x+20, y, width()-x-20, height());

    painter->drawImage(QRect(10, 30, x, y), coverArt, coverArt.rect());

    double factor = titleRect.width() / painter->fontMetrics().width(title.c_str());
    if ((factor < 1) || (factor > 1.25))
    {
        QFont f = painter->font();
        if(f.pointSizeF()*factor > 0)
            f.setPointSizeF(f.pointSizeF()*factor);

        qreal amt=f.pointSizeF();
        while(amt > 40)
            amt-=1;
        f.setPointSizeF(amt);
        painter->setFont(f);
    }

    painter->setPen(Qt::white);
    painter->drawText(x+20, 100, title.c_str());
    QFont f = painter->font();
    if(f.pointSizeF()-17 > 0)
        f.setPointSizeF(f.pointSizeF()-17);
    painter->setFont(f);

    if(artist!="")
        painter->drawText(x+20, 160, artist.c_str());
    painter->end();
}

void MetaDataWidget::onUpdateTitleInWidget(const std::string& t)
{
    title=t;
    update();
}

void MetaDataWidget::onUpdateImageInWidget(const QImage & image)
{
    if(image.isNull())
        coverArt = QImage(QVisualizerLogo);
    else
        coverArt = image;

    update();
}

void MetaDataWidget::onUpdateArtistInWidget(const std::string& a)
{
    if(a!="")
        artist=a;
    update();
}

void MetaDataWidget::onSetDefaultEvent()
{
    title = "No Media Selected.";
    artist = "";
    coverArt = QImage(QVisualizerLogo);
    update();
}

