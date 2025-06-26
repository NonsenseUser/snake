#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QRandomGenerator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    snake = new Snake();

    ui->setupUi(this);
    QTimer *renderTimer = new QTimer(this);
    QObject::connect(renderTimer, &QTimer::timeout, snake, &Snake::move);
    QObject::connect(renderTimer, &QTimer::timeout, this, &MainWindow::repaintWindow);
    renderTimer->start(500);
    food = QRect(50, 50, 100, 100);
}

void MainWindow::repaintWindow(){
    update();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if (snake->body[0].intersects(food)) {
        int newFoodX = QRandomGenerator::global()->bounded(600);
        int newFoodY = QRandomGenerator::global()->bounded(600);
        food = QRect(newFoodX, newFoodY, 100, 100);
        QPoint tailCoord = snake->body[0].bottomLeft();
        snake->body.push_back(QRect(tailCoord.rx(), tailCoord.ry(), 100, 100));
    }
    for (int i = 0; i < snake->body.size(); ++i){
        painter.drawRect(snake->body[i]);
    }
        painter.drawRect(food);
    }

void MainWindow::keyPressEvent(QKeyEvent *event){
    QString button = event->text();
    if (button == 'w') {
        snake->direction = 3;
    }
    if (button == 'a') {
        snake->direction = 1;
    }
    if (button == 'd') {
        snake->direction = 0;
    }
    if (button == 's') {
        snake->direction = 2;
    }
    //snake->move();
    //repaint();
}
