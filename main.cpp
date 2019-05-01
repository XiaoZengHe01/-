#include <QApplication>
#include "TestWidget/TestWidget.h"


int main(int Argc,char** Argv)
{
    QApplication App(Argc,Argv);
TestWidget w;
w.show();
    return App.exec();
}
