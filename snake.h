#ifndef SNAKE_H
#define SNAKE_H
#include<bodypart.h>
#include <QObject>
#include <QDebug>
#include <QRect>

class Snake : public QObject {
    Q_OBJECT

public:
    std::vector<QRect> body;
    int direction = 0;
    int speed = 100;
    Snake(QObject *parent = nullptr);
    virtual ~Snake(){};

public slots:
    void move();
};
#endif // SNAKE_H
