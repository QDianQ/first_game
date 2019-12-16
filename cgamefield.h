#ifndef CGAMEFIELD_H
#define CGAMEFIELD_H


class CGameField
{
public:
    int N;
    int **mass;

    CGameField(int n = 0);
    ~CGameField();
    void create_field();
    void show_field();
    void random_field();
};

#endif // CGAMEFIELD_H
