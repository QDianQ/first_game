#include <iostream>
#include "conio.h"
#include "cdialogentersize.h"
#include <QApplication>
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        CDialogEnterSize *dialogEnterSize = new CDialogEnterSize;
        int N = dialogEnterSize->exec();
//        cout << N << endl;
        if (N > 2){
            MainWindow w;
            w.setSizeField(N);    //не уверен, что вот так передавать значение - корректно
            w.show();
            return a.exec();
        }else
             return 0;
}

