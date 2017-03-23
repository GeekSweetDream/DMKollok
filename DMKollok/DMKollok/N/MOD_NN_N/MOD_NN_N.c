#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "DIV_NN_N/DIV_NN_N.h"
#include "DIV_NN_N/SUB_NDN_N/SUB_NN_N/SUB_NN_N.h"
#include "DIV_NN_N/MUL_NN_N/MUL_NN_N.h"
#include "MOD_NN_N.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 modNumbN
 
 Функция выдает остаток от деления
 
 Параметры:
 1) a - делимое
 2) b - делитель
 
 Функция возращает тип - NUMBN
 
 */


NUMBN modNumbN(NUMBN a, NUMBN b)
    {
        NUMBN ans;
        int error = 0;
        if(a.A && b.A)
            {
                NUMBN k = DivNumbN(a, b);
                ans = differenceNumb(a, multiplicationTwoNumb(b, k));
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, число не существует!\n");
        
        return ans;
    }

