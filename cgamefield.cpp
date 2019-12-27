#include "cgamefield.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "func_rand.h"

CGameField::CGameField(int n)
{
    printf("enter size of field: "); //Ввод размера поля
    scanf("%d",&N);

    srand(time(NULL));
    mass = new int* [N];
    for (int i = 0; i < N; i++)     //формирование двумерного массива
        mass[i] = new int [N];
    buf = new int[N*N];

    f_rand(buf,N);          //формирование массива цифр без повторений
}
CGameField::~CGameField()
{
    if(N!=0){
       for (int i=0;i < N; i++)
           delete [] mass[i];
       delete [] mass;
    }
    delete [] buf;

}
void CGameField::create_field()
{
    int count = 0;
    for(int i = 0; i<N; i++){       //заполнение двумерного массива рандомными числами
        for(int j = 0; j < N; j++){
        mass[i][j]= buf[count];
        count++;
        }
    }
}
void CGameField::show_field()
{
    for (int i = 0; i < N; i++){       //Вывод матрицы на экран в понятном виде для пользователя
        for (int j = 0; j < N; j++){


            if (j<N-1)
               printf("%-5d", mass[i][j]);
            else
                printf("%d\n\n", mass[i][j]);
        }
    }
}
void CGameField::random_field()
{
    //Перемешать значения в матрице в рандомном порядке
}
