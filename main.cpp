#include <iostream>
#include "cgamefield.h"
#include "conio.h"
#include "ccell.h"

#include <QApplication>
#include "mainwindow.h"

using namespace std;

//int main()
//{
//    QApplication a();
//    CGameField *game = new CGameField;    //Размер матрицы

//    game->create_field();
//    game->show_field();
//    game->swap_numbers();
//    printf(" Excellent!\n You win!\n");



//    return 0;
//}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

