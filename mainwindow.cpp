#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include "cbtncell.h"
#include "cgamefield.h"
#include "cdialogentersize.h"
#include <QMessageBox>
#include <QAbstractButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHBoxLayout *lt_horizntal = new QHBoxLayout;
    QVBoxLayout *lt_vertical = new QVBoxLayout;

    zeroCellBtn = new CBtnCell;
    zeroCellBtn->hide();
    game=nullptr;
    tmpQWidleft = new QWidget;

    QPushButton *restartBtn = new QPushButton;  //начать заного
    QPushButton *randomMove = new QPushButton;  //случайное перемещение
    QPushButton *showDialogOfWin = new QPushButton;     //временная кнопка для вывода диалога о победе

    lt_horizntal->addWidget(tmpQWidleft);
    lt_horizntal->insertLayout(1,lt_vertical);

    restartBtn->setText("Restart");
    lt_vertical->addWidget(restartBtn);

    randomMove->setText("Random move");
    lt_vertical->addWidget(randomMove);

    showDialogOfWin->setText("Show dialog of win"); //временная кнопка
    lt_vertical->addWidget(showDialogOfWin);

    ui->centralwidget->setLayout(lt_horizntal);

    connect(restartBtn,SIGNAL(clicked()),this,SLOT(onClickRestart()));
    connect(randomMove,SIGNAL(clicked()),this,SLOT(onClickRandomMove()));
    connect(showDialogOfWin,SIGNAL(clicked()),this,SLOT(onClickShowDialog()));  //временная кнопка

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
    game->createField();       //создается поле


    createBtn();
}
//метод создания кнопок
void MainWindow::createBtn()
{
    clearBtn();

    lt_grid = new QGridLayout;


    int count=0;
    for (int i = 0; i < size; i++){         //Вывод матрицы на экран в понятном виде для пользователя
        for (int j =0; j < size; j++){
            int id = game->buf[count];

            if (id==0){
                newCell=zeroCellBtn;
            }
            else{
                newCell = new CBtnCell("btn " + QString::number(id),tmpQWidleft);
            }

            connect(newCell,SIGNAL(clicked()),this,SLOT(onClickNewCell()));

            lt_grid->addWidget(newCell,i,j);
            game->addCell(newCell,j,i,id);
            count++;
        }
    }

    qDebug() << "countCell " << game->countCell;
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
//слот newCell, который используется для получения индекса нажатой кнопки
void MainWindow::onClickNewCell()
{
    CBtnCell *newCellSender = qobject_cast<CBtnCell*>(sender());

    int newCellSenderID = newCellSender->getID();
    if(game->movementOnField(newCellSenderID))
        swapPositionBtn(newCellSender);
}
//при условии победы срабатывает этот метод
void MainWindow::showMessageOfWin()
{
    QMessageBox *messageBox = new QMessageBox;

    messageBox->setText("You Win!");
    messageBox->setInformativeText("What will you want next?");
    messageBox->setIcon(QMessageBox::Information);

    QPushButton *newGame = messageBox->addButton("New game", QMessageBox::ActionRole);
    QPushButton *exitGame = messageBox->addButton("Exit game", QMessageBox::ActionRole);

    messageBox->setDefaultButton(newGame);
    messageBox->exec();

    if(messageBox->clickedButton()== newGame)
    {        
//        createNewGame=true;
//        close();
        exit(1);
    }
    else if(messageBox->clickedButton()== exitGame)
    {
        exit(0);
    }
}
//кнопка "restart"
void MainWindow::onClickRestart()
{
//    createNewGame=true;
    //close();
    exit(10);
}
//временная кнопка
void MainWindow::onClickShowDialog()
{
    showMessageOfWin();
}
//кнопка для рандомного передвижения
void MainWindow::onClickRandomMove()
{
//    //передать в массив координаты кнопок, которые удовлетворяют условию нажатия
////    zeroCellBtn->getCorrectPositionBtn(massCell);

//    int direction = 0 + rand() % 4;     //рандом направления
//    qDebug() << "direction" << direction;

//    //координты корректных кнопок для нажатия
//    int *posX = &massCell[direction][0];
//    int *posY = &massCell[direction][1];

//    //проверка, чтоб не вышло за границы матрицы
//    if(direction==0){   //верх
//        if (*posX>=0){
//            swapPositionBtn(100,posX,posY);
//        }
//    }
//    if(direction==1){     //низ
//        if(*posX<size){
//            swapPositionBtn(100,posX,posY);
//        }
//    }
//    if(direction==2){     //право
//        if(*posY<size){
//            swapPositionBtn(100,posX,posY);
//        }
//    }
//    if(direction==3){     //лево
//        if(*posY>=0){
//            swapPositionBtn(100,posX,posY);
//        }
//    }


}
//метод меняющий местами newCell и zeroCell
void MainWindow::swapPositionBtn(CBtnCell *newCellSender)
{
    int itemCellPositionX, itemCellPositionY, itemZeroPositionX, itemZeroPositionY,a,b;

    int indexNewCellBtn = lt_grid->indexOf(newCellSender);
    int indexZeroCellBtn = lt_grid->indexOf(zeroCellBtn);

    QLayoutItem *zeroItem, *nCellItem;

    lt_grid->getItemPosition(indexZeroCellBtn,&itemZeroPositionX,&itemZeroPositionY,&a,&b);
    lt_grid->getItemPosition(indexNewCellBtn,&itemCellPositionX,&itemCellPositionY,&a,&b);

    zeroItem=lt_grid->takeAt(indexZeroCellBtn);
    nCellItem=lt_grid->takeAt(indexNewCellBtn);

    lt_grid->addItem(nCellItem,itemZeroPositionX,itemZeroPositionY);
    lt_grid->addItem(zeroItem,itemCellPositionX,itemCellPositionY);
}
