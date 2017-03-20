
#include <stdio.h>
#include <stdlib.h>
#include "numbN.h"
#include "bfunc/bfunc.h"
#include "COM_NN_D/COM_NN_D.h"


NUMBN differenceNumb(NUMBN numbF, NUMBN numbS);

int main(void) {
    
    NUMBN a, b;
    NUMBN c;
    a.n = 2;
    b.n = 2;
    a.A = (int*) malloc(a.n*sizeof(int));
    b.A = (int*) malloc(b.n*sizeof(int));
    
    for(int i = 0; i <a.n; ++i)
        scanf("%d",a.A+i);
    
    for(int i = 0; i <b.n; ++i)
        scanf("%d",b.A+i);
    
    c = differenceNumb(a, b);
    
    for(int i = 0; i <c.n; ++i)
        printf("%d",*(c.A+i));
    
    return 0;

}


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
                                printf("\n%d %d",*(fNumb.A+i),*(sNumb.A+i));
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
