#ifndef _NUMBQ_H_
#define _NUMBQ_H_
#include "numbN.h"
#include "numbZ.h"

typedef struct numbQ
	{
        NUMBZ a;        // Числитель
        NUMBN b;        // Знаменатель
        
    } NUMBQ;

#endif
