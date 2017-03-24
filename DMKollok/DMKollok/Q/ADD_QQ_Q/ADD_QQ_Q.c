/*

 subtractNumbQ

 Функция вычитает два рациональных числа
 Параметры:
 1) A - первое число
 2) B - второе число

 Функция возвращает результат типа - NUMBQ

*/

#include <stdlib.h>
#include <stdio.h>
#include "numbQ.h"
#include "ADD_QQ_Q.h"
#include "TRANS_N_Z/TRANS_N_Z.h"
#include "MUL_ZZ_Z/MUL_ZZ_Z.h"
#include "ADD_ZZ_Z/ADD_ZZ_Z.h"
#include "LCM_NN_N/LCM_NN_N.h"

NUMBQ addNumbQ(NUMBQ A, NUMBQ B)
{
	NUMBQ C;
	if (A.a.A && A.b.A && B.a.A && B.b.A)
	{
		C.b = nokNumbN(A.b, B.b);
		C.a = addNumbZ(multiplicationNumbZ(A.a, getNumbZ(B.b)), multiplicationNumbZ(B.a, getNumbZ(A.b)));
	}
	else
		printf("Ошибка, числа не существует! \n");
	return C;
}