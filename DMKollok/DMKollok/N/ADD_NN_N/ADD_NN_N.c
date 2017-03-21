#include <stdio.h>
#include <stdlib.h>
#include "COM_NN_D/COM_NN_D.h"
#include "numbN.h"
#include "ADD_NN_N.h"

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*

 swapNumb
 
 Функция меняет местами числа
 
 Параметры:
 1) numberOne - Первое число
 2) numberTwo - Второе число
 
 Функция ничего не возвращает
 
*/


void swapNumb(NUMBN* numberOne, NUMBN* numberTwo)
    {
        NUMBN a = *numberTwo;
        *numberTwo = *numberOne;
        *numberOne = a;
    }


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*

 turnNumber
 
 Функция переворачивает число
 
 Параметры:
 1) number - Первое число
 2) length - Второе число
 
 Функция ничего не возвращает
 
*/


void turnNumber(int* number, int length)
    {
        for(int i = 0; i < (length/2); ++i)
            {
                int a = *(number + i);
                *(number + i) = *(number + length - i - 1);
                *(number + length - i -1) = a;
            }
    }


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*

 addNumbers
 
 Функция сравнивает два натуральных числа
 
 Параметры:
 1) numbOne - Первое число
 2) numbTwo - Второе число
 
 Функция возвращает результат типа - NUMBN
 
*/

NUMBN addNumbers(NUMBN numbOne, NUMBN numbTwo)
    {
        int error = 0,
            base = 10,
            balance = 0;
        NUMBN answer;
        NUMBN one = numbOne;
        NUMBN two = numbTwo;
        if(numbOne.A && numbTwo.A)
            {
                turnNumber(one.A,one.n);
                turnNumber(two.A,two.n);
                int comp = compNumbers(numbOne, numbTwo);
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

