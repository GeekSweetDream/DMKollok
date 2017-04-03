#include <stdlib.h>
#include <stdio.h>
#include "../MUL_ND_N/MUL_ND_N.h"
#include "../MUL_Nk_N/MUL_Nk_N.h"
#include "../ADD_NN_N/ADD_NN_N.h"
#include "numbN.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 multiplicationTwoNumb
 
 Функция для умножения двух натуральных чисел
 
 Параметры:
 1) numbF - Первое число
 2) numbS - Второе число
 
 Функция возращает тип - NUMBN
 
*/

NUMBN multiplicationTwoNumb(NUMBN numbF, NUMBN numbS)
    {
        NUMBN answer;
        NUMBN a;
        if(numbF.A && numbS.A)
            {
                answer.n = numbF.n>numbS.n?numbS.n:numbF.n;
                answer.A = (int*) calloc (answer.n, sizeof(int));
                for (int i = numbF.n-1; i >= 0; --i)
                    {
                        a = multiplicateN(numbS, *(numbF.A+i));
                        elevenExp(&a, numbF.n-i-1);
                        answer = addNumbers(a, answer);
                    }
            }
        else
            printf("\nОшибка, число не существует!\n");
        return answer;
    }
