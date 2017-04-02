#include <stdio.h>
#include <stdlib.h>
#include "../COM_NN_D/COM_NN_D.h"
#include "numbN.h"
#include "ADD_NN_N.h"
#include "../bfunc/bfunc.h"


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*

 addNumbers
 
 Функция сравнивает два натуральных числа
 
 Параметры:
 1) one - Первое число
 2) two - Второе число
 
 Функция возвращает результат типа - NUMBN
 
*/

NUMBN addNumbers(NUMBN one, NUMBN two)
    {
        int error = 0,
            base = 10,
            balance = 0;
        NUMBN answer;
        if(one.A && two.A)
            {
                turnNumber(one.A,one.n);
                turnNumber(two.A,two.n);
                int comp = compNumbers(one, two);
                error = comp == -1;
                if(!error)
                    {
                        if(comp == 1)
                            swapNumb(&one, &two);
                        
                        helpAddNumber(one.A, two.A, &(answer.A), base, &balance, 1, 0, two.n);
                        helpAddNumber(one.A, two.A, &(answer.A), base, &balance, 0, two.n, one.n);
                        answer.n = one.n;
                        if(balance != 0)
                            {
                                answer.A = (int*) realloc(answer.A, (answer.n + 1)*sizeof(int));
                                *(answer.A + answer.n) = balance;
                                ++answer.n;
                            }
                        turnNumber(answer.A,answer.n);
                        turnNumber(one.A,one.n);
                        turnNumber(two.A,two.n);
                    }
                }
            else
                error = 1;
        
        if(error)
            printf("\nОшибка с числом, его не существует!\n");
        
        return answer;
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*

 helpAddNumber
 
 Вспомогательная функция для сложения 
 
 Параметры:
 1) numberOne - Первое число
 2) numberTwo - Второе число
 3) answer - Ответ
 4) base - Система счисления
 5) balance - Остаток
 6) addSecNumb - Добавить ли второе число
 7) begin - Начало
 8) end - Конец
 
 Функция ничего не возвращает
 
*/

void helpAddNumber(int* numberOne, int* numberTwo, int** answer, int base, int* balance, int addSecNumb, int begin, int end )
    {
        int numbAlen = begin;
        if(numbAlen == 0)
            *answer = (int*) malloc(sizeof(int));
        for(int i = begin; i < end; ++i)
            {
                int count = *(numberOne+i) + *balance;
                count += addSecNumb? *(numberTwo + i): 0;
                *balance = count / base;
                count %= base;
                *answer = (int*) realloc(*answer, (numbAlen + 1) * sizeof(int));
                *(*answer+numbAlen) = count;
                ++numbAlen;
            }
    }

