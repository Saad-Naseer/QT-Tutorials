#include "fancyslider.h"

#include <QStyleOptionSlider>
#include <QToolTip>
#include <QLabel>
#include <QDebug>

FancySlider::FancySlider(QWidget * parent)
    : QSlider(parent)
{

}

FancySlider::FancySlider(Qt::Orientation orientation, QWidget * parent)
    : QSlider(orientation, parent)
{
}

void FancySlider::sliderChange(QAbstractSlider::SliderChange change)
{
    QSlider::sliderChange(change);

    //if (change == QAbstractSlider::SliderValueChange )
    //{
        QStyleOptionSlider opt;
        initStyleOption(&opt);

        QRect sr = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);
        //QPoint bottomRightCorner = sr.bottomLeft();
        QPoint bottomRightCorner = sr.topLeft();
        handle_coord = bottomRightCorner;
        qDebug()<<"bottom :"<<bottomRightCorner;


        QToolTip::showText(mapToGlobal( QPoint( bottomRightCorner.x(), bottomRightCorner.y() ) ), QString::number(value()), this);


    //}
}
