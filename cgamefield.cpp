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

    sizeN=N;

}
CGameField::~CGameField()
{
    int N=sizeN;
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

void CGameField::createField()
{
    int count = 0;
    for(int i = 0; i<sizeN; i++){       //заполнение двумерного массива рандомными числами
        for(int j = 0; j < sizeN; j++){
        mass[i][j]= buf[count];
        count++;
        }
    }
    cell->find_cell(mass,sizeN);
}

void CGameField::movementOnField(int direction)
{
    ///> Близко к сути, но протаскивание логики через объект
    /// конкретной ячейки - это не корректно.
    /// Идея была в том, что данный метод должен принимать, по сути
    /// не направление а номер ячейки, которая меняется с нулевой.
    /// И в зависимости от положения нулевой ячейки, нужно либо
    /// выполнять перемещение (обновить XY у соответствующих ячеек)
    /// и возвращать True. Либо False, если это не допустимый ход.
    /// Для этого у тебя должен быть массив ВСЕХ CCell-ов на игровом поле
    /// и ещё дополнительно указатель на элемент этого массива, соответствующий
    /// нулевой клетки, для удобства обращения. На этот массив должно проецироваться
    /// изменение конфигурации поля (mas), путём обновления XY каждой ячейки.
    /// Причём массив CCell-ов должен либо инициализироваться внутри (если мы не
    /// используем интерфейс, либо передаваться снаружи если используем)
    cell->edit_XY(direction,mass,sizeN);
    f_convert(mass_converted,mass,sizeN);
}

bool CGameField::checkOfWinGame()
{
    bool check=f_check_win(mass_converted,sizeN);
    return check;
}
