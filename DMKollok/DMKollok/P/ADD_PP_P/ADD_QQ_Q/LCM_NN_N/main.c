#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "GCF_NN_N/GCF_NN_N.h"
#include "GCF_NN_N/MOD_NN_N/DIV_NN_N/MUL_NN_N/MUL_NN_N.h"
#include "GCF_NN_N/MOD_NN_N/DIV_NN_N/DIV_NN_N.h"
#include "LCM_NN_N.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 differenceNUmb
 
 Функция считает нок для чисел
 
 Параметры:
 1) fNumb - Первое число
 2) sNumb - Второе число
 
 Функция возращает тип - NUMBN
 
 */


NUMBN nokNumbN(NUMBN fNumb, NUMBN sNumb)
    {
        NUMBN ans;
        int error = 0;
        if(fNumb.A && sNumb.A)
            {
                NUMBN nod = nodNumbN(fNumb, sNumb);
                if(fNumb.n >= sNumb.n)
                    ans = multiplicationTwoNumb(DivNumbN(fNumb, nod),sNumb);
                else
                    ans = multiplicationTwoNumb(fNumb,DivNumbN(sNumb, nod));
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, числа не существует!\n");
    
        return ans;
    }
