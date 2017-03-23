#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "SUB_NN_N/SUB_NN_N.h"
#include "MUL_ND_N/MUL_ND_N.h"
#include "COM_NN_D/COM_NN_D.h"
#include "SUB_NN_N/bfunc/bfunc.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 differentNumbMultK
 
 Функция вычитание из одного натурального другое умноженное на цифру
 
 Параметры:
 1) numbF - Первое число
 2) numbS - Второе число
 3) k - цифра, на которую будет умножаться число
 
 Функция возращает тип - NUMBN
 
 */

NUMBN differentNumbMultK (NUMBN fNumb, NUMBN sNumb, int k)
    {
        int error = 0;
        NUMBN answer;
        if(fNumb.A && sNumb.A)
            {
                int comp = compNumbers(fNumb, sNumb);
                error = comp == -1;
                if(!error)
                    {
                        if(comp == 1)
                            swapNumb(&fNumb, &sNumb);
                        
                        sNumb = multiplicateN(sNumb, k);
                        answer = differenceNumb(fNumb, sNumb);
                    }
            }
        else
            error = 1;
            
        if(error)
            printf("\nОшибка, число не существует!\n");
            
        return answer;
    }
