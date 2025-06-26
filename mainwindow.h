#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <snake.h>
#include <QKeyEvent>
#include <QObject>
#include <food.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Snake *snake;
    QRect food;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);
    void keyPressEvent (QKeyEvent *event) override;

private slots:
    void repaintWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
