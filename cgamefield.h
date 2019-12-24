#ifndef CGAMEFIELD_H
#define CGAMEFIELD_H


class CGameField
{
public:
    // * Это стоит убрать в protected
    // >-----------------------------
    int N, *buf;
    int **mass;
    // ----------------------------->

    CGameField(int n = 0);
    ~CGameField();
    void create_field();
    void show_field();
    void random_field();

    // * Нужна функция приводящая mass к виду buf и наоборот
    // * Будет полезно для проверки на победу
};

#endif // CGAMEFIELD_H
