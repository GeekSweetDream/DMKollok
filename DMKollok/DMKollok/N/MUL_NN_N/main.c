#include <stdlib.h>
#include <stdio.h>
#include "MUL_ND_N/MUL_ND_N.h"
#include "MUL_Nk_N/MUL_Nk_N.h"
#include "ADD_NN_N/ADD_NN_N.h"
#include "numbN.h"

NUMBN multiplicationTwoNumb(NUMBN numbF, NUMBN numbS);

int main(void) {
    NUMBN a,b,c;
    a.n = 2;
    b.n = 2;
    a.A = (int*) malloc(a.n*sizeof(int));
    b.A = (int*) malloc(b.n*sizeof(int));
    for (int i = 0; i < a.n; ++i) {
        scanf("%d", a.A+i);
    }
    for (int i = 0; i < b.n; ++i) {
        scanf("%d", b.A+i);
    }
    c = multiplicationTwoNumb(a, b);
    for (int i = 0; i < c.n; ++i) {
        printf("%d", *(c.A+i));
    }
    
    return 0;
}


NUMBN multiplicationTwoNumb(NUMBN numbF, NUMBN numbS)
    {
        NUMBN answer;
        NUMBN a;
        if(numbF.A && numbS.A)
            {
                answer.A = (int*) calloc (answer.n, sizeof(int));
                answer.n = numbF.n>numbS.n?numbS.n:numbF.n;
                for (int i = numbF.n-1; i >= 0; --i)
                    {
                        a = multiplicateN(numbS, *(numbF.A+i));
                        for (int i = 0; i < a.n; ++i) {
                            printf("%d", *(a.A+i));
                        }
                        printf("\n");
                        elevenExp(&a, numbF.n-i-1);
                        for (int i = 0; i < a.n; ++i) {
                            printf("%d", *(a.A+i));
                        }
                        printf("\n");

                        answer = addNumbers(a, answer);
                        for (int i = 0; i < answer.n; ++i) {
                            printf("%d", *(answer.A+i));
                        }
                        printf("\n");

                    }
                
            }
        else
            printf("\nОшибка, число не существует!\n");
        return answer;
    }
