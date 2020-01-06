#include <iostream>
#include "cgamefield.h"
#include "func_rand.h"
#include "conio.h"

using namespace std;

int main()
{

    CGameField *game = new CGameField;    //Размер матрицы

    game->create_field();
    game->show_field();
    game->swap_numbers();
    printf("Excellent!\nYou win!\n");



    return 0;
}
