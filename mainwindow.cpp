#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include "cbtncell.h"
#include "cgamefield.h"

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
    textEdit = new QTextEdit;
    tmpQWidleft = new QWidget;



    lt_horizntal->addWidget(tmpQWidleft);
    lt_horizntal->insertLayout(1,lt_vertical);
    lt_vertical->addWidget(textEdit);
    sizeBtn->setText("Enter size field");
    lt_vertical->addWidget(sizeBtn);
    ui->centralwidget->setLayout(lt_horizntal);


    connect(sizeBtn, SIGNAL(clicked()), this, SLOT(enterSizeBtnClick()));
    CBtnCell *newCell = (CBtnCell*) sender();
    connect(newCell,SIGNAL(clicked()), this, SLOT(onClickNewCell()));


}

MainWindow::~MainWindow()
{
    if(game!=nullptr)
        delete game;
    delete zeroCellBtn;
    delete ui;

}

void MainWindow::enterSizeBtnClick(QWidget *sender)
{
    sizeField = textEdit->toPlainText();
    size = sizeField.toInt();
    if(game!=nullptr){
        delete game;
        game=nullptr;
    }
    game = new CGameField(size,zeroCellBtn);    //передается размер поля пятнашек
    game->create_field(size);       //создается поле
    game->swap_numbers(size);       //нахождение координат нуля
//    testbtn->updBtnPos(game->ID);   //здесь я хотел передать координаты нуля в CBtnCell, но при запуске этого метода в дебагере приложение вылетает

    qDebug()<<size;

    createBtn();

}
void MainWindow::createBtn()
{
    clearBtn();

    QHBoxLayout *lt_h = dynamic_cast<QHBoxLayout*>(ui->centralwidget->layout());
    QGridLayout *lt_grid = new QGridLayout;

    int posX=0,posY=0;

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

//    QWidget *tmp_w = lt_h->takeAt(0)->widget();
//    if (tmp_w)
//        tmp_w->setLayout(lt_grid);
    tmpQWidleft->setLayout(lt_grid);
    adjustSize();
}
void MainWindow::clearBtn()
{
//    QHBoxLayout *lt_h = dynamic_cast<QHBoxLayout*>(ui->centralwidget->layout());
//    QLayout *lt_item = lt_h->takeAt(0)->widget()->layout();
      QObjectList mass_child=tmpQWidleft->children();

      foreach (QObject *var, mass_child) {
        delete var;
      }
}
void MainWindow::onClickNewCell()
{
    textEdit->setText("click");     //хотел таким способом проверить работает ли метод
}

