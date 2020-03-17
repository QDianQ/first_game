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
};

#endif // CBTNCELL_H
