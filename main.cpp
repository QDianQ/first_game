#include <iostream>
#include "conio.h"
#include "cdialogentersize.h"
#include <QApplication>
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ///> Основное окно логично не отображать до закрытия диалога
    CDialogEnterSize *dialogEnterSize = new CDialogEnterSize;

    ///> см. документацию QDialog::exec
    /// По сути main здесь затормозиться до тех пор, пока не закроется диалог
    int N = dialogEnterSize->exec();
    cout << N << endl;

    ///> На самом деле таким образом можно обойтись и без обработки закрытия приложения
    /// в классе Диалога. И это скорее будет правильно, поскольку тот диалог может
    /// в последствии вызываться вновь, для переинициализации игры, но при этом
    /// не совсем логично, чтобы вся программа закрылась в таком случае.
    /// По этому диалог просто может возвращать 0, при нажатии кнопки Отмена
    if (N > 2)
    {
        MainWindow w;
        w.show();

        return a.exec();
    }
    else
        return 0;
}

