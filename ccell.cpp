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
void CCell::edit_XY(int direction,int **mass,int N)
{
    if(direction=='w'){
        if (x!=0){
            mass[x][y]=mass[x-1][y];
            mass[x-1][y]=0;
            x--;
        }
    }
    if(direction=='s'){
        if(x!=N-1){
            mass[x][y]=mass[x+1][y];
            mass[x+1][y]=0;
            x++;
        }
    }
    if(direction=='a'){
        if(y!=0){
            mass[x][y]=mass[x][y-1];
            mass[x][y-1]=0;
            y--;
        }
    }
    if(direction=='d'){
        if(y!=N-1){
            mass[x][y]=mass[x][y+1];
            mass[x][y+1]=0;
            y++;
        }
    }
}
