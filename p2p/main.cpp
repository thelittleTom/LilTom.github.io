#include "mainwindow.h"
#include<time.h>
#include <QApplication>
# include<QDebug>
int main(int argc, char *argv[])
{

    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
