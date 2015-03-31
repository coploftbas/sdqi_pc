#include "Scene.h"

#include <QtDebug>
#include <QGraphicsSceneMouseEvent>
#include <QDrag>
#include <QMimeData>

Item::Item(int x, int y) : QGraphicsEllipseItem(x,y,50,50) {}

void Item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "item mouse press";

    // Create the mime  data that will be transfered  from one scene
    // to another
    QMimeData * mimeData = new QMimeData;

    // In our case, the data will be the address of the item.
    //
    // Note: This is  UNSAFE, and just for the  sake of example. The
    // good way to do it is to create your own mime type, containing
    // all the information necessary to recreate an identical Item.
    //
    // This  is because  drag  and  drop is  meant  to work  between
    // applications, and the address  of your item is not accessible
    // by  other  applications   (deferencing  it  would  produce  a
    // segfault). It  works fine  in this case  since you  perform a
    // drag  and   drop  between  different  windows   of  the  same
    // application.
    Item *item = this;
    QByteArray byteArray(reinterpret_cast<char*>(&item),sizeof(Item*));
    mimeData->setData("Item",byteArray);

    // start the event
    QDrag *drag = new QDrag(event->widget());
    drag->setMimeData(mimeData);
    drag->start();
}

Scene::Scene(int i) : i(i)
{
    Item *item = new Item(100+100*i,100);
    addItem(item);
}

void Scene::dragEnterEvent ( QGraphicsSceneDragDropEvent * event )
{
    qDebug() << "scene" << i << "drag enter";
}

void Scene::dragLeaveEvent ( QGraphicsSceneDragDropEvent * event )
{
    qDebug() << "scene" << i << "drag leave";
}

void Scene::dragMoveEvent ( QGraphicsSceneDragDropEvent * event )
{
    qDebug() << "scene" << i << "drag move";
}


void Scene::dropEvent ( QGraphicsSceneDragDropEvent * event )
{
    qDebug() << "scene" << i << "drop";

    // retrieve the address of the item from the mime data
    QByteArray byteArray = event->mimeData()->data("Item");
    Item * item = *reinterpret_cast<Item**>(byteArray.data());

    // add the item  to the scene (automatically remove  it from the
    // other scene)
    addItem(item);
}

