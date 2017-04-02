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
#include "../../Q/SUB_QQ_Q/SUB_QQ_Q.h"

NUMBP subtractNumbP(NUMBP A, NUMBP B)
{
	NUMBP C;

	if (A.C && B.C)
	{
		if (A.m >= B.m)   
		{
			C.m = A.m;
			C.C = (NUMBQ*)malloc((C.m+1) * sizeof(NUMBQ));

			for (int var = 0;var < B.m+1;++var)
                *(C.C + A.m - var)  = subtractNumbQ(*(A.C+A.m - var), *(B.C+B.m-var));

			for (int i = B.m+1;i < A.m+1;++i)
                *(C.C + A.m - i) = *(A.C+A.m-i);
        }
		else               
		{
			C.m = B.m;
			C.C = (NUMBQ*)malloc((C.m+1) * sizeof(NUMBQ));

            for (int var = 0;var < (A.m+1);++var)
                *(C.C + B.m - var) = subtractNumbQ(*(B.C + B.m - var), *(A.C + A.m - var));

            for (int i = A.m+1;i < B.m+1;++i)
                *(C.C + B.m - i) = *(B.C + B.m - i);
		}
	}
	else
		printf("Многочлена не существует! \n");

	return C;
}