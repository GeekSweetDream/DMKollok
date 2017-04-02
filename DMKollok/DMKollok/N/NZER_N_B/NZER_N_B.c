#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "NZER_N_B.h"

/*
 
 isZero
 
 Функция для проерки числа на ноль, если 1 - то не явл. нулем, 0 - явл. нулем, -1 - ошибка
 
 Параметры:
 1) a - Первое число
 
 Функция возращает тип - int
 
 */

int isZero(NUMBN a)
    {
        int ans = 0;
        if(a.A)
            {
                for(int i = 0; i < a.n && !ans; ++i)
                    ans = *(a.A+i) != 0;
            }
        else
            {
                printf("\nОшибка, числа не существует!\n");
                ans = -1;
            }
        
        return ans;
    }
