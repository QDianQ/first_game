#include <iostream>
#include "cgamefield.h"
#include "func_rand.h"
#include "conio.h"
#include "ccell.h"

using namespace std;

int main()
{

    CGameField *game = new CGameField;    //Размер матрицы
//    CCell *cell = new CCell;

    game->create_field();
    game->show_field();
//    cell->find_cell(game->mass,game->N);
    game->swap_numbers();
    printf(" Excellent!\n You win!\n");



    return 0;
}
