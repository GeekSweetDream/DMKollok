
#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "MUL_Nk_N/MUL_Nk_N.h"
#include "COM_NN_D/COM_NN_D.h"
#include "bfunc/bfunc.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 getFirstNumbDivident
 
 Функция выдает первую цифру большего числа умн на 10^k
 
 Параметры:
 1) fNumb - Первое число
 2) sNumb - Второе число
 
 Функция возращает тип - NUMBN
 
 */

NUMBN getFirstNumbDivident(NUMBN fNumb,NUMBN sNumb)
    {
        NUMBN answer;
        int error = 0;
        if(fNumb.A && sNumb.A)
            {
                int comp = compNumbers(fNumb,sNumb);
                error = comp == -1;
                if (!error)
                    {
                        if(comp == 1)
                            swapNumb(&fNumb, &sNumb);
                        
                        answer.n = 1;
                        answer.A = (int*) malloc(sizeof(int));
                        *(answer.A) = *(fNumb.A);
                        elevenExp(&answer, fNumb.n - 1);
                    }
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, число не существует!\n");
        
        return answer;
    }
