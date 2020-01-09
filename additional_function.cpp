#include <iostream>
#include "cgamefield.h"
#include "windows.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

bool f_check_win(int *mass_converted, int size)  //функция проверки условаия победы
{
    int count=0;                            //счетчик кол-ва правильных цифр в массиве
    for(int i=0;i<size*size;i++){
        if(mass_converted[i]==i)
            count++;
    }
    if (count==size*size)                   //если кол-во правильных цифр совпадает с размером массива
        return 1;                           // то вернуть true
    else                                    //иначе
        return 0;                           //вернуть false

}

void f_convert(int *mass_converted, int **mass,int size)    //функция конвертирующая двумерный массив в одномерный
{
    int n=0,m=0;
    for(int i=0;i<size*size;i++){
        mass_converted[i]=mass[n][m];
        m++;
        if (m==size){
            m=0;
            n++;
        }
    }
}

void f_show_field(int **mass,int size)      //функция вывода матрицы на экран
{
    system("CLS");
    printf("\n");
    for (int i = 0; i < size; i++){         //Вывод матрицы на экран в понятном виде для пользователя
        for (int j = 0; j < size; j++){


            if (j<size-1)
               printf("%5d", mass[i][j]);
            else
                printf("%5d\n\n", mass[i][j]);
        }
    }
}
void f_rand(int *buf,int size)              //функция для рандома чисел без повтора и записи в массив
{

    int tmp;                                //переменная для рандомного числа
    bool flag=false;                        //флаг определяющий были ли повторения при рандоме числа


    srand(time(NULL));


    for (int i=0; i < (size*size); i++){    //логика функции предполагалась такой:
        tmp = 0 + rand() % (size*size);     //рандомится число
        flag=0;                             //обнуляется флаг

        for(int j=0; j < i; j++){           //далее цикл для сравнения рандомного числа tmp с каждым значением ячейки массива
            if(buf[j]==tmp){                //условие: если число tmp совпадает с числом в ячейке, то
                flag=1;                     //установить флаг повторения
                i--;                        //и вернутся на одно значение назад по i
                break;
            }
        }

        if(flag==0){                        //условие: если flag равен нулю, тогда
            buf[i]=tmp;                     //в ячейку массива присвоить значение tmp
        }
    }
}
