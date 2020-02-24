#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include "cbtncell.h"
#include "cgamefield.h"
#include "cdialogentersize.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHBoxLayout *lt_horizntal = new QHBoxLayout;
    QVBoxLayout *lt_vertical = new QVBoxLayout;
    QPushButton *sizeBtn = new QPushButton;

    zeroCellBtn = new CBtnCell;
    zeroCellBtn->hide();
    game=nullptr;
    tmpQWidleft = new QWidget;

    lt_horizntal->addWidget(tmpQWidleft);
    lt_horizntal->insertLayout(1,lt_vertical);
    sizeBtn->setText("Enter size field");
    lt_vertical->addWidget(sizeBtn);
    ui->centralwidget->setLayout(lt_horizntal);

    connect(sizeBtn ,SIGNAL(clicked()), this, SLOT(onClickEnterSize()));
}
MainWindow::~MainWindow()
{
    if(game!=nullptr)
        delete game;
    delete zeroCellBtn;
    delete ui;

}
//метод получающий значение размера поля из диалога
void MainWindow::setSizeField(int sizeFieled)
{
    size=sizeFieled;
    enterSize();
}
//метод формирующий игровое поле и запускающий метод создания кнопок
void MainWindow::enterSize(QWidget *sender)
{    
    if(game!=nullptr){
        delete game;
        game=nullptr;
    }
    game = new CGameField(size,zeroCellBtn);    //передается размер поля пятнашек
    game->create_field(size);       //создается поле

    createBtn();
}
//метод создания кнопок
void MainWindow::createBtn()
{
    clearBtn();

    QGridLayout *lt_grid = new QGridLayout;

    int posX=0,posY=0;
    CBtnCell *newCell;
    for (int i = 0; i < size; i++){         //Вывод матрицы на экран в понятном виде для пользователя
        static int count=0;        
        for (int j =0; j < size; j++){

            int id = game->buf[count];
            if (id==0)
                newCell=zeroCellBtn;
            else
                newCell = new CBtnCell("btn " + QString::number(id),tmpQWidleft);
            if (posX<size){
                lt_grid->addWidget(newCell,posY,posX);
                posX++;
                count++;
            }else{
                posY++;
                posX=0;
                lt_grid->addWidget(newCell,posY,posX);
                posX++;
                count++;
            }
        }
    }

    connect(newCell,SIGNAL(clicked()),this,SLOT(onClickNewCell()));

    tmpQWidleft->setLayout(lt_grid);
    adjustSize();
}
//метод удаления кнопок
void MainWindow::clearBtn()
{
      QObjectList mass_child=tmpQWidleft->children();

      foreach (QObject *var, mass_child) {
        delete var;
      }
}
void MainWindow::onClickEnterSize()  //оставил для примера
{
    ///> вот так можно проверить sender
        QPushButton* btn = qobject_cast<QPushButton*>(sender());
        qDebug() << btn->text();
}
void MainWindow::onClickNewCell()   //слот для newCell
{
    CBtnCell* btn = qobject_cast<CBtnCell*>(sender());
    qDebug() << btn->text();
}
