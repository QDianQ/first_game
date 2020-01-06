#include <iostream>
#include "func_check_win.h"
#include "cgamefield.h"

bool f_check_win(int *mass_converted, int size)  //функция проверки условаия победы
{
    int count=0;    //счетчик кол-ва правильных цифр в массиве
    for(int i=0;i<size*size;i++){
        if(mass_converted[i]==i)
            count++;
    }
    if (count==size*size)  //если кол-во правильных цифр совпадает с размером массива
        return 1;           // то вернуть true
    else                  //иначе
        return 0;           //вернуть false

}
