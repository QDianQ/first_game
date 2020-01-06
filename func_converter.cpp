#include <iostream>
#include "func_converter.h"
#include "cgamefield.h"

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
