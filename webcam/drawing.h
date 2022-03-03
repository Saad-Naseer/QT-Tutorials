#ifndef DRAWING_H
#define DRAWING_H

#include <QLabel>
#include <QTimer>

class drawing : public QLabel
{
    Q_OBJECT
public:
    explicit drawing(QWidget *parent = nullptr);
    virtual int heightForWidth( int width ) const;
    virtual QSize sizeHint() const;
    QPixmap scaledPixmap() const;

public slots:
    //void setPixmap ( const QPixmap & );
    void resizeEvent(QResizeEvent *);
    void Mat2QImage();
private:
    QPixmap pix;
    QTimer *timer;
};

#endif // DRAWING_H
