#ifndef _ADD_NN_N_H_
#define _ADD_NN_N_H_


/*
 
 Автор: Пискунов Виталий
 Группа: 6308

*/

#include <stdio.h>
#include <stdlib.h>
#include "COM_NN_D/COM_NN_D.h"
#include "numbN.h"

void turnNumber(int* number, int length);                                                                                               // Функция для переворота числа
void swapNumb(NUMBN* numberOne, NUMBN* numberTwo);                                                                                      // Функция для обмена указателей
void helpAddNumber(int* numberOne, int* numberTwo, int** answer, int base, int* balance, int addSecNumb, int begin, int end );          // Вспомогательная функция для сложения
NUMBN addNumbers(NUMBN numbOne, NUMBN numbTwo);                                                                                         // Функция для сложения двух чисел

#endif
