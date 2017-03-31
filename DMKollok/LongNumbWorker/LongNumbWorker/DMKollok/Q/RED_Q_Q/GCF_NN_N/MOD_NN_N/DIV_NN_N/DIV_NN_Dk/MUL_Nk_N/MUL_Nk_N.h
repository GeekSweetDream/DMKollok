#ifndef _COM_NN_D_H_
#define _COM_NN_D_H_
#include "numbN.h"
/*
 
 Автор: Форафонтов Владислав
 Группа: 6308
 
 eleventExp
 
 Функция возводит передаваемое число в 10^k степень.
 В случае, если передан указатель на NULL, вывод ошибки
 
 Параметры:
 1) str - Структура
 2) k - Степень 10
 
 Функция возвращает результат типа - NUMBN*
 
*/

void elevenExp(NUMBN* str, int k);

#endif
