
#include <stdlib.h>
#include <stdio.h>
#include "numbQ.h"

/*
INT_Q_B
Функция проверяет нацелое,если рациональное число целое, то 1 - Да, иначе 0 - Нет, -1 - Ошибка.
Параметры:
1) q - число
Функция возвращает результат типа - int
*/

int INT_Q_B(NUMBQ q)
    {
        int answer = 0 ;
        if (q.b.A && q.a.A)
            answer = *(q.b.A) == 1 && q.b.n == 1;
        else
            {
                printf("\nОшибка, число не существует!\n");
                answer = -1;
            }
        return answer;
    }
