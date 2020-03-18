#ifndef CRANDMOVE_H
#define CRANDMOVE_H

class CCell;
class CRandMove
{
public:
    CRandMove(CCell *zeroCell);
    bool getRandPosition(int *x, int *y, int size);
    void getCorrectPositionCell(int (&CorrectPosition)[4][2]);
protected:
    int X,Y;
};

#endif // CRANDMOVE_H
