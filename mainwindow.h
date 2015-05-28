#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPainter>

#include <QMainWindow>
#include"dialog.h"
#include<QPushButton>
#include<QLCDNumber>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static const int size=100;
protected:
    void paintEvent(QPaintEvent *);
    void generate();
    void initial();
    void keyPressEvent(QKeyEvent *);
    void picture();
    void moveup();
    void movedown();
    void moveright();
    void moveleft();
    void assign();
    void initialmarker();
    void open();
    void gameover();
    void score();
    void highscore();
    void openwin();



private slots:
    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
    int xplace;
    int yplace;
    int row;
    int column;
    int gamemember[4][4];
    QPixmap image[13];
    QPixmap *art[4][4];
    int marker[4][4];
    int  check;
    QPushButton *p[1];
    QLCDNumber *s[2];
    int scorenum;
    int highscorenum;

};

#endif // MAINWINDOW_H
