#include "cgamefield.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "additional_function.h"
#include "ccell.h"

CGameField::CGameField(int N)
{
//    printf("enter size of field: "); //Ввод размера поля
//    scanf("%d",&N);

    srand(time(NULL));
    mass = new int* [N];
    for (int i = 0; i < N; i++)     //формирование двумерного массива
        mass[i] = new int [N];
    buf = new int[N*N];
    mass_converted = new int[N*N];

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
    delete [] mass_converted;

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
    f_show_field(mass,N);       //вывод игрового поля на экран
}
void CGameField::swap_numbers()
{
    char key[10];           //переменная для указания направления движения

    bool check=false;         //переменная для определения победы

    CCell *cell = new CCell;
    cell->find_cell(mass,N);    //вывов метода поиска ячейки с нулем

    while(check!=true){

        printf(" press key: ");
        scanf("%s",&key);
        std::cout << std::endl;
        switch (key[0]) {      //управление клавишами w,a,s,d
                case 'w':
                case 's':
                case 'a':
                case 'd':
                    // Все варианты идентичны, при таком построении функции cell->edit_XY
                    cell->edit_XY(key[0],mass,N);
                    f_show_field(mass,N);
                    f_convert(mass_converted,mass,N);
                    check=f_check_win(mass_converted,N);
                    break;

        default:
            printf("Use keys: w,a,s,d\n");
        }
    }
    delete cell;
}
