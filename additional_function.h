#ifndef ADDITIONAL_FUNCTION_H
#define ADDITIONAL_FUNCTION_H

bool f_check_win(int *mass_converted, int size);            //функция проверки условаия победы
void f_convert(int *mass_converted, int **mass, int size);  //функция конвертирующая двумерный массив в одномерный
void f_show_field(int **mass,int size);                     //функция вывода матрицы на экран
void f_rand(int *buf, int size);                            //функция для рандома чисел без повтора и записи в массив

#endif // ADDITIONAL_FUNCTION_H
