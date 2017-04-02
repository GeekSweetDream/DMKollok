/*

 multiplicationNumbPQ
 Функция для умножения многочлена на рациональное число. Возвращает: B - результат умножения 
 многочлена на рациональное число
 Параметры:
 1) A - многочлен
 2) Q - рациональное число
 Функция возвращает результат типа - NUMBP

*/

#include <stdio.h>
#include <stdlib.h>
#include "numbP.h"
#include "MUL_PQ_P.h"
#include "../../Q/MUL_QQ_Q/MUL_QQ_Q.h"

NUMBP multiplicationNumbPQ(NUMBP A, NUMBQ Q)
{
	NUMBP B;

	if (A.C)
	{
		B.m = A.m;
		B.C = (NUMBQ*)malloc((B.m+1) * sizeof(NUMBQ));
		for (int i = 0;i < (B.m+1);++i)
			B.C[i] = multiplicationNumbQ(A.C[i], Q);
	}
	else
		printf("Многочлена не существует!\n");

	return B;
}






