
#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "MUL_Nk_N/MUL_Nk_N.h"
#include "SUB_NDN_N/SUB_NN_N/SUB_NN_N.h"
#include "COM_NN_D/COM_NN_D.h"
#include "bfunc/bfunc.h"
#include "DIV_NN_Dk.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 getFirstNumbDivident
 
 Функция выдает первую цифру  деления большего числа умн на 10^k
 
 Параметры:
 1) fNumb - Первое число
 2) sNumb - Второе число
 
 Функция возращает тип - NUMBN
 
*/

NUMBN getFirstNumbDivident(NUMBN fNumb,NUMBN sNumb)
    {
        int error = 0,
            k = 0;
        NUMBN answer;
        if(fNumb.A && sNumb.A)
            {
                NUMBN a = fNumb;
                int comp, len = 0;
                
                a.A = (int*) realloc(a.A, sNumb.n*sizeof(int));
                a.n = sNumb.n;
                
                comp = compNumbers(a,sNumb);
                error = comp == -1;
                
                if(comp == 1)
                    {
                        a = fNumb;
                        a.A = (int*) realloc(a.A, (sNumb.n+1)*sizeof(int));
                        a.n = sNumb.n+1;
                    }
                len = a.n;
                do
                    {
                        ++k;
                        a = differenceNumb(a, sNumb);
                        comp = compNumbers(a,sNumb);
                        error = comp == -1;
                    }
                while(!error && (comp == 2 || comp == 0));
                answer.n = 1;
                answer.A = (int*) malloc(sizeof(int));
                *(answer.A) = k;
                elevenExp(&answer, fNumb.n-len);
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, число не существует!\n");
        
        return answer;
    }
