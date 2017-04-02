#include <stdlib.h>
#include <stdio.h>
#include "numbZ.h"
#include "numbN.h"
#include "../ABS_Z_N/ABS_Z_N.h"
#include "../../N/DIV_NN_N/DIV_NN_N.h"
#include "../POZ_Z_D/POZ_Z_D.h"
#include "../TRANS_N_Z/TRANS_N_Z.h"

/*
 
 diffNumbZ
 
 Функция для деления двух целых чисел
 
 Параметры:
 1) a - делимое
 2) b - делитель
 
 Функция возвращает результат типа - NUMBZ
 
 */

NUMBZ divNumbZ(NUMBZ divident, NUMBZ divider)
    {
        NUMBZ ans;
        int error =0;
        if(divident.A && divider.A)
            {
                NUMBN a, b;
                a = absNumbZ(divident);
                b = absNumbZ(divider);
                a = DivNumbN(a, b);
                ans = getNumbZ(a);
                ans.b = (!divider.b && divident.b) || (!divident.b && divider.b);
            }
        else
            error =1;
        
        if(error)
            printf("\nОшибка, число не существует!\n");
        
        return ans;
    }
