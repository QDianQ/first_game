#ifndef CCELL_H
#define CCELL_H


class CCell
{
public:
    CCell();
    //~CCell();
//    void find_cell(int **mass, int N);
//    void edit_XY(int direction, int **mass, int N);
//    void getCorrectPositionBtn(int (&CorrectPosition)[4][2]);
    void setPos(int x, int y);
    void setID(int id);
    void getPos(int *x, int *y);
    int getID();
protected:
//    int posZeroX, posZeroY; //координаты нуля
    int X, Y, ID;
};

#endif // CCELL_H
