#include "bucmain.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BucMain w;
    w.show();

    return a.exec();
}
