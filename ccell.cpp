#include "ccell.h"
#include <iostream>

CCell::CCell()
{

}

void CCell::find_cell(int **mass, int N, int *ID)    //поиск координат нуля для перемены местами нуля и нужной нам цифры
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mass[i][j]==0){
                posX=i;
                posY=j;
                break;
            }
        }
    }
    ID[0]=posX;
    ID[1]=posY;
}

void CCell::edit_XY(char direction, int **mass,int N)
{
    if(direction=='w'){
        if (posX!=0){
            mass[posX][posY]=mass[posX-1][posY];
            mass[posX-1][posY]=0;
            posX--;
        }
    }
    if(direction=='s'){
        if(posX!=N-1){
            mass[posX][posY]=mass[posX+1][posY];
            mass[posX+1][posY]=0;
            posX++;
        }
    }
    if(direction=='a'){
        if(posY!=0){
            mass[posX][posY]=mass[posX][posY-1];
            mass[posX][posY-1]=0;
            posY--;
        }
    }
    if(direction=='d'){
        if(posY!=N-1){
            mass[posX][posY]=mass[posX][posY+1];
            mass[posX][posY+1]=0;
            posY++;
        }
    }
}
