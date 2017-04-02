#ifndef _ADD_NN_N_H_
#define _ADD_NN_N_H_



#include <stdio.h>
#include <stdlib.h>
#include "numbN.h"


void helpAddNumber(int* numberOne, int* numberTwo, int** answer, int base, int* balance, int addSecNumb, int begin, int end );          // Вспомогательная функция для сложения
NUMBN addNumbers(NUMBN numbOne, NUMBN numbTwo);                                                                                         // Функция для сложения двух чисел

#endif
