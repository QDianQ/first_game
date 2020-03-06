#ifndef CGAMEFIELD_H
#define CGAMEFIELD_H

class CCell;
class CGameField
{
public:

    CGameField(int N,CCell *zeroCCell=nullptr);
    ~CGameField();
    void createField();        //создать игровое поле
    void movementOnField(int direction);        //движение по полю
    bool checkOfWinGame();  //проверка на победу
    int *buf;              //вынес buf в public, чтобы использовать значений этого массива для заполнения кнопок

protected:
    int sizeN, *mass_converted; //N-размерность матрицы,buf-массив с рандомными числами,mass_converted-массив для конвертирования двумерного массива в одномерный
    int **mass;                 //двумерный массив пятнашек
    CCell *cell;
};

#endif // CGAMEFIELD_H
