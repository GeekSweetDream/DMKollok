/*

 getSign

 Функция для определения положительности числа. Возвращает: 2 - число положительное,
 0 - равное нулю, 1 - отрицательное

 Параметры:
 1) numb - целое число

 Функция возвращает результат типа - int

*/

#include <stdio.h>
#include "numbZ.h"
#include "POZ_Z_D.h"

int getSign(NUMBZ numb)
{
	int check = numb.b;
	
	for (int i = 0;i < numb.n && check;++i)
		check = *(numb.A + i) == 0;
	if (check)
		check = 0;
	else
		if (numb.b == 1)
			check = 1;
		else
			check = 2;
	return check;
}