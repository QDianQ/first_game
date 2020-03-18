#include "crandmove.h"
#include <stdlib.h>
#include "ccell.h"
#include "iostream"

CRandMove::CRandMove(CCell *zeroCell)
{    
    zeroCell->getPos(&X,&Y);
}
bool CRandMove::getRandPosition(int *x, int *y,int size)
{
    int correctPosition[4][2];
    getCorrectPositionCell(correctPosition);

    while(true){
        int randomDirection = 0 + rand() % 4;

        *x = correctPosition[randomDirection][0];
        *y = correctPosition[randomDirection][1];

        switch (randomDirection) {
        case 0 :
            if (*y>=0)
                return true;
            break;
        case 1:
            if(*y<size)
                return true;
            break;
        case 2:
            if(*x<size)
                return true;
            break;
        case 3:
            if(*x>=0)
                return true;
            break;
        }
    }
}
void CRandMove::getCorrectPositionCell(int (&CorrectPosition)[4][2])
{
    CorrectPosition[0][0]=X;        //верх
    CorrectPosition[0][1]=Y-1;

    CorrectPosition[1][0]=X;        //низ
    CorrectPosition[1][1]=Y+1;

    CorrectPosition[2][0]=X+1;      //право
    CorrectPosition[2][1]=Y;

    CorrectPosition[3][0]=X-1;      //лево
    CorrectPosition[3][1]=Y;

}
