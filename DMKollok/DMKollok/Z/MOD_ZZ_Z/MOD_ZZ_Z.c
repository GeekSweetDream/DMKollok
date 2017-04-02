
#include <stdlib.h>
#include <stdio.h>
#include "numbZ.h"
#include "../MUL_ZZ_Z/MUL_ZZ_Z.h"
#include "../SUB_ZZ_Z/SUB_ZZ_Z.h"
#include "../DIV_ZZ_Z/DIV_ZZ_Z.h"
#include "MOD_ZZ_Z.h"

/*


modNumbN

Функция выдает остаток от деления

Параметры:
1) a - делимое
2) b - делитель

Функция возращает тип - NUMBN

*/

NUMBZ modNumbZ(NUMBZ divident,NUMBZ divider)
    {
        NUMBZ ans;
        if(divident.A && divider.A)
            {
                NUMBZ k = divNumbZ(divident, divider);
                int sign = (!divident.b && divider.b) || (!divider.b && divident.b);
                divident.b = 0;
                divider.b = 0;
                k.b = 0;
                ans = diffNumbZ(divident,multiplicationNumbZ(divider, k));
                ans.b = sign;
            }
        else
            printf("\nОшибка, число не существует!\n");

        return ans;
    }
