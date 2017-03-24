/*

getNumbZ

Функция преобразует натуральное число в целое.

Параметры:
 1)numb - Натуральное число

Функция возвращает - NUMBZ

*/
#include <stdlib.h>
#include <stdio.h>
#include "numbZ.h"
#include "numbN.h"
#include "TRANS_N_Z.h"

NUMBZ getNumbZ(NUMBN numb)
    {
        NUMBZ outNumb;
        if (numb.A)
            {
                outNumb.n = numb.n;
                outNumb.b = 0;
                outNumb.A = (int*)malloc(outNumb.n * sizeof(int));
                for (int i = 0; i < outNumb.n; i++)
                    outNumb.A[i] = numb.A[i];
            }
        else
            printf("\nОшибка, число не существует!\n");
        return outNumb;
    }




