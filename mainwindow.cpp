#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<cstdlib>
#include<ctime>
#include<QKeyEvent>
#include"dialog.h"
#include<QPixmap>
#include<QPushButton>
#include<cmath>
#include"win.h"
//#include<iostream>
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initial();
    picture();
    score();
    highscorenum=0;
    highscore();










}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    int i,j;
    QPainter painter(this);
    painter.drawPixmap(0,0,400,600,image[12]);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {   xplace=i*size;
            yplace=j*size;
            painter.drawPixmap(xplace,yplace+200,size,size,*art[i][j]);
        }
    }


}
void MainWindow::generate()
{
    srand(time(NULL));
    while(1)
    {
        row=rand()%4;
        column=rand()%4;
        if(gamemember[row][column]!=0)
        {
            continue;
        }
        else
        {
           // xplace=row*size;
            //yplace=column*size;
            gamemember[row][column]++;
           // art[row][column]=&image[gamemember[row][column]];
            break;
        }
    }
   assign();
   update();




}
void MainWindow::initial()
{
   srand(time(NULL));
   int i,j;
   for(i=0;i<4;i++)
   {
       for(j=0;j<4;j++)
       {
           gamemember[i][j]=0;
       }
   }
   i=rand()%4;
   j=rand()%4;
   gamemember[i][j]=1;
   assign();
   update();
   scorenum=0;
}
void MainWindow ::keyPressEvent(QKeyEvent *e)
{

   switch (e->key())
   {
   case Qt::Key_Up :moveup(); break;
   case Qt::Key_Down : movedown(); break;
   case Qt::Key_Right : moveright(); break;
   case Qt::Key_Left : moveleft(); break;
   }
}
void MainWindow::picture()
{
    image[0].load(":/0.jpg");
    image[1].load(":/2.jpg");
    image[2].load(":/4.jpg");
    image[3].load(":/8.jpg");
    image[4].load(":/16.jpg");
    image[5].load(":/32.jpg");
    image[6].load(":/64.jpg");
    image[7].load(":/128.jpg");
    image[8].load(":/256.jpg");
    image[9].load(":/512.jpg");
    image[10].load(":/1024.jpg");
    image[11].load(":/2048.jpg");
    image[12].load(":/background1.jpg");


}
void MainWindow::moveup()
{

    initialmarker();
    check=0;
    int i,j,k,number;
    for(i=0;i<4;i++)
    {
        for(j=1;j<4;j++)
        {
            for(number=1;number<12;number++)
            {
                if(gamemember[i][j]==number)
                {
                    k=j-1;
                    if(gamemember[i][k]==0)
                    {
                        if(marker[i][j]!=0)
                        {
                            marker[i][j]--;
                            marker[i][k]++;
                        }
                        gamemember[i][j]=0;
                        gamemember[i][k]=number;
                        check++;


                    }
                    else if(gamemember[i][j]==gamemember[i][k]&&marker[i][j]==0)
                    {
                        gamemember[i][k]=gamemember[i][j]+1;
                        scorenum+=pow(2,gamemember[i][k]);
                        gamemember[i][j]=0;
                        marker[i][k]++;
                        check++;

                    }
                    else
                        continue;
                    i--;

                }

            }
        }


    }
    assign();
    update();
    score();
    highscore();
    openwin();
    if(check!=0)
    {
        generate();
        gameover();
    }


}
void MainWindow::movedown()
{
    initialmarker();
    check=0;
    int i,j,k,number;
    for(i=0;i<4;i++)
    {
        for(j=2;j>=0;j--)
        {
            for(number=1;number<12;number++)
            {
                if(gamemember[i][j]==number)
                {
                    k=j+1;
                    if(gamemember[i][k]==0)
                    {
                        if(marker[i][j]!=0)
                        {
                           marker[i][j]--;
                           marker[i][k]++;
                        }
                        gamemember[i][j]=0;
                        gamemember[i][k]=number;
                        check++;



                    }
                    else if(gamemember[i][j]==gamemember[i][k]&&marker[i][j]==0)
                    {
                        gamemember[i][k]=gamemember[i][j]+1;
                        scorenum+=pow(2,gamemember[i][k]);
                        gamemember[i][j]=0;
                        marker[i][k]++;
                        check++;

                    }
                    else
                        continue;
                    i--;

                }
            }
        }
    }
    assign();
    update();
    score();
    highscore();
    openwin();
    if(check!=0)
    {
        generate();
        gameover();
    }

}
void MainWindow::moveright()
{

    initialmarker();
    check=0;
    int i,j,k,u,number;
    for(u=0;u<4;u++)
    {
        for(i=2;i>=0;i--)
        {
            for(j=0;j<4;j++)
            {
                for(number=1;number<12;number++)
                {
                    if(gamemember[i][j]==number)
                    {
                        k=i+1;
                        if(gamemember[k][j]==0)
                        {
                            gamemember[i][j]=0;
                            gamemember[k][j]=number;
                            if(marker[i][j]!=0)
                            {
                               marker[i][j]--;
                               marker[i][k]++;
                            }
                            check++;


                        }
                        else if(gamemember[i][j]==gamemember[k][j]&&marker[i][j]==0)
                        {
                            gamemember[k][j]=gamemember[i][j]+1;
                            scorenum+=pow(2,gamemember[k][j]);
                            gamemember[i][j]=0;
                            marker[k][j]++;
                            check++;

                        }
                        else
                            continue;

                        u--;

                    }
                }
            }
        }
    }

    assign();
    update();
    score();
    highscore();
    openwin();
    if(check!=0)
    {
        generate();
        gameover();
    }

}
void MainWindow::moveleft()
{

    initialmarker();
    check=0;
    int i,j,k,u,number;
    for(u=0;u<4;u++)
    {
        for(i=1;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                for(number=1;number<12;number++)
                {
                    if(gamemember[i][j]==number)
                    {
                        k=i-1;
                        if(gamemember[k][j]==0)
                        {
                            gamemember[i][j]=0;
                            gamemember[k][j]=number;
                            if(marker[i][j]!=0)
                            {
                               marker[i][j]--;
                               marker[i][k]++;
                            }
                            check++;


                        }
                        else if(gamemember[i][j]==gamemember[k][j]&&marker[i][j]==0)
                        {
                            gamemember[k][j]=gamemember[i][j]+1;
                            scorenum+=pow(2,gamemember[k][j]);
                            gamemember[i][j]=0;
                            marker[k][j]++;
                            check++;

                        }
                        else
                            continue;

                        u--;

                    }
                }
            }
        }
    }

    assign();
    update();
    score();
    highscore();
    openwin();
    if(check!=0)
    {
        generate();
        gameover();
    }


}

