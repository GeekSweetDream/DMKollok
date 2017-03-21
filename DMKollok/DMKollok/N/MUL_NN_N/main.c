#include <stdlib.h>
#include <stdio.h>
#include "MUL_ND_N/MUL_ND_N.h"
#include "MUL_Nk_N/MUL_Nk_N.h"
#include "ADD_NN_N/ADD_NN_N.h"
#include "bfunc/bfunc.h"
#include "numbN.h"



int main(void) {
    return 0;
}


NUMBN multiplicationN(NUMBN numbF, NUMBN numbS)
    {
        NUMBN answer;
        NUMBN a;
        if(numbF.A && numbS.A)
            {
                turnNumber(numbF.A, numbF.n);
                turnNumber(numbS.A, numbS.n);
                answer.A = (int*) calloc( answer.n, sizeof(int));
                for (int i = 0; i < numbF.n; ++i)
                    {
                        a = multiplicateN(numbS, *(numbF.A+i));
                        answer = addNumbers(a, answer);
                    }
                
                
            }
        else
            printf("\nОшибка, число не существует!\n");
        return answer;
    }
