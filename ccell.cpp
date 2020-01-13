#include "ccell.h"
#include "cgamefield.h"

CCell::CCell()
{

}
void CCell::find_cell(int **mass, int N)    //поиск координат нуля для перемены местами нуля и нужной нам цифры
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mass[i][j]==0){
                x=i;
                y=j;
                break;
            }
        }
    }
}
void CCell::edit_xy(int direction, int **mass)
{
    if (direction==1){
        if (x!=0){
            mass[x][y]=mass[x-1][y];
            mass[x-1][y]=0;
        }
    }
}
