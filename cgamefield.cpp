#include "cgamefield.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

CGameField::CGameField(int n)
{
    printf("enter size of field: "); //Ввод размера поля
    scanf("%d",&N);

    srand(time(NULL));
    mass = new int* [N];
    for (int i = 0; i < N; i++)     //формирование двумерного массива
        mass[i] = new int [N];
}
CGameField::~CGameField()
{
    if(N!=0){
       for (int i=0;i < N; i++)
           delete [] mass[i];
       delete [] mass;
    }

}
void CGameField::create_field()
{
    int count = 0;
    for(int i = 0; i<N; i++){       //заполнение двумерного массива рандомными числами
        for(int j = 0; j < N; j++){
        mass[i][j]= 0 + rand() % (N*N);
        count++;
        }
    }
}
void CGameField::show_field()
{
    for (int i = 0; i < N; i++){       //Вывод матрицы на экран в понятном виде для пользователя
        for (int j = 0; j < N; j++){


            if (j<N-1)
               printf("%d ", mass[i][j]);
            else
                printf("%d\n", mass[i][j]);
        }
    }
}
void CGameField::random_field()
{
    //Перемешать значения в матрице в рандомном порядке
}
