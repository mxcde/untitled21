#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<iostream>
#include<string>
#include<fstream>

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QTextEdit>
#include <QThread>
#include <QPixmap>

#include<opencv2/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui.hpp>

#include<vector>

#include"ui_mainwindow.h"
using namespace cv;
using namespace std;
namespace Ui {
class MainWindow;
class pao;
}

class MainWindow : public QMainWindow,public QThread
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     //void paintEvent(QPaintEvent *);
     void painter0();
     void vecmat();
     void kmean();
     void kmcolor();
public:
     void readfile();
     void vectomat();
     void writefile();
public:
    Ui::MainWindow *ui;
    QPainter *painter;
    QPen      pen;
    QPointF   pointf[150];
    Point2f   poin[6];
    string fname;

    Mat centers;
    Mat labels;
    Mat  mat;
    QPixmap pixmap;
    void run();
    vector<vector<float>> iris;




    std::vector<Point2f> vec;
};

class pao:public QWidget
{
public:
    pao(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    QPainter *painter;
    QPen      pen;
    //Ui::pao *ui;
};


#endif // MAINWINDOW_H
