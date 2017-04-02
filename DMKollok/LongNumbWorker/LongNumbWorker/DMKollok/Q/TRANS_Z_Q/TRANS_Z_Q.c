
#include <stdio.h>
#include <stdlib.h>
#include "numbQ.h"
#include "numbZ.h"
#include "TRANS_Z_Q.h"

/*
 getNumbQ
 Функция пребразует целое в дробное
 Параметры:
 1) a - число
 Функция возвращает результат типа - NUMBQ
 */

NUMBQ getNumbQ(NUMBZ a)
    {
        NUMBQ ans;
        if(a.A)
            {
                ans.b.n = 1;
                ans.b.A = (int*) malloc(sizeof(int));
                *(ans.b.A) = 1;
                ans.a.b = a.b;
                ans.a.n = a.n;
                ans.a.A = (int*) malloc(ans.a.n*sizeof(int));
                for (int i = 0; i < a.n; ++i)
                    *(ans.a.A+i) = *(a.A+i);
            }
        else
            printf("\nОшибка, числа не существует!\n");
        
        return ans;
    }

