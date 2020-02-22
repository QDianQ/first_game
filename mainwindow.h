#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
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

protected:
    QString sizeField;
    QTextEdit *textEdit;
    int size, btnID;
    CGameField *game;
    CBtnCell *zeroCellBtn, *newCell;


signals:

public slots:
    void enterSizeBtnClick(QWidget *sender = nullptr);
    void onClickNewCell();

private:
    Ui::MainWindow *ui;
    QWidget *tmpQWidleft;
};

#endif // MAINWINDOW_H
