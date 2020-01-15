#include <iostream>
#include "cgamefield.h"
#include "conio.h"
#include "ccell.h"

using namespace std;

int main()
{

    CGameField *game = new CGameField;    //Размер матрицы

    game->create_field();
    game->show_field();
    game->swap_numbers();
    printf(" Excellent!\n You win!\n");

    return 0;
}
