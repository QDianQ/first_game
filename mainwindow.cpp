#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGridLayout *lt_grid = new QGridLayout;

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

void MainWindow::onBtnClick(QWidget *sender)
{
//    QString str = ui->pushButton_3->text();
//    ui->plainTextEdit->appendPlainText(str);
//    ui->plainTextEdit->appendPlainText("test_str");
}
