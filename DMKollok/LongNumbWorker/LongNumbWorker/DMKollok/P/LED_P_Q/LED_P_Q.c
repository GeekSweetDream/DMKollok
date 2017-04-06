/*

 Функция для получения старшего коэффициента многочлена

 Параметры:
 1) A - многочлен

 Функция возвращает результат типа - NUMBQ

*/

#include <stdio.h>
#include "numbP.h"

NUMBQ getLeadingCoef(NUMBP A)
{
	return A.C;
}
