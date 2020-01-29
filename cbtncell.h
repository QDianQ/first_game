#ifndef CBTNCELL_H
#define CBTNCELL_H

#include "ccell.h"
#include <QPushButton>

class CBtnCell : public CCell, public QPushButton
{

public:
    CBtnCell();
    void updBtnPos();
protected:
    int posBtnX, posBtnY;
};

#endif // CBTNCELL_H
