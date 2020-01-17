#ifndef CGAMEFIELD_H
#define CGAMEFIELD_H


class CGameField
{
public:


    CGameField(int n = 0);
    ~CGameField();
    void create_field();        //создать игровое поле
    void show_field();          //вывести игровое поле на экран
    void swap_numbers();        //перемещение нуля по игровому полю
    char direction;             //направление перемещения нуля
protected:
    int N, *buf, *mass_converted; //N-размерность матрицы,buf-массив с рандомными числами,mass_converted-массив для конвертирования двумерного массива в одномерный
    int **mass;                 //двумерный массив пятнашек
};

#endif // CGAMEFIELD_H
