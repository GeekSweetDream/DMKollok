
#include <stdlib.h>
#include <stdio.h>
#include "../DIV_NN_Dk/DIV_NN_Dk.h"
#include "../SUB_NN_N/SUB_NN_N.h"
#include "../ADD_NN_N/ADD_NN_N.h"
#include "../MUL_NN_N/MUL_NN_N.h"
#include "../bfunc/bfunc.h"
#include "numbN.h"
#include "DIV_NN_N.h"

/*
 
 DivNumbN
 
 Функция для вычисления частного от двух чисел
 
 Параметры:
 1) one - делимое число
 2) two - делитель число
 
 Функция возвращает результат типа - NUMBN
 
 */



NUMBN DivNumbN(NUMBN a, NUMBN b)
    {
        NUMBN ans;
        int error = 0;
        if(a.A && b.A)
            {
                NUMBN aD = a;
                for (int i = 0; i < a.n ; ++i)
                    *(aD.A+i) = *(a.A+i);
                ans.n = 1;
                ans.A = (int*) calloc(ans.n, sizeof(int));
                int comp;
                do
                    {
                        NUMBN k =getFirstNumbDivident(aD, b);
                        ans = addNumbers(k, ans);
                        aD = differenceNumb(aD, multiplicationTwoNumb(b, k));
                        comp = compNumbers(aD,b);
                        error = comp == -1;
                    }
                while(!error && (comp == 2 || comp == 0));
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, число не существует!\n");
        
        return ans;
    }
