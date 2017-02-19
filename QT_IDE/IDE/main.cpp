#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //定义了一个QApplication的实例，同时使用构造函数并传入参数来初始化。
    Widget w;                   //定义了一个Widget实例，名字叫w
    w.show();

    return a.exec();
}
