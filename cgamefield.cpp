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
//    if (zeroCCell==nullptr){
//         flagCreateCell = true;
//         cellMass = new CCell;
//         }
//    else
//        cellMass=zeroCCell;
    cellMass = new CCell*[N*N];

    countCell=0;
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
//    if (flagCreateCell==true)
    delete cellMass;
}

bool CGameField::addCell(CCell *cell, int posX, int posY, int id)
{
    if(countCell==sizeN*sizeN){
        return false;
    }

    cell->setPos(posX,posY);
    cell->setID(id);
    cellMass[id]=cell;

    if(id==0){
        zeroCellptr=cell;
    }

    countCell++;

    return true;
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
//    cell->find_cell(mass,sizeN);
    find_cell();
}
bool CGameField::movementOnField(int id)
{
    if(swap(id)){
        f_convert(mass_converted,mass,sizeN);
        return true;
    }
    return false;
}
bool CGameField::checkOfWinGame()
{
    bool check=f_check_win(mass_converted,sizeN);
    return check;
}
void CGameField::find_cell()    //поиск координат нуля для перемены местами нуля и нужной нам цифры
{
    for(int i=0;i<sizeN;i++){
        for(int j=0;j<sizeN;j++){
            if(mass[i][j]==0){
                posZeroX=j;
                posZeroY=i;
                break;
            }
         }
    }
}
void CGameField::getCorrectPositionBtn(int (&CorrectPosition)[4][2])
{
//    find_cell();
        CorrectPosition[0][0]=posZeroX;    //верх
        CorrectPosition[0][1]=posZeroY-1;

        CorrectPosition[1][0]=posZeroX;    //низ
        CorrectPosition[1][1]=posZeroY+1;

        CorrectPosition[2][0]=posZeroX+1;      //право
        CorrectPosition[2][1]=posZeroY;

        CorrectPosition[3][0]=posZeroX-1;      //лево
        CorrectPosition[3][1]=posZeroY;
}
bool CGameField::swap(int id)
{
    if(countCell!=sizeN*sizeN and id<sizeN*sizeN){
        return false;
    }
    CCell *cell = cellMass[id];

    int correctPos[4][2];
    getCorrectPositionBtn(correctPos);

    int cellPositionX, cellPositionY;
    cell->getPos(&cellPositionX,&cellPositionY);


    for(int i=0;i<4;i++){
        if(cellPositionX==correctPos[i][0] and cellPositionY==correctPos[i][1]){
            //выбор направления
            switch (i) {

                case 0:
//                  qDebug() << "up";
                    cell->setPos(cellPositionX,cellPositionY+1);
                    zeroCellptr->setPos(cellPositionX,cellPositionY);

                    mass[posZeroY][posZeroX]=mass[posZeroY-1][posZeroX];
                    mass[posZeroY-1][posZeroX]=0;
                    posZeroY--;


                return true;

                case 1:
//                  qDebug() << "down";
                    cell->setPos(cellPositionX,cellPositionY-1);
                    zeroCellptr->setPos(cellPositionX,cellPositionY);

                    mass[posZeroY][posZeroX]=mass[posZeroY+1][posZeroX];
                    mass[posZeroY+1][posZeroX]=0;
                    posZeroY++;

                return true;

                case 2:
//                  qDebug() << "right";
                    cell->setPos(cellPositionX-1,cellPositionY);
                    zeroCellptr->setPos(cellPositionX,cellPositionY);

                    mass[posZeroY][posZeroX]=mass[posZeroY][posZeroX+1];
                    mass[posZeroY][posZeroX+1]=0;
                    posZeroX++;

                return true;

                case 3:
//                  qDebug() << "left";
                    cell->setPos(cellPositionX+1,cellPositionY);
                    zeroCellptr->setPos(cellPositionX,cellPositionY);

                    mass[posZeroY][posZeroX]=mass[posZeroY][posZeroX-1];
                    mass[posZeroY][posZeroX-1]=0;
                    posZeroX--;

                return true;
            }
        }
    }
    return false;
}
bool CGameField::getCell(CCell &cell, int posX, int posY)
{
    if(posX<0 or posY<0)
        return false;
    if(countCell<sizeN*sizeN)
        return false;
    int X,Y;
    for(int i=0;i<sizeN*sizeN;i++){
        cellMass[i]->getPos(&X,&Y);
        if(X==posX and Y==posY){
            cell=*cellMass[i];
            return true;
        }
    }
    return false;
}

