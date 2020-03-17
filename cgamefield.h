#ifndef CGAMEFIELD_H
#define CGAMEFIELD_H

class CCell;
class CGameField
{
public:

    CGameField(int N,CCell *zeroCCell=nullptr);
    ~CGameField();
    void createField();        //создать игровое поле
    bool movementOnField(int id);        //движение по полю
    bool checkOfWinGame();  //проверка на победу
    int *buf;              //вынес buf в public, чтобы использовать значений этого массива для заполнения кнопок

    void find_cell();
    void getCorrectPositionBtn(int (&CorrectPosition)[4][2]);
    bool swap(int id);
    bool addCell(CCell *cell, int posX, int posY, int id);
    bool getCell(CCell *cell, int posX, int posY);
    int countCell;      //счетчик заполнения cellMass       ||временно


protected:
    int sizeN, *mass_converted; //N-размерность матрицы,buf-массив с рандомными числами,mass_converted-массив для конвертирования двумерного массива в одномерный
    int **mass;                 //двумерный массив пятнашек
    CCell **cellMass, *zeroCellptr;
    int posZeroX, posZeroY; //координаты нуля

};

#endif // CGAMEFIELD_H
