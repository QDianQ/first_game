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

    spinBoxEnterSize->setMinimum(3);

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
    connect(okBtn, SIGNAL(clicked()), this, SLOT(onClickOK()));
    connect(closeBtn, SIGNAL(clicked()), this, SLOT(onClickClose()));
}
void CDialogEnterSize::onClickOK()
{    
    done(spinBoxEnterSize->value());

}
void CDialogEnterSize::onClickClose()
{
    exit(0);
}
