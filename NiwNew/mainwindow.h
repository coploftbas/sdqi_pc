#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QColorDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QObject *var1;
    QObject *var2;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);



private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *rectangle;
    QGraphicsRectItem *rectangel2;
};

#endif // MAINWINDOW_H
