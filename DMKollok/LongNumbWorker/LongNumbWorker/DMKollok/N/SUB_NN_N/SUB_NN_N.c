
#include <stdio.h>
#include <stdlib.h>
#include "numbN.h"
#include "../bfunc/bfunc.h"
#include "../COM_NN_D/COM_NN_D.h"
#include "SUB_NN_N.h"

/*
  
 differenceNUmb
 
 Функция вычитание из одного натурального другое
 
 Параметры:
 1) fNumb - Первое число
 2) sNumb - Второе число
 
 Функция возращает тип - NUMBN
 
 */



NUMBN differenceNumb(NUMBN fNumb, NUMBN sNumb)
    {
        int error = 0;
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
                        
                        int min = 0;
                        for(int i = 0; i < sNumb.n; ++i)
                            {
                                *(answer.A+i) = *(fNumb.A+i) - *(sNumb.A+i) - min;
                                min = 0;
                                if(*(answer.A+i) < 0)
                                    {
                                        *(answer.A+i) += 10;
                                        min = 1;
                                    }
                                
                            }
                        if(sNumb.n!=fNumb.n)
                            {
                                for (int i = sNumb.n; i < fNumb.n; ++i)
                                    {
                                        *(answer.A+i) += *(fNumb.A+i) - min;
                                        min = 0;
                                    }
                            }
                        
                        int fl = 0,
                        i;
                        
                        for (i = fNumb.n-1; i >= 0 && !fl; --i)                         // Удаление нулей из числа
                            fl = *(answer.A + i) != 0;
                        
                        i+=2;
                        if(i != fNumb.n)
                            {
                                answer.n = i;
                                answer.A = (int*) realloc(answer.A, i*sizeof(int));
                            }

                        turnNumber(answer.A, answer.n);
                        turnNumber(fNumb.A, fNumb.n);
                        turnNumber(sNumb.A, sNumb.n);
                    }
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, одно из чисел не существует!\n");
        
        return answer;
    }
