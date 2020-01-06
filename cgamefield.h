#ifndef CGAMEFIELD_H
#define CGAMEFIELD_H


class CGameField
{
public:


    CGameField(int n = 0);
    ~CGameField();
    void create_field();
    void show_field();
    void random_field();
protected:
    int N,*buf;
    int **mass;
};

#endif // CGAMEFIELD_H
