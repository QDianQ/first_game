#include "cdialogentersize.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QApplication>

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

    ///> Альтернатива
    //connect(closeBtn, SIGNAL(clicked()), this, SLOT(onClickCloseBtn()));
    connect(closeBtn, SIGNAL(clicked()), qApp, SLOT(quit()), Qt::QueuedConnection);
}

//метод проверяющий одинаковые ли значения в SpinBox и enterSizeField
///> Метод получается избыточным. Логика должна быть проще:
/// по нажатию кнопки Ok Диалог должен закрыться, с возвращением кода
/// соответствующего N, котоый просто считывается из SpinBox.
/// Основное приложение должно просто получить это значение
/// и использовать как N, либо закрыться, если N==0
/// Правильность значения, возвращаемого из SpinBox,
/// можно обеспечить просто задав ему нижнюю границу "2" (см документацию на QSpinBox)
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
//    if (checkValue())
//        close();
    done(spinBoxEnterSize->value());
}

//метод закрывающий программу
void CDialogEnterSize::onClickCloseBtn()
{
    exit(0);    //навярняка есть более лучший способ закрывать программу, но я другого не нашел

    ///> Это вполне корректный вариант
    /// Как альтернативу, можно использовать слот quit(), он делает ровно тоже самое
    /// Смотри конструктор (тогда эта функция в таком варианте не нужна)
}
//слот для записи enterSizeField при взаимодействии с SpinBox
///> Велом так можно и иногда нужно, но в конкретном случае это тоже излишняя функция
void CDialogEnterSize::getSizeField(int)
{
    enterSizeField = spinBoxEnterSize->value();
}
