#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ccell.h"
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class CGameField;
class CBtnCell;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();    

    void setSizeField(int sizeField);
    bool createNewGame = false;

protected:
    void createBtn();
    void clearBtn();
    void showMessageOfWin();
    void swapPositionBtn(CBtnCell *newCellSender,int *randomPosX=nullptr,int *randomPosY=nullptr);
    int size, btnID,*itemPositon;

    CGameField *game;
    CBtnCell *zeroCellBtn, *newCell;
//    int posBtnX=0,posBtnY=0;


signals:

public slots:
    void enterSize(QWidget *sender = nullptr);
    void onClickNewCell();
    void onClickRestart();
    void onClickRandomMove();
    void onClickShowDialog();   //временная кнопка

private:
    Ui::MainWindow *ui;
    QWidget *tmpQWidleft;
    QGridLayout *lt_grid;

};

#endif // MAINWINDOW_H
