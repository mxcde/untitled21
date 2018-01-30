#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  //  setFixedSize(800,800); //固定大小
   // setStyleSheet("background-color:black");

    //setAutoFillBackground(true);

    //setFixedSize(800,800);


    //childrenRect();
    QPalette palette;
    ui->widget->setStyleSheet("background-color:black;");
    palette.setBrush(QPalette::Background,QBrush(QPixmap(pixmap)));
    ui->widget->setPalette(palette);

    QWidget* p = new pao(this);
    p = ui->widget;
    p->setGeometry(0,0,500,100);
    //p->setStyleSheet("background-color:black;");


    // painter = new QPainter (ui->widget);
   // painter0();
    //ui->widget->setGeometry(0,0,300,100);

    //setCentralWidget(pixmap);
    setWindowTitle("Hello DevDiv!");
    fname = "C:\\Users\\ZhuQiang\\Documents\\untitled21\\iris.txt";
    readfile();

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::paintEvent(QPaintEvent *)
{

   // painter = new QPainter (&pixmap);             // 创建QPainter一个对象
    painter = new QPainter (this);
    pen.setColor(Qt::red);
    pen.setWidth(5);// 设置画笔为黄色
    painter->setPen(pen);   // 设置画笔
    painter->drawPixmap(QPoint(100,100),pixmap);

    QBrush bruch(Qt::FDiagPattern);     // 画刷
    painter->setBrush(bruch);            // 设置画刷

    for(int i=0;i<iris.size();++i)
    {
        pointf[i].setX((iris[i][0]+iris[i][1])*20);
        pointf[i].setY((iris[i][2]+iris[i][1])*20);
    }
   painter->drawPoints(pointf,iris.size());
   vecmat();
}*/

void MainWindow::painter0()
{
              // 创建QPainter一个对象

    pen.setColor(Qt::white);
    pen.setWidth(2);// 设置画笔为黄色
    painter->setPen(pen);   // 设置画笔


    QBrush bruch(Qt::FDiagPattern);     // 画刷
    painter->setBrush(bruch);            // 设置画刷

    for(int i=0;i<iris.size();++i)
    {
        pointf[i].setX((iris[i][0]+iris[i][1])*20);
        pointf[i].setY((iris[i][2]+iris[i][1])*20);
    }
   painter->drawPoints(pointf,iris.size());
   vecmat();
}

void MainWindow::vecmat()
{
    vectomat();
    kmean();
}

void MainWindow::kmean()
{
    centers =  Mat(3, 1, mat.type());
    kmeans(mat,3, labels,
        TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0),
           3, KMEANS_PP_CENTERS, centers);
    kmcolor();
    writefile();
}

void MainWindow::kmcolor()
{

    for(int i=0;i<150;++i)
    {
        int cIdx = labels.at<int>(i);

        if(cIdx ==0)
        {
            pen.setColor(Qt::green);

        }
        else if(cIdx ==1)
        {
            pen.setColor(Qt::red);
        }
        else
        {
            pen.setColor(Qt::yellow);
        }
        pen.setWidth(2);// 设置画笔为黄色
        painter->setPen(pen);
        painter->drawPoint(pointf[i]);
    }


}

void MainWindow::readfile()
{
        ifstream filename(fname);
        string line;
        int div_pose =0;

        vector<float> tmp;
        string str;
        while (getline(filename,line))
        {
            tmp.clear();
            int i = 0;
            if (line[0] == ' ')
            {
                i++;
            }
            while (1)
            {
                div_pose = line.find(" ");
                if (div_pose <0)
                {
                    break;
                }
                str = line.substr(0, div_pose);

                float f2 = stof(str);
                tmp.push_back(f2);

                line = line.substr(div_pose + 1, line.size());
            }
            tmp.push_back(stof(line));
            iris.push_back(tmp);
        }

}

void MainWindow::vectomat()
{
    Mat	tmp(iris.size(), iris.at(0).size(), CV_32F);
     for (int i=0;i<tmp.rows;++i)
     {
         for (int j = 0; j < tmp.cols; ++j)
         {
             tmp.at<float>(i, j) = iris.at(i).at(j);
         }
     }
     tmp.copyTo(mat);
}

void MainWindow::writefile()
{
    fstream  outfile;
    outfile.open("irii.txt",ios::out|ios::trunc);
    outfile<<"iris0\n";
    for(int i=0;i<150;++i)
    {
        int cIdx = labels.at<int>(i);
        if(cIdx ==0)
        {
         outfile<<fixed<<iris[i][0]<<" "<<iris[i][1]<<" "<<iris[i][2]<<" "<<iris[i][3]<<"\n";
        }

    }
     outfile<<"iris1\n";
    for(int i=0;i<150;++i)
    {
        int cIdx = labels.at<int>(i);
        if(cIdx ==1)
        {
         outfile<<fixed<<iris[i][0]<<" "<<iris[i][1]<<" "<<iris[i][2]<<" "<<iris[i][3]<<"\n";
        }

    }
     outfile<<"iris2\n";
    for(int i=0;i<150;++i)
    {
        int cIdx = labels.at<int>(i);
        if(cIdx ==2)
        {
         outfile<<fixed<<iris[i][0]<<" "<<iris[i][1]<<" "<<iris[i][2]<<" "<<iris[i][3]<<"\n";
        }

    }

}

void MainWindow::run()
{

}


pao::pao(QWidget *parent)
{
    painter = new QPainter (parent);
}

void pao::paintEvent(QPaintEvent *)
{

    pen.setColor(Qt::red);
    pen.setWidth(2);// 设置画笔为黄色
    painter->setPen(pen);   // 设置画笔


    QBrush bruch(Qt::FDiagPattern);     // 画刷
    painter->setBrush(bruch);// 设置画刷
    QPoint  point;
    point.setX(10);
    point.setY(10);
    painter->drawPoint(point);
/*
    for(int i=0;i<iris.size();++i)
    {
        pointf[i].setX((iris[i][0]+iris[i][1])*20);
        pointf[i].setY((iris[i][2]+iris[i][1])*20);
    }*/
    // painter->drawPoints(pointf,iris.size());
}

