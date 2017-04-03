
#include <stdio.h>
#include <stdlib.h>
#include "DMKollok/N/numbN.h"
#include "DMKollok/Z/numbZ.h"
#include "DMKollok/Q/numbQ.h"
#include "DMKollok/P/numbP.h"
#include "DMKollok/N/ADD_NN_N/ADD_NN_N.h"
#include "DMKollok/N/SUB_NN_N/SUB_NN_N.h"
#include "DMKollok/N/MUL_NN_N/MUL_NN_N.h"
#include "DMKollok/N/DIV_NN_N/DIV_NN_N.h"
#include "DMKollok/N/MOD_NN_N/MOD_NN_N.h"
#include "DMKollok/N/GCF_NN_N/GCF_NN_N.h"
#include "DMKollok/N/LCM_NN_N/LCM_NN_N.h"
#include "DMKollok/N/COM_NN_D/COM_NN_D.h"
#include "DMKollok/Z/ADD_ZZ_Z/ADD_ZZ_Z.h"
#include "DMKollok/Z/SUB_ZZ_Z/SUB_ZZ_Z.h"
#include "DMKollok/Z/MUL_ZZ_Z/MUL_ZZ_Z.h"
#include "DMKollok/Z/DIV_ZZ_Z/DIV_ZZ_Z.h"
#include "DMKollok/Z/MOD_ZZ_Z/MOD_ZZ_Z.h"
#include "DMKollok/Q/ADD_QQ_Q/ADD_QQ_Q.h"
#include "DMKollok/Q/SUB_QQ_Q/SUB_QQ_Q.h"
#include "DMKollok/Q/MUL_QQ_Q/MUL_QQ_Q.h"
#include "DMKollok/Q/DIV_QQ_Q/DIV_QQ_Q.h"
#include "DMKollok/Q/RED_Q_Q/RED_Q_Q.h"
#include "DMKollok/P/ADD_PP_P/ADD_PP_P.h"
#include "DMKollok/P/SUB_PP_P/SUB_PP_P.h"
#include "DMKollok/P/MUL_PQ_P/MUL_PQ_P.h"

int showMenu(void);                         // Функция выводит меню для пользователя и принимает, вводимое им число
int showSubMenu(int ch);                    // Функция выводит подменю для пользователя и принимает, вводимое им число
int* inputString(int* len);                 // Функция для перевода из символов в цифры

NUMBN inputN();                             // Функция для ввода натуральных чисел
void printNumb(int* numb, int len);         // Функция для вывода натуральных чисел
int* freeNumb(int** numb);                  // Функция для освобождения натуральных чисел
void actionN();                             // Функция для подменю для выбора действий с натуральными числами


NUMBZ inputZ();                             // Функция для ввода целых чисел
void actionZ();                             // Функция для подменю для выбора действий с целыми числами
void printNumbZ(NUMBZ numb);                // Функция для вывода целых чисел

NUMBQ inputQ();                             // Функция для ввода рациональных чисел
void actionQ();                             // Функция для подменю для выбора действий с рациональными числами
void printNumbQ(NUMBQ numb);                // Функция для вывода рациональных чисел

NUMBP inputP();                             //Функция для ввода коэффициентов многочлена
void actionP();                             // Функция для подменю для выбора действий с многочленами числами
void printNumbP(NUMBP numb);                // Функция для ввода коэффициентов многочлена
NUMBQ* freeP(NUMBP* numbp);                 // Функция для освобождения памяти из под многочлена

