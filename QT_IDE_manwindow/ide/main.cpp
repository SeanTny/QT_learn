#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(600,400);//将对话框重新设置大小宽500，高300
    w.show();

    return a.exec();
}
