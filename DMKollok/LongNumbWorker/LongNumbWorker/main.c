
#include <stdio.h>
#include <stdlib.h>
#include "DMKollok/N/numbN.h"
#include "DMKollok/Z/numbZ.h"
#include "DMKollok/Q/numbQ.h"
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


int showMenu(void);
int showSubMenu(int ch);

int* inputString(int* len);

NUMBN inputN();
void printNumb(int* numb, int len);
int* freeNumb(int** numb);
void actionN();


NUMBZ inputZ();
void actionZ();
void printNumbZ(NUMBZ numb);

NUMBQ inputQ();
void actionQ();
void printNumbQ(NUMBQ numb);

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
                        
                        break;
                    case 5:
                        
                        break;
                    case 0:
                        exit = 1;
                        break;
                        
                    default:
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
        puts("\nВыберите тип чисел, с которыми будете работать: \n1. Натуральные числа\n2. Целые числа  \n3. Рациональные числа \n4. Многочлены \n5. Справка по программе \n\n0. Выйти из программы\n");
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
                        printNumb(a.A,c.n);
                        printf("\nВаше второе число: ");
                        printNumb(b.A,c.n);
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


NUMBN inputN()
    {
        NUMBN numb;
        numb.A = inputString(&numb.n);
        return numb;
    }

int* inputString(int* len)
    {

        int err = 0;
        char* arr = NULL;
        char ch;
        int* numb = NULL;
        *len = 0;
        printf("\nВведите число: ");
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


void printNumb(int* numb,int len)
    {
        for(int i = 0; i < len; ++i)
            printf("%d",*(numb+i));
        //printf("\n");
    }

int* freeNumb(int** numb)
    {
        if(*numb)
            free(*numb);
        return NULL;
    }


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

NUMBZ inputZ()
    {
        int err = 0,
            s;
        NUMBZ numb;
        do
            {
                printf("\nВведи знак ( 1 - отрицательное, 0 - положительное): ");
                scanf("%d",&s);
                err = s == 0 || s == 1;
                if(!err)
                    printf("\nБыл введен неверный символ!");
            }
        while(!err);
        scanf( "%*[^\n]" );         // Эти две команды нужны для того, чтобы очистить поток ввода
        scanf( "%*c" );
        numb.b = s;
        numb.A = inputString(&numb.n);
        return numb;
    }

void printNumbZ(NUMBZ numb)
    {
        if(numb.b)
            printf("-");
        else
            printf("+");
        printNumb(numb.A,numb.n);
    }


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

NUMBQ inputQ()
    {
        NUMBQ numb;
        printf("Введи числитель: ");
        numb.a = inputZ();
        printf("Введи знаменатель: ");
        numb.b.A = inputString(&numb.b.n);
        return numb;
    }

void printNumbQ(NUMBQ numb)
    {
        printNumbZ(numb.a);
        printf("/");
        printNumb(numb.b.A,numb.b.n);
    }

void actionP()
{
    int exit = 0,
    ch;
    do
    {
        ch = showSubMenu(1);
        switch (ch) {
            case 1:
                //Ввод числа
                break;
                
            case 2:
                //Сложение
                break;
            case 3:
                //diff
                break;
            case 4:
                //MULL
                break;
            case 5:
                //div
                break;
            case 6:
                //mod
                break;
            case 7:
                //NOD
                break;
            case 8:
                //NOK
                break;
            case 9:
                //COMP
                break;
            default:
                printf("\nОшибка, выбран не существующий пункт меню!\n");
                break;
        }
        
    }
    while (!exit);
    
}



