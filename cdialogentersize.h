#ifndef CDIALOGENTERSIZE_H
#define CDIALOGENTERSIZE_H

#include <QDialog>
#include <QSpinBox>

class CDialogEnterSize: public QDialog
{
    Q_OBJECT

public:
    CDialogEnterSize(QWidget *parent=0);
    int enterSizeField=-1; //переменная для хранения размера поля, которая потом будет передваться
protected:
    QSpinBox *spinBoxEnterSize;

public slots:
    void onClickOK();
    void __attribute__((noreturn)) onClickClose();
};

#endif // CDIALOGENTERSIZE_H
