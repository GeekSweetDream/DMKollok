/*
 
 eleventExp
 
 Функция возводит передаваемое число в 10^k степень.
 В случае, если передан указатель на NULL, вывод ошибки
 
 Параметры:
 1) str - Структура
 2) k - Степень 10
 
 Функция возвращает результат типа - NUMBN*
 
 */
#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "MUL_Nk_N.h"

void elevenExp(NUMBN* str, int k)
{
    if (str->A != NULL)
    {
        for (int i = str->n; i < str->n + k; i++)
        {
            str->A = realloc(str->A, str->n+i * sizeof(int*));
            *(str->A + i) = 0;
        }
        str->n += k;
    }
    else
        puts("Ошибка, было передано пустое значение числа");
}