int main(void)
    {
        int exit = 0;
        do
            {
                int choice = showMenu();
                switch (choice) {
                    case 1:
                        actionN();
                        break;
                    case 2:
                        actionZ();
                        break;
                    case 3:
                        actionQ();
                        break;
                    case 4:
                        actionP();
                        break;
                    case 0:
                        exit = 1;
                        printf("\nПрограмма завершена!\n");
                        break;
                        
                    default:
                        printf("\nОшибка, выбран не существующий пункт меню!");
                        break;
                }
            }
        while(!exit);
        return 0;
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
 
 Функция выводит меню для пользователя и принимает, вводимое им число
 
 */

int showMenu(void)
    {
        int choiceUser;
        puts("\nВыберите тип чисел, с которыми будете работать: \n1. Натуральные числа\n2. Целые числа  \n3. Рациональные числа \n4. Многочлены \n\n0. Выйти из программы\n");
        printf("Ваш выбор: ");
        scanf("%d",&choiceUser);
        
        scanf( "%*[^\n]" );         // Эти две команды нужны для того, чтобы очистить поток ввода
        scanf( "%*c" );
    
        return choiceUser;
    }


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
 
 Функция выводит подменю для пользователя и принимает, вводимое им число
 
*/

int showSubMenu(int ch)
    {
        int choiceUser;
        switch (ch) {
            case 1:
                printf("\nВыберите действие: \n1. Ввести числа\n2. Сложение чисел \n3. Разность чисел \n4. Умножение чисел \n5. Частное от деления \n6. Остаток от деления \n7. НОД чисел \n8. НОК чисел \n9. Сравнение двух чисел\n10. Вывести ваши числа\n\n0. Выйти в главное меню\n");
                break;
            case 2:
                printf("\nВыберите действие:\n1. Ввести числа \n2. Сложение чисел \n3. Разность чисел \n4. Умножение чисел \n5. Частное от деления \n6. Остаток от деления \n7. Вывести ваши числа \n\n0. Выйти в главное меню\n");
                break;
            case 3:
                printf("\nВыберите действие: \n1. Ввести дроби \n2. Сложение дробей \n3. Разность дробей \n4. Умножение дробей \n5. Деление дробей \n6. Сокращение дробей \n7. Вывести ваши числа \n\n0. Выйти в главное меню\n");
                break;
            case 4:
                printf("\nВыберите действие: \n1. Ввести многочлены\n2. Сложение многочленов \n3. Разность многочленов \n4. Умножение многочлена на рациональное число \n5. Степень многочлена \n\n0. Выйти в главное меню\n");
                break;
            default:
                printf("\nОшибка, пункт меню не существует!\n");
                break;
        }

        printf("\nВаш выбор: ");
        scanf("%d",&choiceUser);
    
        scanf( "%*[^\n]" );         // Эти две команды нужны для того, чтобы очистить поток ввода
        scanf( "%*c" );
    
        return choiceUser;
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для подменю для выбора действий с натуральными числами

 */


void actionN()
    {
        int complFstage = 0,
            exit = 0,
            ch;
        NUMBN a,b,c;
        a.A = NULL;
        b.A = NULL;
        c.A = NULL;
        do
            {
                ch = showSubMenu(1);
                switch (ch) {
                    case 1:
                        a.A = freeNumb(&a.A);
                        a.A = freeNumb(&b.A);
                        a = inputN();
                        b = inputN();
                        printf("\nВаше первое число: ");
                        printNumb(a.A,a.n);
                        printf("\nВаше второе число: ");
                        printNumb(b.A,b.n);
                        complFstage = 1;
                        break;


                    case 2:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = addNumbers(a, b);
                                printf("\nСумма равна: ");
                                printNumb(c.A,c.n);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        break;
                        
                    case 3:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = differenceNumb(a, b);
                                printf("\nРазность равна: ");
                                printNumb(c.A,c.n);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        //diff
                        break;
                    case 4:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = multiplicationTwoNumb(a, b);
                                printf("\nПроизведение равно: ");
                                printNumb(c.A,c.n);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        //MULL
                        break;
                    case 5:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = DivNumbN(a, b);
                                printf("\nЧастное равно: ");
                                printNumb(c.A,c.n);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        //div
                        break;
                    case 6:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = modNumbN(a, b);
                                printf("\nОстаток равно: ");
                                printNumb(c.A,c.n);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        //mod
                        break;
                    case 7:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = nodNumbN(a, b);
                                printf("\nНОД равен: ");
                                printNumb(c.A,c.n);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        //NOD
                        break;
                    case 8:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = nokNumbN(a, b);
                                printf("\nНОК равен: ");
                                printNumb(c.A,c.n);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        //NOK
                        break;
                    case 9:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                int ans = compNumbers(a,b);
                                if(ans)
                                    {
                                        if(ans == 1)
                                            printf("\nВторое число больше\n");
                                        else
                                            printf("\nПервое число больше\n");
                                    }
                                else
                                    printf("\nОни равны\n");
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        //COMP
                        break;

                    case 10:
                        printf("\nВаше первое число: ");
                        printNumb(a.A,a.n);
                        printf("\nВаше второе число: ");
                        printNumb(b.A,b.n);
                        break;

                    case 0:
                        exit = 1;
                        c.A = freeNumb(&a.A);
                        c.A = freeNumb(&b.A);
                        c.A = freeNumb(&c.A);
                        break;
                    default:
                        printf("\nОшибка, выбран не существующий пункт меню!\n");
                        break;
                }
                printf("\nНажмите enter для продолжния!\n");
                getchar();
            }
        while (!exit);
    
    }


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для ввода натуральных чисел

 */

NUMBN inputN()
    {
        NUMBN numb;
        numb.A = inputString(&numb.n);
        return numb;
    }
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для перевода из символов в цифры

 */

int* inputString(int* len)
    {

        int err = 0;
        char* arr = NULL;
        char ch;
        int* numb = NULL;
        *len = 0;
        printf("Введите число: ");
        do
            {
                err = 0;
                scanf("%c",&ch);
                if(len)
                    arr = (char*) realloc(arr,(*len+1)*sizeof(char));
                else
                    arr = (char*) malloc(sizeof(char));
                err = *len == 0 && ch == '\n';
                if(!err)
                    {
                        if(ch > 47 && ch < 58)
                        {
                            *(arr+*len) = ch;
                            ++*len;
                        }
                    }
                else
                    printf("\nБыла введено пустое значение!\n");
            }
        while (err || ch != '\n' );
        numb = (int*) malloc((*len)*sizeof(int));
        for(int i = 0; i < *len; ++i )
            *(numb+i) = *(arr + i) - '0';

        return numb;
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для вывода натуральных чисел

 */

void printNumb(int* numb,int len)
    {
        for(int i = 0; i < len; ++i)
            printf("%d",*(numb+i));
        //printf("\n");
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для освобождения натуральных чисел

 */

int* freeNumb(int** numb)
    {
        if(*numb)
            free(*numb);
        return NULL;
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для подменю для выбора действий с целыми числами

 */

void actionZ()
    {
        int complFstage = 0,
                exit = 0,
                ch;
        NUMBZ a,b,c;
        a.A = NULL;
        b.A = NULL;
        c.A = NULL;
        do
            {
                ch = showSubMenu(2);
                switch (ch) {
                    case 1:
                        a.A = freeNumb(&a.A);
                        b.A = freeNumb(&a.A);
                        a = inputZ();
                        b = inputZ();
                        printf("\nВаше первое число: ");
                        printNumbZ(a);
                        printf("\nВаше второе число: ");
                        printNumbZ(b);
                        complFstage = 1;
                        //Ввод числа
                        break;

                    case 2:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = addNumbZ(a, b);
                                printf("\nСумма равна: ");
                                printNumbZ(c);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        //Сложение
                        break;
                    case 3:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = diffNumbZ(a, b);
                                printf("\nРазность равна: ");
                                printNumbZ(c);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        //diff
                        break;
                    case 4:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = multiplicationNumbZ(a, b);
                                printf("\nПроизведение равно: ");
                                printNumbZ(c);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        //MULL
                        break;
                    case 5:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = divNumbZ(a, b);
                                printf("\nЧастное равно: ");
                                printNumbZ(c);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        //div
                        break;
                    case 6:
                        if(complFstage)
                            {
                                c.A = freeNumb(&c.A);
                                c = modNumbZ(a, b);
                                printf("\nОстаток равен: ");
                                printNumbZ(c);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        //mod
                        break;
                    case 7:
                        if(complFstage)
                            {
                                printf("\nВаше первое число: ");
                                printNumbZ(a);
                                printf("\nВаше второе число: ");
                                printNumbZ(b);
                                break;
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                    case 0:
                        a.A = freeNumb(&a.A);
                        b.A = freeNumb(&b.A);
                        c.A = freeNumb(&c.A);
                        exit = 1;
                        break;
                    default:
                        printf("\nОшибка, выбран не существующий пункт меню!\n");
                        break;
                }
                printf("\nНажмите enter для продолжния!\n");
                getchar();
            }
        while (!exit);

    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для ввода целых чисел

 */


NUMBZ inputZ()
    {
        int err = 0,
            s;
        NUMBZ numb;
        do
            {
                printf("\nВведи знак ( 1 - отрицательное, 0 - положительное): ");
                scanf("%d",&s);
                scanf( "%*[^\n]" );         // Эти две команды нужны для того, чтобы очистить поток ввода
                scanf( "%*c" );
                err = s == 0 || s == 1;
                if(!err)
                    printf("\nБыл введен неверный символ!");
            }
        while(!err);
        numb.b = s;
        numb.A = inputString(&numb.n);
        return numb;
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для вывода целых чисел

 */


void printNumbZ(NUMBZ numb)
    {
        if(numb.b)
            printf("-");
        printNumb(numb.A,numb.n);
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для подменю для выбора действий с рациональными числами

 */


void actionQ()
    {
        int complFstage = 0,
                exit = 0,
                ch;
        NUMBQ a,b,c;
        a.a.A = NULL;
        b.a.A = NULL;
        c.a.A = NULL;
        a.b.A = NULL;
        b.b.A = NULL;
        c.b.A = NULL;
        do
            {
                ch = showSubMenu(3);
                switch (ch) {
                    case 1:
                        a.a.A = freeNumb(&a.a.A);
                        b.a.A = freeNumb(&b.a.A);
                        a.b.A = freeNumb(&a.b.A);
                        b.b.A = freeNumb(&b.b.A);
                        a = inputQ();
                        b = inputQ();
                        printf("\nВаше первое число: ");
                        printNumbQ(a);
                        printf("\nВаше второе число: ");
                        printNumbQ(b);
                        complFstage = 1;
                        //Ввод числа
                        break;

                    case 2:
                        if(complFstage)
                            {
                                c.a.A = freeNumb(&c.a.A);
                                c.b.A = freeNumb(&c.b.A);
                                c = addNumbQ(a, b);
                                printf("\nСумма равна: ");
                                printNumbQ(c);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        //Сложение
                        break;
                    case 3:
                        if(complFstage)
                            {
                                c.a.A = freeNumb(&c.a.A);
                                c.b.A = freeNumb(&c.b.A);
                                c = subtractNumbQ(a, b);
                                printf("\nРазность равна: ");
                                printNumbQ(c);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        //diff
                        break;
                    case 4:
                        if(complFstage)
                            {
                                c.a.A = freeNumb(&c.a.A);
                                c.b.A = freeNumb(&c.b.A);
                                c = multiplicationNumbQ(a, b);
                                printf("\nПроизведение равно: ");
                                printNumbQ(c);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        //MULL
                        break;
                    case 5:
                        if(complFstage)
                            {
                                c.a.A = freeNumb(&c.a.A);
                                c.b.A = freeNumb(&c.b.A);
                                c = divNumbQ(a, b);
                                printf("\nДеление равно: ");
                                printNumbQ(c);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        //div
                        break;
                    case 6:
                        if(complFstage)
                            {
                                c.a.A = freeNumb(&c.a.A);
                                c.b.A = freeNumb(&c.b.A);
                                c = reductNumbQ(a);
                                printf("\nСокращение дроби равно: ");
                                printNumbQ(c);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        break;
                    case 7:
                        if(complFstage)
                            {
                                printf("\nВаше первое число: ");
                                printNumbQ(a);
                                printf("\nВаше второе число: ");
                                printNumbQ(b);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        break;
                    case 0:
                        exit = 1;
                        c.a.A = freeNumb(&c.a.A);
                        c.b.A = freeNumb(&c.b.A);
                        a.a.A = freeNumb(&a.a.A);
                        b.a.A = freeNumb(&b.a.A);
                        a.b.A = freeNumb(&a.b.A);
                        b.b.A = freeNumb(&b.b.A);
                        break;
                    default:
                        printf("\nОшибка, выбран не существующий пункт меню!\n");
                        break;
                }

                printf("\nНажмите enter для продолжния!\n");
                getchar();
            }
        while (!exit);

    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для ввода рациональных чисел

 */


NUMBQ inputQ()
    {
        NUMBQ numb;
        printf("Введи числитель: ");
        numb.a = inputZ();
        printf("Введи знаменатель: \n");
        numb.b.A = inputString(&numb.b.n);
        return numb;
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для вывода рациональных чисел

 */

void printNumbQ(NUMBQ numb)
    {
        printNumbZ(numb.a);
        printf("/");
        printNumb(numb.b.A,numb.b.n);
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для подменю для выбора действий с многочленами числами

 */


void actionP()
    {
        int complFstage = 0,
                exit = 0,
                ch;
        NUMBP a,b,c;
        a.C = NULL;
        b.C = NULL;
        c.C = NULL;
        do
            {
                ch = showSubMenu(4);
                switch (ch) {
                    case 1:
                        a.C = freeP(&a);
                        b.C = freeP(&b);
                        a = inputP();
                        b = inputP();
                        printf("\nВаше первое число: ");
                        printNumbP(a);
                        printf("\nВаше второе число: ");
                        printNumbP(b);
                        complFstage = 1;
                        //Ввод числа
                        break;

                    case 2:
                        if(complFstage)
                            {
                                c.C = freeP(&c);
                                c = addNumbP(a, b);
                                printf("\nСумма равна: ");
                                printNumbP(c);
                                printf("\n");
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        //Сложение
                        break;
                    case 3:
                        if(complFstage)
                            {
                                c.C = freeP(&c);
                                c = subtractNumbP(a, b);
                                printf("\nРазность равна: ");
                                printNumbP(c);
                                printf("\n");
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        //diff
                        break;
                    case 4:
                        if(complFstage)
                            {
                                NUMBQ numbq = inputQ();
                                c.C = freeP(&c);
                                c = multiplicationNumbPQ(a, numbq);
                                printf("\nУмножение на рациональное равно: ");
                                printNumbP(c);
                                printf("\n");
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");
                        //MULL
                        break;
                    case 6:
                        if(complFstage)
                            {
                                printf("\nВаше первое число: ");
                                printNumbP(a);
                                printf("\nВаше второе число: ");
                                printNumbP(b);
                            }
                        else
                            printf("\nОшибка, сначала нужно ввести числа!\n");

                        break;
                    case 0:
                        exit = 1;
                        a.C = freeP(&a);
                        b.C = freeP(&b);
                        c.C = freeP(&c);
                        break;
                    default:
                        printf("\nОшибка, выбран не существующий пункт меню!\n");
                        break;
                }
                printf("\nНажмите enter для продолжния!\n");
                getchar();
            }
        while (!exit);

    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для ввода коэффициентов многочлена

 */

NUMBP inputP()
    {
        int err = 0,
                s;
        NUMBP numb;
        do
            {
                printf("\nВведите степень многочлена: ");
                scanf("%d",&s);
                err = s >= 0;
                if(!err)
                    printf("\nБыл введен неверный символ!");
            }
        while(!err);
        scanf( "%*[^\n]" );         // Эти две команды нужны для того, чтобы очистить поток ввода
        scanf( "%*c" );
        numb.m = s;

        for(int i = 0; i < s + 1; ++i)
            {
                printf("\nВведите коэффициент:\n");
                if(i)
                    numb.C = (NUMBQ*) realloc(numb.C, (i+1)*sizeof(NUMBQ));
                else
                    numb.C = (NUMBQ*) malloc(sizeof(NUMBQ));
                *(numb.C+i) = inputQ();
            }
        return numb;
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для вывода  коэффициентов многочлена

 */

void printNumbP(NUMBP numb)
    {
        for(int i = 0; i < numb.m+1; ++i )
            {
                printf("(");
                printNumbQ(*(numb.C + i));
                printf(")");
                if(i != numb.m)
                    {
                        printf("*x^%d",numb.m-i);
                        printf(" + ");
                    }
            }
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

 Функция для освобождения памяти из под многочлена

 */


NUMBQ* freeP(NUMBP* numbp)
    {
        if(numbp->C)
            {
                freeNumb(&numbp->C->a.A);
                freeNumb(&numbp->C->b.A);
                free(numbp->C);
            }
        return NULL;
    }