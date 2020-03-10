#include <iostream>
#include "conio.h"
#include "cdialogentersize.h"
#include <QApplication>
#include "mainwindow.h"
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    bool restart=false;
    do{
        QApplication a(argc, argv);

        CDialogEnterSize *dialogEnterSize = new CDialogEnterSize;
        int N = dialogEnterSize->exec();

        MainWindow w;
        w.setSizeField(N);
        w.show();
        a.exec();
        ///> переменная createNewGame избыточна. Мы говорили,
        /// что можно использовать просто различные аргументы (exit).
        /// Значение этого аргумента можно получать из самого метода exec()
        restart=w.createNewGame;
    }while(restart);


return 0;


}

