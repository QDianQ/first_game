#ifndef CCELL_H
#define CCELL_H


class CCell
{
public:
    CCell();
    void find_cell(int **mass, int N);
    void edit_XY(int direction,int **mass,int N);

protected:
    int x, y; //координаты нуля
};

#endif // CCELL_H
