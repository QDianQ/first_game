#ifndef CBTNCELL_H
#define CBTNCELL_H

#include "ccell.h"
#include "cgamefield.h"
#include <QPushButton>

class CBtnCell : public CCell
{

public:
     CBtnCell();
    void updBtnPos(int *ID);

protected:
    int posBtnX, posBtnY;
};

#endif // CBTNCELL_H
