#ifndef CGAMEFIELD_H
#define CGAMEFIELD_H


class CGameField
{
public:


    CGameField(int n = 0);
    ~CGameField();
    void create_field();
    void show_field();
    void check_win();
protected:
    int N,*buf,*mass_converted;
    int **mass;
};

#endif // CGAMEFIELD_H
