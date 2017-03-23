#include <stdlib.h>
#include <stdio.h>
#include "numbN.h"
#include "DIV_NN_N/DIV_NN_N.h"
#include "DIV_NN_N/SUB_NDN_N/SUB_NN_N/SUB_NN_N.h"
#include "DIV_NN_N/MUL_NN_N/MUL_NN_N.h"

NUMBN modNumbN(NUMBN a, NUMBN b);

int main(int argc, const char * argv[]) {
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
    
    c = modNumbN(a, b);
    
    for (int i = 0 ; i<c.n; ++i) {
        printf("%d",*(c.A+i));
    }
    
    return 0;
}


NUMBN modNumbN(NUMBN a, NUMBN b)
    {
        NUMBN ans;
        int error = 0;
        if(a.A && b.A)
            {
                NUMBN k = DivNumbN(a, b);
                ans = differenceNumb(a, multiplicationTwoNumb(b, k));
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, число не существует!\n");
        
        return ans;
    }

