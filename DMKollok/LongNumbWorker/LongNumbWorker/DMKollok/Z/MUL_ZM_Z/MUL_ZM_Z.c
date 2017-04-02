
#include <stdio.h>
#include <stdlib.h>
#include "numbZ.h"
#include "MUL_ZM_Z.h"

/*
 
 multiMinusOne
 
 Функция для  умножения целого числа на (-1)
 
 Параметры:
    1) numb - целое число
 
 Функция ничего не возвращает
 
*/

void multiMinusOne(NUMBZ* numb)
    {
        if(numb->A)
            numb->b = numb->b? 0 : 1;
        else
            printf("\nОшибка, число не существует!\n");
    }
