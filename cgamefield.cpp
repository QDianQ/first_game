#include "cgamefield.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "additional_function.h"
#include "ccell.h"

CGameField::CGameField(
        int N,
        CCell *zeroCCell/*=nullptr*/
        )
{
    srand(time(NULL));
    mass = new int* [N];
    for (int i = 0; i < N; i++)     //формирование двумерного массива
        mass[i] = new int [N];
    buf = new int[N*N];
    mass_converted = new int[N*N];

    f_rand(buf,N);          //формирование массива цифр без повторений
    static bool flagCreateCell = false;
    if (zeroCCell==nullptr){
           flagCreateCell = true;
           cell = new CCell;
           }
    else
           cell=zeroCCell;

}
CGameField::~CGameField()
{
    if(N!=0){
       for (int i=0;i < N; i++)
           delete [] mass[i];
       delete [] mass;
    }
    delete [] buf;
    delete [] mass_converted;
    static bool flagCreateCell;
    if (flagCreateCell==true)
            delete cell;            
}
void CGameField::create_field(int N)
{
    int count = 0;
    for(int i = 0; i<N; i++){       //заполнение двумерного массива рандомными числами
        for(int j = 0; j < N; j++){
        mass[i][j]= buf[count];
        count++;
        }
    }
    cell->find_cell(mass,N);
}
void CGameField::show_field()
{
    f_show_field(mass,N);       //вывод игрового поля на экран
}
