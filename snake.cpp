#include <snake.h>
#include <QRect>
#include <QDebug>
Snake::Snake(QObject *parent): QObject(parent){
    this->body.push_back(QRect(500, 500, 100, 100));
}

void Snake::move(){
    for (int i = body.size()-1; i > 0 ; --i){
        body[i].moveTo(body[i-1].topLeft());
    }
    switch(direction){
        case 0:
            body[0].translate(speed, 0);
            break;
        case 1:
            body[0].translate(-speed, 0);
            break;
        case 2:
            body[0].translate(0, speed);
            break;
        case 3:
            body[0].translate(0, -speed);
            break;
    }
    for (int i = body.size()-1; i > 0 ; --i){
        if (body[0].intersects(body[i])){
            qDebug() << "Game over";
        }
    }
}
