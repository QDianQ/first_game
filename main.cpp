#include <iostream>
#include "cgamefield.h"
#include "func_rand.h"

using namespace std;

int main()
{

    CGameField *game = new CGameField;    //Размер матрицы

    game->create_field();
 //   game->show_field();

//    for ( int i = 0; i < game->N; i++){       //Вывод матрицы на экран в понятном виде для пользователя
//        for ( int j = 0; j < game->N; j++){
//            cout << game->mass[i][j] << endl;
//        }
//    }

    //вызов функции (ради проверки работает ли она как надо или нет)
    f_rand(game->buf,game->N);
    return 0;
}
