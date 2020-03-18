#include "cbtncell.h"

/// > Реализуем стандартные конструкторы, необходимые для QPushButton
CBtnCell::CBtnCell(QWidget *parent)
    : QPushButton(parent),
      CCell()
{

}

CBtnCell::CBtnCell(const QString &text, QWidget *parent)
    : QPushButton(text, parent),
      CCell()
{

}

