#include <QApplication>
#include <QQmlApplicationEngine>

#include "Scene.h"
#include "View.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

        Scene * scene1 = new Scene(1);
        View * view1 = new View(scene1, 1);

        Scene * scene2 = new Scene(2);
        View * view2 = new View(scene2,2);

        view1->show();
        view2->show();
        return app.exec();
}
