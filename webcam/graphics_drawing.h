#ifndef GRAPHICS_DRAWING_H
#define GRAPHICS_DRAWING_H

#include <QGraphicsView>

class graphics_drawing : public QGraphicsView
{
    Q_OBJECT
public:
    explicit graphics_drawing(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // GRAPHICS_DRAWING_H
