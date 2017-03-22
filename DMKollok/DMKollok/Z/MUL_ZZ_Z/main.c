
#include <stdlib.h>
#include <stdio.h>
#include "POZ_Z_D/POZ_Z_D.h"
#include "ABS_Z_N/ABS_Z_N.h"
#include "MUL_ZM_Z/MUL_ZM_Z.h"
#include "MUL_NN_N/MUL_NN_N.h"
#include "numbZ.h"
#include "numbN.h"

NUMBZ multiplicationNumbZ(NUMBZ a, NUMBZ b);

int main(int argc, const char * argv[]) {
    NUMBZ a;
    a.n = 3;
    a.A =(int*) calloc(a.n, sizeof(int));
    NUMBZ b;
    a.b = 0;
    b.b = 0;
    b.n = 3;
    b.A =(int*) calloc(a.n, sizeof(int));
    NUMBZ c;
    
    for (int i = 0; i < a.n; ++i)
        scanf("%d",a.A+i);
    for (int i = 0; i < b.n; ++i)
        scanf("%d",b.A+i);
    
    c = multiplicationNumbZ(a, b);
    printf("%d\n",c.b);
    for (int i = 0; i < c.n; ++i)
        printf("%d",*(c.A+i));
    

    return 0;
}


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
