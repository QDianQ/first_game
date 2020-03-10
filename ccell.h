#ifndef CCELL_H
#define CCELL_H


class CCell
{
public:
    CCell();
    //~CCell();
    void find_cell(int **mass, int N);
    void edit_XY(int direction, int **mass, int N);
    void getCorrectPositionBtn(int (&CorrectPosition)[4][2]);

protected:
    int posZeroX, posZeroY; //координаты нуля

};

#endif // CCELL_H
