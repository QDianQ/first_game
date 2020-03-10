#include "ccell.h"
#include <iostream>

CCell::CCell()
{

}

void CCell::find_cell(int **mass, int N)    //поиск координат нуля для перемены местами нуля и нужной нам цифры
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mass[i][j]==0){
                posZeroX=i;
                posZeroY=j;
                break;
            }
         }
    }
}
void CCell::getCorrectPositionBtn(int (&CorrectPosition)[4][2])
{

        CorrectPosition[0][0]=posZeroX-1;    //верх
        CorrectPosition[0][1]=posZeroY;

        CorrectPosition[1][0]=posZeroX+1;    //низ
        CorrectPosition[1][1]=posZeroY;

        CorrectPosition[2][0]=posZeroX;      //право
        CorrectPosition[2][1]=posZeroY+1;

        CorrectPosition[3][0]=posZeroX;      //лево
        CorrectPosition[3][1]=posZeroY-1;
}

void CCell::edit_XY(int direction, int **mass,int N)
{
    if(direction==0){   //верх
        if (posZeroX!=0){
            mass[posZeroX][posZeroY]=mass[posZeroX-1][posZeroY];
            mass[posZeroX-1][posZeroY]=0;
            posZeroX--;
        }
    }
    if(direction==1){     //низ
        if(posZeroX!=N-1){
            mass[posZeroX][posZeroY]=mass[posZeroX+1][posZeroY];
            mass[posZeroX+1][posZeroY]=0;
            posZeroX++;

        }
    }
    if(direction==2){     //право
        if(posZeroY!=N-1){
            mass[posZeroX][posZeroY]=mass[posZeroX][posZeroY+1];
            mass[posZeroX][posZeroY+1]=0;
            posZeroY++;
        }
    }
    if(direction==3){     //лево
        if(posZeroY!=0){
            mass[posZeroX][posZeroY]=mass[posZeroX][posZeroY-1];
            mass[posZeroX][posZeroY-1]=0;
            posZeroY--;
        }
    }

}
