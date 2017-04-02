
#include <stdio.h>
#include "../MOD_NN_N/MOD_NN_N.h"
#include "../NZER_N_B/NZER_N_B.h"
#include "../COM_NN_D/COM_NN_D.h"
#include "../bfunc/bfunc.h"
#include "numbN.h"
#include "GCF_NN_N.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 nodNumbN
 
 Функция для нахождения нод двух чисел
 
 Параметры:
 1) fNumb - Первое число
 2) sNumb - Второе число
 
 Функция возращает тип - NUMBN
 
 */

NUMBN nodNumbN(NUMBN fNumb, NUMBN sNumb)
    {
        NUMBN ans;
        int error = 0;
        if(fNumb.A && sNumb.A)
            {
                NUMBN a = fNumb, b=sNumb;
                int comp = compNumbers(a, b);
                
                if(comp == 1)
                    swapNumb(&a, &b);
                
                int zero = 0;
                do
                    {
                        a = modNumbN(a, b);
                        comp = compNumbers(a, b);
                        error = comp == -1;
                        zero = isZero(a) && isZero(b);
                        if(comp == 1)
                            swapNumb(&a, &b);
                    }
                while (!error && zero);
                ans = a;
            }
        else
            error = 1;
    
        if(error)
            printf("\nОшибка, число не существует!\n");
    
        return ans;
    }

