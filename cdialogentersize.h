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
    int checkValue(); //метод проверяющий одинаковые ли значения в SpinBox и enterSizeField

public slots:
    void getSizeField(int); //слот для записи enterSizeField при взаимодействии с SpinBox
    void onClickOkeyBtn();  //слот, который проверяет введен ли размер поля, и если соответсвует условию checkValue, то закрывает диалог
    void onClickCloseBtn();
};

#endif // CDIALOGENTERSIZE_H
