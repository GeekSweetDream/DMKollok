
#include <stdio.h>
#include "numbN.h"

// Функция для тестирования моей функции

int compNumbers(NUMBN fNumb, NUMBN sNumb);

int main(void)
    {
        NUMBN a,b;
        a.n = 5;
        b.n = 5;
        a.A = (int*) malloc(a.n*sizeof(int));
        b.A = (int*) malloc(b.n*sizeof(int));
        for(int i =0; i < 5; ++i)
            {
                scanf("%d",(a.A+i));
                scanf("%d",(b.A+i));
            }
        printf("%d\n",compNumbers(a, b));
        
        // Позже здесь будет код!
    
        return 0;
    }

/*

 compNumbers
 
 Функция сравнивает два целых числа, и возвращает: 2, если первое больше второго,
 0, если они равны, иначе 1, если ошибка, то выводит -1
 
 Параметры:
 1) fNumb - Первое число
 2) sNumb - Второе число
 
 Функция возвращает результат типа - int
 
*/


int compNumbers(NUMBN fNumb, NUMBN sNumb)
    {
        int answer = 0;
        if(fNumb.A && sNumb.A)
            {
                if(fNumb.n == sNumb.n)
                    {
                        int len = fNumb.n,
                            fl = 1;
                        for(int i = 0; (i < len) && fl; ++i )
                            {
                                fl = i < len && *(fNumb.A+i) == *(sNumb.A+i);
                                if((!fl) && (i < len))
                                    answer = *(fNumb.A+i) > *(sNumb.A+i)? 2: 1;
                            }
                    }
                else
                    answer = fNumb.n > sNumb.n? 2: 1;
            }
        else
            answer = -1;
        
        return answer;
    }

