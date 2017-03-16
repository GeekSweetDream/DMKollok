
#include <stdio.h>
#include "numbN.h"

// Функция для тестирования моей функции


int main(void)
    {
        
        
        // Позже здесь будет код!
    
        return 0;
    }

/*
 compNumbers
 
 Функция сравнивает два целых числа, и возвращает: 2, если первое больше второго,
 0, если они равны, иначе 1
 
 Параметры:
 1) fNumb - Первое число
 2) sNumb - Второе число
 
 Функция возвращает результат типа - int
 */


int compNumbers(NUMBN fNumb, NUMBN sNumb)
    {
        int answer = 0;
        if(fNumb.n == sNumb.n)
            {
                int len = fNumb.n,
                    fl = 0;
                for(int i = 0; (i < len) && !fl; ++i )
                    {
                        fl = i < len && *(fNumb.A+i) == *(sNumb.A+i);
                        if((!fl) && (i != len))
                            answer = *(fNumb.A+i) > *(sNumb.A+i)? 2: 1;
                    }
            }
        else
            answer = *(fNumb.A) > *(sNumb.A)? 2: 1;
        
        return answer;
    }

