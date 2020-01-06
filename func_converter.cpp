#include <iostream>
#include "func_converter.h"
#include "cgamefield.h"

void f_convert(int *mass_converted, int **mass,int size)
{
    for(int i=0;i<size*size;i++){
        static int n=0,m=0;
        mass_converted[i]=mass[n][m];
        m++;
        if (m==size){
            m=0;
            n++;
        }
        printf("%d ",mass_converted[i]);
    }
}
