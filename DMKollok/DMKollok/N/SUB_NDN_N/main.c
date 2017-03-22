#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "SUB_NN_N/SUB_NN_N.h"
#include "MUL_ND_N/MUL_ND_N.h"
#include "COM_NN_D/COM_NN_D.h"
#include "SUB_NN_N/bfunc/bfunc.h"

NUMBN differentNumbMultK (NUMBN fNumb, NUMBN sNumb, int k);

int main(void) {
    
    NUMBN a, b,c;
    a.n = 2;
    b.n = 3;
    a.A = (int*) malloc(a.n*sizeof(int));
    b.A = (int*) malloc(b.n*sizeof(int));
    
    for (int i = 0; i < a.n; ++i) {
        scanf("%d", a.A+i);
    }
    
    for (int i = 0; i < b.n; ++i) {
        scanf("%d", b.A+i);
    }
    
    c = differentNumbMultK(a,b, 4);

    for (int i = 0; i < c.n; ++i) {
        printf("%d", *(c.A+i));
    }

    
    return 0;
}


NUMBN differentNumbMultK (NUMBN fNumb, NUMBN sNumb, int k)
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
                        sNumb = multiplicateN(sNumb, k);
                        answer = differenceNumb(fNumb, sNumb);
                    }
            }
        else
            error = 1;
            
        if(error)
            printf("\nОшибка, число не существует!\n");
            
        return answer;
    }
