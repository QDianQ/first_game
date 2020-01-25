#ifndef CBTNCELL_H
#define CBTNCELL_H

#include "ccell.h"

class CBtnCell : public CCell
{
public:
    CBtnCell();
    void updBtnPos();
protected:
    int posBtnX, posBtnY;
};

#endif // CBTNCELL_H
