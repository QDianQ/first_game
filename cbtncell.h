#ifndef CBTNCELL_H
#define CBTNCELL_H

#include "ccell.h"
#include "cgamefield.h"
#include <QPushButton>

/// > Чтобы не нарушать логику работы Qt-шных библиотек, нуджно их родительские классы указывать в первую очередь
/// т.е. сначала QPushButton, затем CCell. И соблюдать это в конструкторах
class CBtnCell : public QPushButton, public CCell   //наверняка я неправильно делаю наследование
{                                                   //если пройти дебагером внутри этого класса, то приложение вылетает
                                                    //а если запускать без дебагера, то не вылетает5
    Q_OBJECT /// > Нужно не заывать про этот макрос, он важен для сигналов / слотов

public:
    explicit CBtnCell(QWidget *parent = nullptr); // > В конструкторе желательно получать все аргументы, которые требуются конструкторам родительских классов
    explicit CBtnCell(const QString &text, QWidget *parent = nullptr);
    void updBtnPos(int *ID);

protected:
    int posBtnX, posBtnY;                           //в эти переменные записываю координаты нуля, которые передаю через массив *ID
    /// > Если ты под этими переменными полагаешь аналоги posX, PosY из CCell
    /// То они не нужны, ты можешь в этом классе использовать,
    /// без дополнительного объявления, аттрибуты и методы объявленные в
    /// родительском классе (CCell, QPushButton). В этом основная соль наследования
};

#endif // CBTNCELL_H
