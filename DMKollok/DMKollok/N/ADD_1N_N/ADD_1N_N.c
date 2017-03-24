
#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "bfunc/bfunc.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*

 AddOne
 
 Функция для прибавления 1
 
 Параметры
 1) NUMBN numb - Число, к которому будут прибавлять
 
 
  Фукнция выводит тип - NUMBN
 
 */


NUMBN AddOne(NUMBN numb)
{
    NUMBN answer;
    if (numb.A)
        {
            answer.n = numb.n;
            answer.A = (int*) malloc(answer.n*sizeof(int));
            for(int i = 0; i < answer.n; ++i)
                *(answer.A+i) = *(numb.A+i);
            if(*(answer.A+answer.n-1) == 9)
                {
                    turnNumber(answer.A, answer.n);
                    int ost = 1;
                    for(int i = 0; i < answer.n && ost; ++i)
                        {
                            *(answer.A + i) += ost;
                            ost = *(answer.A + i ) / 10;
                            *(answer.A + i) %= 10 ;
                        }
                    if(ost)
                        {
                            answer.A = (int*) realloc(answer.A, (answer.n)*sizeof(int));
                            *(answer.A+answer.n) = ost;
                            ++answer.n;
                        }
                    turnNumber(answer.A, answer.n);
                }
            else
                ++*(answer.A+answer.n-1);
        }
    else
        printf("\nОшибка, числа не существует!\n");
    
    return answer;
    
}



