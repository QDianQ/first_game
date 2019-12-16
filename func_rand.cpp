#include "func_rand.h"
#include <stdlib.h>
#include <iostream>

int f_rand(int min,int max)     //функция для рандома чисел без повтора и записи в массив
{

    int r,count=0,*buf;     //r - рандомное число, count - счетчик кол-ва цифр в массиве, которые не повторяются, buf - массив
    for (int i=0; i < max; i++){
        buf[i] = min + rand() % max;

        for (int j=0; count < max; j++){
            r = min + rand() % max;
            if (buf[j]!=r){
                buf[i]=r;
                count ++;
                break;
            }
        }
    }
    return *buf;
}
