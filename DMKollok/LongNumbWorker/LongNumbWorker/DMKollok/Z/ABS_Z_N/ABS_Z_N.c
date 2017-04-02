#include <stdlib.h>
#include <stdio.h>
#include "numbZ.h"
#include "numbN.h"
#include "ABS_Z_N.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 absNumbZ
 
 Функция выдает абсолютное значение(натуральное) целого числа
 
 Параметры:
 1) numb - Целое число
 
 Функция возращает тип - NUMBN
 
*/

NUMBN absNumbZ(NUMBZ numb)
    {
        NUMBN answer;
        
        if(numb.A)
            {
                answer.n = numb.n;
                answer.A = (int*) malloc(answer.n*sizeof(int));
                for (int i = 0; i < numb.n; ++i)
                    *(answer.A+i) = *(numb.A+i);
            }
        else
            printf("\nОшибка, числа не существует!\n");
        return answer;
    }

