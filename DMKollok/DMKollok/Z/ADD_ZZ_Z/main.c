
#include <stdlib.h>
#include <stdio.h>
#include "COM_NN_D/COM_NN_D.h"
#include "ABS_Z_N/ABS_Z_N.h"
#include "ADD_NN_N/ADD_NN_N.h"
#include "SUB_NN_N/SUB_NN_N.h"
#include "MUL_ZM_Z/MUL_ZM_Z.h"
#include "POZ_Z_D/POZ_Z_D.h"
#include "numbZ.h"
#include "numbN.h"

NUMBZ addNumbZ(NUMBZ a, NUMBZ b);


int main(void) {
    
    NUMBZ a;
    a.n = 3;
    a.A =(int*) calloc(a.n, sizeof(int));
    NUMBZ b;
    a.b = 0;
    b.b = 1;
    b.n = 3;
    b.A =(int*) calloc(a.n, sizeof(int));
    NUMBZ c;

    for (int i = 0; i < a.n; ++i)
        scanf("%d",a.A+i);
    for (int i = 0; i < b.n; ++i)
        scanf("%d",b.A+i);
    
    c = addNumbZ(a, b);
    printf("%d\n",c.b);
    for (int i = 0; i < c.n; ++i)
        printf("%d",*(c.A+i));
    
    
    
    
    return 0;
}


NUMBZ addNumbZ(NUMBZ a, NUMBZ b)
    {
        NUMBZ answer;
        NUMBN c;
        int error = 0;
        if(a.A && b.A)
            {
                NUMBN aN, bN;
                aN = absNumbZ(a);
                bN = absNumbZ(b);
                if(aN.A && bN.A)
                    {
                        int comp = compNumbers(aN, bN);
                        int fl = 0;
                        error = comp ==-1;
                        if(!error)
                        {
                            if(a.b == b.b)
                                {
                                    c = addNumbers(aN, bN);
                                    fl = a.b == 1;
                                }
                            else
                                {
                                    c = differenceNumb(aN, bN);
                                    fl = (comp == 1 && b.b == 1) || (comp == 2 && a.b == 1);
                                }
                            answer.b = 0;
                            answer.n = c.n;
                            answer.A = (int*) malloc(c.n*sizeof(int));
                            for (int i = 0; i < c.n; ++i)
                                *(answer.A + i) = *(c.A+i);
                            
                            if(fl)
                                multiMinusOne(&answer);
                        }
                    }
                else
                    error = 1;
            }
        else
            error = 1;
        
        if(error)
            printf("\nОшибка, число не существует!\n");
        
        return answer;
    }
