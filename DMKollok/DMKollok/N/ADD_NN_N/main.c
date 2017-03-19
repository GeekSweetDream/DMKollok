
#include <stdio.h>
#include <stdlib.h>
#include "COM_NN_D/COM_NN_D.h"
#include "numbN.h"

void turnNumber(int* number, int length);                                                                                               // Функция для переворота числа
void swapNumb(NUMBN* numberOne, NUMBN* numberTwo);                                                                                      // Функция для обмена указателей
void helpAddNumber(int* numberOne, int* numberTwo, int** answer, int base, int* balance, int addSecNumb, int begin, int end );           // Вспомогательная функция для сложения
NUMBN addNumbers(NUMBN numbOne, NUMBN numbTwo);                                                                                     // Функция для сложения двух чисел


int main()
    {
        NUMBN number;                      // Число, которое введет пользователь
        NUMBN numbert;
        NUMBN answer;                      // Ответ
        number.n = 1;
        numbert.n = 1;
        number.A = (int*) malloc(number.n*sizeof(int));
        numbert.A = (int*) malloc((numbert.n)*sizeof(int));
        for (int i = 0;  i < 1; ++i) {
            scanf("%d",number.A+i);
            scanf("%d",numbert.A+i);
        }
        
        
//        for(int i = 0; i < 5; ++i)
//            printf("%d",*(number.A+i));
//        printf("\n");
//        
//        for(int i = 0; i < 6; ++i)
//            printf("%d",*(numbert.A+i));
//        printf("\n");
        
        
        answer = addNumbers(number, numbert);
        
        for(int i = 0; i < answer.n; ++i)
            printf("%d",*(answer.A+i));
        printf("\n");
        return 0;
    }


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 
 Функция для обмена указателей
 
 */

void swapNumb(NUMBN* numberOne, NUMBN* numberTwo)
    {
        NUMBN a = *numberTwo;
        *numberTwo = *numberOne;
        *numberOne = a;
    }


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
 
 Функция для переворота числа
 
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
 
 Функция для сложения числа
 
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
 
 Вспомогательная функция для сложения
 
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


