#include <iostream>
#include "conio.h"
#include "cdialogentersize.h"
#include <QApplication>
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    CDialogEnterSize *dialogEnterSize = new CDialogEnterSize;

    w.show();
    dialogEnterSize->show();



    return a.exec();
}

