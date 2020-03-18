#ifndef CCELL_H
#define CCELL_H


class CCell
{
public:
    CCell();
    //~CCell();
    void setPos(int x, int y);
    void setID(int id);
    void getPos(int *x, int *y);
    int getID();
protected:
    int X, Y, ID;
};

#endif // CCELL_H
