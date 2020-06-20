#ifndef METADATAWIDGET_H
#define METADATAWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QPainter>

#define CoverRectX 170
#define CoverRectY 170

#define QVisualizerLogo ":/resources/resources/QVisualizer.jpg"

class MetaDataWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    MetaDataWidget();

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;

public slots:
    void onUpdateTitleInWidget(const std::string&);
    void onUpdateImageInWidget(const QImage&);
    void onUpdateArtistInWidget(const std::string&);
    void onSetDefaultEvent();

private:
    QImage coverArt;
    std::string title;
    std::string artist;
    QRect targetRect;
    QRect titleRect;
    QPainter* painter;
};

#endif // METADATAWIDGET_H
