#include "func_rand.h"
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>


void f_rand(int *buf,int size)     //функция для рандома чисел без повтора и записи в массив
{

    int tmp;    //переменная для рандомного числа
    int count=0;     //счетчик кол-ва совпадающих чисел в массиве

    srand(time(NULL));

    for (int i=0; i < (size*size); i++){    //логика функции предполагалась такой:
        tmp = 0 + rand() % (size*size);     //рандомится число

        for(int j=0; j < (size*size); j++){     //далее цикл для сравнения рандомного числа tmp с каждым значением ячейки массива
            count=0;
            if(buf[j]==tmp){                //условие: если число tmp совпадает с числом в ячейке, то инкрементировать count
                count++;
            }
            if(count==0){                   //условие: если count равен нулю, тогда в ячейку массива присвоить значение tmp
                buf[i]=tmp;
                break;                      //и выйти из цикла сразу, как в ячейку было записано tmp
            }
        }
    }

    for (int i=0;i<size*size;i++)   //временный цикл для вывода на экран, чтобы убедиться в правильности формирования массива
        std::cout << buf[i] << std::endl;
}
