#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include "cbtncell.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include "additional_function.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHBoxLayout *lt_horizntal = new QHBoxLayout;
    QVBoxLayout *lt_vertical = new QVBoxLayout;
    QPushButton *sizeBtn = new QPushButton;
    CBtnCell *testbtn = new CBtnCell;
    testbtn->setText("testBtn");

    textEdit = new QTextEdit;
    tmpQWidleft = new QWidget;

    lt_horizntal->addWidget(tmpQWidleft);
    lt_horizntal->insertLayout(1,lt_vertical);
    lt_vertical->addWidget(textEdit);
    sizeBtn->setText("Enter size field");
    lt_vertical->addWidget(sizeBtn);
    lt_vertical->addWidget(testbtn);
    ui->centralwidget->setLayout(lt_horizntal);


    connect(sizeBtn, SIGNAL(clicked()), this, SLOT(enterSizeBtnClick()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enterSizeBtnClick(QWidget *sender)
{
    sizeField = textEdit->toPlainText();
    size = sizeField.toInt();
    qDebug()<<size;
    createBtn();

}
void MainWindow::createBtn()
{
    clearBtn();
//    CGameField *game = new CGameField(size);

    QHBoxLayout *lt_h = dynamic_cast<QHBoxLayout*>(ui->centralwidget->layout());
    QGridLayout *lt_grid = new QGridLayout;

    int btnID=0,posX=0,posY=0;


    for (int i = 0; i < size; i++){         //Вывод матрицы на экран в понятном виде для пользователя
        for (int j =0; j < size; j++){
            if (posX<size){
                lt_grid->addWidget(new QPushButton("btn " + QString::number(btnID),tmpQWidleft),posY,posX);
                btnID++;
                posX++;
            }else{
                posY++;
                posX=0;
                lt_grid->addWidget(new QPushButton("btn " + QString::number(btnID),tmpQWidleft),posY,posX);
                btnID++;
                posX++;
            }
        }
    }

//    QWidget *tmp_w = lt_h->takeAt(0)->widget();
//    if (tmp_w)
//        tmp_w->setLayout(lt_grid);
    tmpQWidleft->setLayout(lt_grid);
    adjustSize();
}
void MainWindow::clearBtn()
{
    QHBoxLayout *lt_h = dynamic_cast<QHBoxLayout*>(ui->centralwidget->layout());
//    QLayout *lt_item = lt_h->takeAt(0)->widget()->layout();
      QObjectList mass_child=tmpQWidleft->children();

      foreach (QObject *var, mass_child) {
        delete var;
      }
}
