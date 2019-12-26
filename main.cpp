#include <iostream>
#include "cgamefield.h"
#include "func_rand.h"

using namespace std;

int main()
{

    CGameField *game = new CGameField;    //Размер матрицы

    game->create_field();
    game->show_field();


    //вызов функции (ради проверки работает ли она как надо или нет)

    return 0;
}
