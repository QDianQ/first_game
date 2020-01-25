#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include "cbtncell.h"
#include "ccell.h"
#include "cgamefield.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGridLayout *lt_grid = new QGridLayout;
    textEdit = new QTextEdit;
    QPushButton *sizeBtn = new QPushButton;

    lt_grid->addWidget(textEdit,20,20);
    sizeBtn->setText("Enter size field");
    lt_grid->addWidget(sizeBtn,21,20);

    connect(sizeBtn, SIGNAL(clicked()), this, SLOT(enterSizeBtnClick()));



    int btnID=0,posX=0,posY=0;
    int size = 3;
    for (int i = 0; i < size; i++){         //Вывод матрицы на экран в понятном виде для пользователя
        for (int j =0; j < size; j++){
            if (posX<size){
                lt_grid->addWidget(new QPushButton("btn " + QString::number(btnID),this),posY,posX);
                btnID++;
                posX++;
            }else{
                posY++;
                posX=0;
                lt_grid->addWidget(new QPushButton("btn " + QString::number(btnID),this),posY,posX);
                btnID++;
                posX++;
            }
        }
    }
    ui->centralwidget->setLayout(lt_grid);

      adjustSize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterSizeBtnClick(QWidget *sender)
{
    sizeField = textEdit->toPlainText();
//    textEdit->setText("completed");
    sizeField.toInt();
    size = sizeField.toInt();
    CGameField *game = new CGameField(size);
}
