#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ccell.h"

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
    void createBtn();
    void clearBtn();
    CCell *cellZero;
    void setSizeField(int sizeField);

protected:
    int size, btnID;
    CGameField *game;
    CBtnCell *zeroCellBtn, *newCell;


signals:

public slots:
    void enterSize(QWidget *sender = nullptr);
    void onClickNewCell();
    void onClickEnterSize();

private:
    Ui::MainWindow *ui;
    QWidget *tmpQWidleft;
};

#endif // MAINWINDOW_H