void MainWindow::assign()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            art[i][j]=&image[gamemember[i][j]];
        }
    }
}
void MainWindow::initialmarker()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            marker[i][j]=0;
        }
    }
}
void MainWindow::gameover()
{
    int i,j,k,gamecheck;
    gamecheck=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(gamemember[i][j]==0)
            {
                gamecheck++;
            }
        }
    }
    for(i=1;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            k=i-1;
            if(gamemember[i][j]==gamemember[k][j])
            {
                gamecheck++;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            k=i+1;
            if(gamemember[i][j]==gamemember[k][j])
            {
                gamecheck++;
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=1;j<4;j++)
        {
            k=j-1;
            if(gamemember[i][j]==gamemember[i][k])
            {
                gamecheck++;
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            k=j+1;
            if(gamemember[i][j]==gamemember[i][k])
            {
                gamecheck++;
            }
        }
    }
    if(gamecheck==0)
    {
        open();
    }


}
void MainWindow::open()
{

    Dialog *dialog=new Dialog;
    dialog->setWindowTitle(tr("you lose"));
    dialog->exec();
}





void MainWindow::on_pushButton_clicked()
{
    initial();
    score();
}

void MainWindow::score()
{
    s[0]=ui->lcdNumber;
    s[0]->display(scorenum);
}
void MainWindow::highscore()
{
    s[1]=ui->lcdNumber_2;
    if(scorenum>highscorenum)
    {
        highscorenum=scorenum;
    }
    else
        highscorenum=highscorenum;
    s[1]->display(highscorenum);
}
void MainWindow::openwin()
{
    int i,j,k;
    k=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(gamemember[i][j]==11)
             k=1;
        }
    }
    if(k!=0)
    {
        win *p=new win;
        p->setWindowTitle(tr("you win"));
        p->show();
    }
}
