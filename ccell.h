#ifndef CCELL_H
#define CCELL_H


class CCell
{
public:
    CCell();
    void find_cell(int **mass, int N);
    void edit_xy(int direction,int **mass);

protected:
    int x, y; //координаты нуля

};

#endif // CCELL_H
