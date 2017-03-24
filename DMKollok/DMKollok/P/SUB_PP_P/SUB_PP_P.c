/*

 subtractNumbP

 Функция выполняет вычитание для двух многочленов

 Параметры:
 1) A - первый многочлен
 2) B - второй многочлен

 Функция возвращает результат типа - NUMBP

*/

#include <stdlib.h>
#include <stdio.h>
#include "numbP.h"
#include "SUB_PP_P.h"
#include "SUB_QQ_Q/SUB_QQ_Q.h"

NUMBP subtractNumbP(NUMBP A, NUMBP B)
{
	NUMBP C;
	int var;

	if (A.C && B.C)
	{
		if (A.m >= B.m)   
		{
			C.m = A.m;
			C.C = (NUMBQ*)sizeof(C.m * sizeof(NUMBQ));

			for (var = 0;var < B.m;++var)
				C.C[var] = subtractNumbQ(A.C[var], B.C[var]);

			for (int i = var;i < A.m;++i)
				C.C[i] = A.C[i];
		}
		else               
		{
			C.m = B.m;
			C.C = (NUMBQ*)malloc(C.m * sizeof(NUMBQ));

			for (var = 0;var < A.m;++var)
				C.C[var] = subtractNumbQ(B.C[var], A.C[var]);

			for (int i = var;i < B.m;++i)
				C.C[i] = B.C[i];
		}
	}
	else
		printf("Многочлена не существует! \n");

	return C;
}