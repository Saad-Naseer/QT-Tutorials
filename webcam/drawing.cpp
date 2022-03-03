#include "drawing.h"
#include <QDebug>
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>
drawing::drawing(QWidget *parent) :
    QLabel(parent)
{
    this->setMinimumSize(1,1);
    setScaledContents(false);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Mat2QImage()));
    timer->start(1000);
    //pix.load("/home/franz/Bilder/robidia_icon.png");

}

/*void drawing::setPixmap ( const QPixmap & p)
{
    //pix = p;
    qDebug()<<"here";
    //QLabel::setPixmap(scaledPixmap());
}
*/
int drawing::heightForWidth( int width ) const
{
    return pix.isNull() ? this->height() : ((qreal)pix.height()*width)/pix.width();
}

QSize drawing::sizeHint() const
{
    int w = this->width();
    return QSize( w, heightForWidth(w) );
}

QPixmap drawing::scaledPixmap() const
{
    return pix.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void drawing::resizeEvent(QResizeEvent * e)
{
    if(!pix.isNull())
        QLabel::setPixmap(scaledPixmap());
}
void drawing::Mat2QImage()
{
    cv::VideoCapture cap;
    if (!cap.open(0))
    {
        std::cout<<"error in webcam11111";
        //return 0;
    }

    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    cv::Mat frame;
    cap >> frame;


    // cv::resize(frame, frame, cv::Size(disp_img_size.x, disp_img_size.y));

    QImage dest((const uchar *)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    pix = QPixmap::fromImage(dest);


    dest = QImage();


}
