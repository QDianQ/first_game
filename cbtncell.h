#ifndef CBTNCELL_H
#define CBTNCELL_H

#include "ccell.h"
#include "cgamefield.h"
#include <QPushButton>

class CBtnCell : public CCell, public QPushButton   //наверняка я неправильно делаю наследование
{                                                   //если пройти дебагером внутри этого класса, то приложение вылетает
                                                    //а если запускать без дебагера, то не вылетает5
public:
     CBtnCell();
    void updBtnPos(int *ID);

protected:
    int posBtnX, posBtnY;                           //в эти переменные записываю координаты нуля, которые передаю через массив *ID
};

#endif // CBTNCELL_H
