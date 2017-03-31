#ifndef _NUMBP_H_
#define _NUMBP_H_
#include "numbQ.h"

typedef struct numbP
	{
		int m;		// Степень многочлена
		NUMBQ* C;	// Массив коэффициентов
	} NUMBP;

#endif
