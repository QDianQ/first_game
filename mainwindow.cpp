#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(onBtnClick()));
    //connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onBtnClick);
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
