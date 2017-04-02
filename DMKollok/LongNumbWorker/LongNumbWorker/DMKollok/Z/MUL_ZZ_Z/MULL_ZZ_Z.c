
#include <stdlib.h>
#include <stdio.h>
#include "../POZ_Z_D/POZ_Z_D.h"
#include "../ABS_Z_N/ABS_Z_N.h"
#include "../MUL_ZM_Z/MUL_ZM_Z.h"
#include "../../N/MUL_NN_N/MUL_NN_N.h"
#include "numbZ.h"
#include "numbN.h"
#include "MUL_ZZ_Z.h"

NUMBZ multiplicationNumbZ(NUMBZ a, NUMBZ b)
    {
        int error = 0;
        NUMBZ answer;
        NUMBN c;
        if(a.A && b.A)
            {
                NUMBN aN,bN;
                aN = absNumbZ(a);
                bN = absNumbZ(b);
                if(aN.A && bN.A)
                    {
                        c = multiplicationTwoNumb(aN, bN);
                        answer.b = 0;
                        answer.n = c.n;
                        answer.A = (int*) malloc(answer.n*sizeof(int));
                        for(int i = 0; i < c.n; ++i)
                            *(answer.A + i) = *(c.A+i);
                        if(a.b != b.b)
                            multiMinusOne(&answer);
                    }
                else
                    error = 1;
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, числа не существует!\n");
        
        return answer;
    }
