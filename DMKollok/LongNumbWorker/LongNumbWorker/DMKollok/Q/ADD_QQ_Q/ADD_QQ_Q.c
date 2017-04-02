/*

 addNumbQ

 Функция для сложения двух рациональных чисел

 Параметры:
 1) A - первое число
 2) B - второе число

 Функция возвращает результат типа - NUMBQ

*/

#include <stdlib.h>
#include <stdio.h>
#include "numbQ.h"
#include "ADD_QQ_Q.h"
#include "../../Z/TRANS_N_Z/TRANS_N_Z.h"
#include "../../Z/MUL_ZZ_Z/MUL_ZZ_Z.h"
#include "../../N/DIV_NN_N/DIV_NN_N.h"
#include "../../Z/ADD_ZZ_Z/ADD_ZZ_Z.h"
#include "../../N/LCM_NN_N/LCM_NN_N.h"

NUMBQ addNumbQ(NUMBQ A, NUMBQ B)
{
	NUMBQ C;
	if (A.a.A && A.b.A && B.a.A && B.b.A)
	{
		C.b = nokNumbN(A.b, B.b);
		C.a = addNumbZ(multiplicationNumbZ(getNumbZ(DivNumbN(C.b, A.b)), A.a), multiplicationNumbZ(getNumbZ(DivNumbN(C.b,B.b)), B.a));
	}
	else
		printf("Ошибка, числа не существует! \n");
	return C;
}