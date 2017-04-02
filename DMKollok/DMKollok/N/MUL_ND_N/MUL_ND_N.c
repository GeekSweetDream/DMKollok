#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "../bfunc/bfunc.h"
#include "MUL_ND_N.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 multi
 
 Функция вычитание из одного натурального другое
 
 Параметры:
 1) numb  - Первое число
 2) k - Цифра на которую нужно умножить
 
 Функция возращает тип - NUMBN
 
 */

NUMBN multiplicateN(NUMBN numb, int k)
    {
        NUMBN answer;
        if(numb.A)
            {
                answer.n = numb.n;
                answer.A = (int*) calloc(numb.n, sizeof(int));
                if(k < 10)
                    {
                        if(k > 0)
                            {
                                int ost = 0;
                                turnNumber(numb.A,numb.n);
                                for (int i = 0; i < numb.n; ++i)
                                    {
                                        *(answer.A+i) = *(numb.A+i)*k + ost;
                                        ost = *(answer.A+i) / 10;
                                        *(answer.A + i) %= 10;
                                    }
                                if(ost)
                                    {
                                        ++answer.n;
                                        answer.A = (int*) realloc(answer.A, (answer.n)*sizeof(int));
                                        *(answer.A + answer.n-1) = ost;
                                    }
                                turnNumber(answer.A, answer.n);
                                turnNumber(numb.A, numb.n);
                            }
                    }
                else
                    {
                        printf("\nЦифра, которую вы ввели, была больше 10\n");
                        for (int i = 0 ; i < numb.n; ++i)
                            *(answer.A+i) = *(numb.A+i);
                    }
            }
        else
            printf("\nОшибка, числа не существует!\n");
        
        return answer;
    }
