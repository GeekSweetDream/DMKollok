/*

 getSign

 Функция для определения положительности числа. Возвращает: 2 - число положительное,
 0 - равное нулю, 1 - отрицательное, -1 - ошибка

 Параметры:
 1) numb - целое число

 Функция возвращает результат типа - int

*/

#include <stdio.h>
#include "numbZ.h"
#include "POZ_Z_D.h"

int getSign(NUMBZ numb)
{
	int check = -1;
	
	if (numb.A)
	{
		for (int i = 0;i < numb.n && check;++i)
			check = *(numb.A + i) == 0;
    
        check = check? 0: (numb.b == 1)? 1 : 2;
	}

	return check;
}
