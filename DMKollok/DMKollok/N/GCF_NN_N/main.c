
#include <stdio.h>
#include "MOD_NN_N/MOD_NN_N.h"
#include "NZER_N_B/NZER_N_B.h"
#include "MOD_NN_N/DIV_NN_N/MUL_NN_N/ADD_NN_N/COM_NN_D/COM_NN_D.h"
#include "MOD_NN_N/DIV_NN_N/MUL_NN_N/bfunc/bfunc.h"
#include "numbN.h"

NUMBN nodNumbN(NUMBN fNumb, NUMBN sNumb);

int main(int argc, const char * argv[]) {

    NUMBN a,b,c;
    
    a.n = 3;
    b.n = 2;
    
    a.A = (int*) malloc(a.n * sizeof(int));
    b.A = (int*) malloc(b.n * sizeof(int));
    
    for (int i = 0 ; i<a.n; ++i) {
        scanf("%d",a.A+i);
    }
    
    for (int i = 0 ; i<b.n; ++i) {
        scanf("%d",b.A+i);
    }
    
    c = nodNumbN(a, b);
    
    for (int i = 0 ; i<c.n; ++i) {
        printf("%d",*(c.A+i));
    }
    return 0;
}


NUMBN nodNumbN(NUMBN fNumb, NUMBN sNumb)
    {
        NUMBN ans;
        int error = 0;
        if(fNumb.A && sNumb.A)
            {
                NUMBN a = fNumb, b=sNumb;
                int comp,
                    zero = 0;
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

