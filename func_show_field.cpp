#include <iostream>
#include "func_show_field.h"
#include "cgamefield.h"
#include "windows.h"

void f_show_field(int **mass,int size)
{
    system("CLS");
    printf("\n");
    for (int i = 0; i < size; i++){       //Вывод матрицы на экран в понятном виде для пользователя
        for (int j = 0; j < size; j++){


            if (j<size-1)
               printf("%5d", mass[i][j]);
            else
                printf("%5d\n\n", mass[i][j]);
        }
    }
}
