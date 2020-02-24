#ifndef CGAMEFIELD_H
#define CGAMEFIELD_H

class CCell;
class CGameField
{
public:

    /// > Зачем в каждой функции передавать N,
    /// если оно является атрибутом класса,
    /// к которому всегда есть доступ изнутри класса?


    CGameField(int N,CCell *zeroCCell=nullptr);
    ~CGameField();
    void create_field(int N);        //создать игровое поле
    void show_field();          //вывести игровое поле на экран
    char direction;             //направление перемещения нуля

    int *buf;              //ID - массив для хранения координат нуля
                                //вынес buf в public, чтобы использовать значений этого массива для заполнения кнопок

protected:
    int N,  *mass_converted; //N-размерность матрицы,buf-массив с рандомными числами,mass_converted-массив для конвертирования двумерного массива в одномерный
    int **mass;                 //двумерный массив пятнашек
    CCell *cell;
};

#endif // CGAMEFIELD_H
