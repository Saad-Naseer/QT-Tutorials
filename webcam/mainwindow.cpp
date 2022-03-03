#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyleOptionSlider>
#include <QToolTip>
//#include "fancyslider.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->label->move(QPoint(ui->horizontalSlider->pos().x()+ui->horizontalSlider->handle_coord.x(), ui->horizontalSlider->y()));
    //ui->label_2->move(QPoint(ui->horizontalSlider_2->pos().x()+ui->horizontalSlider_2->handle_coord.x(), ui->horizontalSlider_2->y()));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug()<<"xhanged";
    qDebug()<<ui->horizontalSlider->handle_coord;
   // ui->label->setParent(ui->horizontalSlider);

    ui->label->move(QPoint(ui->horizontalSlider->pos().x()+ui->horizontalSlider->handle_coord.x(), ui->horizontalSlider->pos().y()-15));

}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    ui->label_2->move(QPoint(ui->horizontalSlider_2->pos().x()+ui->horizontalSlider_2->handle_coord.x(),0));

}


void MainWindow::on_pushButton_clicked()
{

    ui->horizontalSlider->setValue(10);
    if(ui->pushButton->isChecked())
    {

    }
    else
    {

    }
}
