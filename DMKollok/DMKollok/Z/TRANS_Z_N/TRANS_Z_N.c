/*

getNatural

Функция преобразует целое неотрицательное число в натуральное.

Параметры:
numb - целое число

Функция возвращает натуральное число

*/

#include <stdio.h>
#include "numbZ.h"
#include "numbN.h"
#include "TRANS_Z_N.h"

NUMBN getNatural(NUMBZ numb)
    {
	NUMBN outNumb;
	if (numb.A)
	      if (numb.b == 1)
	          {
			outNumb.n = numb.n;
			outNumb.A = (int*)malloc(outNumb.n * sizeof(int));
			for (int i = 0; i < outNumb.n; i++)
				outNumb.A[i] = numb.A[i];
	          }
	       else
	          printf("Введено отрицательное число, действие не может быть выполнено");
	else
	    printf("\nОшибка, число не существует!\n");
	return outNumb;
     }




