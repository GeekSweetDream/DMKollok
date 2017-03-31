#include <stdlib.h>
#include <stdio.h>
#include "numbQ.h"
#include "MUL_ZZ_Z/MUL_ZZ_Z.h"
#include "MUL_ZZ_Z/MUL_NN_N/MUL_NN_N.h"
#include "MUL_QQ_Q.h"

/*
 multiplicationNumbQ
 Функция умножает два рациональных числа
 Параметры:
 1) a - первое число
 2) b - второе число
 Функция возвращает результат типа - NUMBQ
*/

NUMBQ multiplicationNumbQ(NUMBQ a, NUMBQ b)
    {
        NUMBQ ans;
        int error = 0;
        if(a.a.A && a.b.A && b.a.A && b.b.A)
            {
                ans.a = multiplicationNumbZ(a.a, b.a);
                ans.b = multiplicationTwoNumb(a.b, b.b);
                error = !(ans.a.A && ans.b.A);
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, числа не существует!\n");
        
        return ans;
    }
