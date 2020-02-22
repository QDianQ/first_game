#include "cdialogentersize.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>

CDialogEnterSize::CDialogEnterSize(QWidget *parent)
    : QDialog(parent)
{
    QLabel *label = new QLabel("Enter size of puzzle");
    spinBoxEnterSize = new QSpinBox;
    QPushButton *okBtn = new QPushButton("&Okey");
    QPushButton *closeBtn = new QPushButton("&Close");

    QHBoxLayout *left_layout = new QHBoxLayout;
    left_layout->addWidget(label);
    left_layout->addWidget(spinBoxEnterSize);

    QVBoxLayout *right_layout = new QVBoxLayout;
    right_layout->addWidget(okBtn);
    right_layout->addWidget(closeBtn);

    QHBoxLayout *main_layout = new QHBoxLayout;
    main_layout->addLayout(left_layout);
    main_layout->addLayout(right_layout);

    setLayout(main_layout);
    connect(spinBoxEnterSize, SIGNAL(valueChanged(int)), this, SLOT(getSizeField(int)));
    connect(okBtn, SIGNAL(clicked()), this, SLOT(onClickOkeyBtn()));
    connect(closeBtn, SIGNAL(clicked()), this, SLOT(onClickCloseBtn()));
}

//метод проверяющий одинаковые ли значения в SpinBox и enterSizeField
int CDialogEnterSize::checkValue()
{
    if (spinBoxEnterSize->value() == enterSizeField and enterSizeField>=3)
        return 1;
    else
        return 0;

}

//слот, который проверяет введен ли размер поля, и если соответсвует условию checkValue, то закрывает диалог
void CDialogEnterSize::onClickOkeyBtn()
{
    if (checkValue())
        close();
}

//метод закрывающий программу
void CDialogEnterSize::onClickCloseBtn()
{
    exit(0);    //навярняка есть более лучший способ закрывать программу, но я другого не нашел
}
//слот для записи enterSizeField при взаимодействии с SpinBox
void CDialogEnterSize::getSizeField(int)
{
    enterSizeField = spinBoxEnterSize->value();
}
