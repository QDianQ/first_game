#ifndef CCELL_H
#define CCELL_H


class CCell
{
public:
    CCell();
    //~CCell();
    void find_cell(int **mass, int N, int *ID);
    void edit_XY(char direction, int **mass, int N);

protected:
    int posX, posY; //координаты нуля
};

#endif // CCELL_H
