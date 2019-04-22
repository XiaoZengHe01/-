#include <QApplication>
#include "MyDialog/MyDialog.h"


int main(int Argc,char** Argv)
{
    QApplication App(Argc,Argv);
    MyDialog w;
    w.show();
    return  App.exec();
}
