
#include <stdio.h>
#include <stdlib.h>
#include "numbQ.h"
#include "numbZ.h"
#include "MUL_QQ_Q/MUL_QQ_Q.h"
#include "TRANS_Z_N/TRANS_Z_N.h"
#include "TRANS_N_Z/TRANS_N_Z.h"
#include "DIV_QQ_Q.h"
/*
 
 divNumbQ
 
 Функция для деления двух рациональных чисел
 
 Параметры:
 1) divident - первое число
 2) divider - второе число
 
 Функция возвращает результат типа - NUMBQ
 
 */

NUMBQ divNumbQ(NUMBQ divident, NUMBQ divider)
    {
        NUMBQ ans;
        if(divident.a.A && divident.b.A && divider.b.A && divider.a.A)
            {
                NUMBZ a = getNumbZ(divider.b);
                a.b = divider.a.b;
                divider.a.b = 0;
                divider.b = getNatural(divider.a);
                divider.a = a;
                ans = multiplicationNumbQ(divident, divider);
            }
        else
            printf("\nОшибка, числа не существует!\n");
        
        return ans;
    }
