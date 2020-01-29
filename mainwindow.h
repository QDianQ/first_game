#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class CGameField;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createBtn();
    void clearBtn();

protected:
    QString sizeField;
    QTextEdit *textEdit;
    int size;
    CGameField *game;

signals:

public slots:
    void enterSizeBtnClick(QWidget *sender = nullptr);

private:
    Ui::MainWindow *ui;
    QWidget *tmpQWidleft;
};

#endif // MAINWINDOW_H
