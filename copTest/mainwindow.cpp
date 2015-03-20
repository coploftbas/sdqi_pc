#include "mainwindow.h"
#include "ui_mainwindow.h"

int posX = 0;
int posY = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    //QBrush blueBrush(Qt::gray);
    //QPen blackPen(Qt::black);

    //blackPen.setWidth(6);

    //rectangle = scene->addRect(10,10,50,50,blackPen, blueBrush);
    //rectangle->setFlag(QGraphicsItem::ItemIsMovable);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QBrush blueBrush(Qt::gray);
    QPen blackPen(Qt::black);
    blackPen.setWidth(6);
    rectangle = scene->addRect(posX, posY,80,50,blackPen, blueBrush);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
    posX += 50;
    posY += 50;
}
