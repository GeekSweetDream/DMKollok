
#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "MUL_Nk_N/MUL_Nk_N.h"
#include "COM_NN_D/COM_NN_D.h"
#include "bfunc/bfunc.h"

NUMBN getFirstNumbDivident(NUMBN fNumb,NUMBN sNumb);

int main(void) {

    NUMBN a,b,c;
    
    a.n = 3;
    b.n = 3;
    
    a.A = (int*) malloc(a.n * sizeof(int));
    b.A = (int*) malloc(b.n * sizeof(int));
    
    for (int i = 0 ; i<a.n; ++i) {
        scanf("%d",a.A+i);
    }
    
    for (int i = 0 ; i<b.n; ++i) {
        scanf("%d",b.A+i);
    }

    c = getFirstNumbDivident(a, b);
    
    for (int i = 0 ; i<c.n; ++i) {
        printf("%d",*(c.A+i));
    }

    
    return 0;
}


NUMBN getFirstNumbDivident(NUMBN fNumb,NUMBN sNumb)
    {
        NUMBN answer;
        int error = 0;
        if(fNumb.A && sNumb.A)
            {
                int comp = compNumbers(fNumb,sNumb);
                error = comp == -1;
                if (!error)
                    {
                        if(comp == 1)
                            swapNumb(&fNumb, &sNumb);
                        
                        answer.n = 1;
                        answer.A = (int*) malloc(sizeof(int));
                        *(answer.A) = *(fNumb.A);
                        elevenExp(&answer, fNumb.n - 1);
                    }
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, число не существует!\n");
        
        return answer;
    }
