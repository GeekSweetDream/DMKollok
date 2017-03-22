
#include <stdio.h>
#include <stdlib.h>
#include "numbN.h"
#include "bfunc/bfunc.h"
#include "COM_NN_D/COM_NN_D.h"
#include "SUB_NN_N.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 differenceNUmb
 
 Функция вычитание из одного натурального другое
 
 Параметры:
 1) numbF - Первое число
 2) numbS - Второе число
 
 Функция возращает тип - NUMBN
 
 */



NUMBN differenceNumb(NUMBN numbF, NUMBN numbS)
    {
        int error = 0;
        NUMBN fNumb = numbF,
        sNumb = numbS;
        NUMBN answer;
        if(fNumb.A && sNumb.A)
            {
                int comp = compNumbers(fNumb, sNumb);
                error = comp == -1;
                if(!error)
                    {
                        if(comp == 1)
                            swapNumb(&fNumb, &sNumb);
                        
                        answer.A = (int*) malloc (fNumb.n*sizeof(int));
                        answer.n = fNumb.n;
                        turnNumber(fNumb.A, fNumb.n);
                        turnNumber(sNumb.A, sNumb.n);
                        
                        for(int i = 0; i < sNumb.n; ++i)
                            {
                                *(answer.A+i) = *(fNumb.A+i) - *(sNumb.A+i);
                                if(*(answer.A+i) < 0)
                                    {
                                        *(answer.A+i) += 10;
                                        *(fNumb.A+i+1) -= 1;
                                    }
                            }
                        if(sNumb.n!=fNumb.n)
                            {
                                for (int i = sNumb.n; i < fNumb.n; ++i)
                                    *(answer.A+i) += *(fNumb.A+i);
                            }
                        turnNumber(answer.A, answer.n);
                    }
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, одно из чисел не существует!\n");
        
        return answer;
    }
