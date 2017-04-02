
#include <stdio.h>
#include <stdlib.h>
#include "numbQ.h"
#include "numbZ.h"
#include "TRANS_Q_Z.h"


/*
 getNumbZ
 Функция пребразует дробное в целое, если знаменатель 1
 Параметры:
 1) a - число
 Функция возвращает результат типа - NUMBZ
 */

NUMBZ getZNumbQ(NUMBQ a)
{
    NUMBZ ans;
    if(a.a.A && a.b.A)
    {
        if(a.b.n == 1 && *(a.b.A) == 1)
        {
            ans.b = a.a.b;
            ans.n = a.a.n;
            ans.A = (int*) malloc(ans.n*sizeof(int));
            for (int i = 0; i < ans.n; ++i)
                *(ans.A+i) = *(a.a.A+i);
        }
        else
            printf("\nЗнаменатель не равен 1!\n");
    }
    else
        printf("\nОшибка, числа не существует!\n");
    
    return ans;
}
