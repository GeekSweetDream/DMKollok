#include <stdlib.h>
#include <stdio.h>
#include "numbZ.h"
#include "numbN.h"
#include "numbQ.h"
#include "GCF_NN_N/GCF_NN_N.h"
#include "GCF_NN_N/GCF_NN_N.h"
#include "DIV_ZZ_Z/DIV_ZZ_Z.h"
#include "ABS_Z_N/ABS_Z_N.h"
#include "TRANS_N_Z/TRANS_N_Z.h"
#include "DIV_ZZ_Z/DIV_NN_N/DIV_NN_N.h"
#include "GCF_NN_N/MOD_NN_N/DIV_NN_N/DIV_NN_Dk/COM_NN_D/COM_NN_D.h"
#include "RED_Q_Q.h"

/*
 
 Написал: Пискунов Виталий
 Группа: 6308
 
 reductNumbQ
 
 Функция для сокращения рациональных чисел
 
 Параметры:
 1) numb - дробь
 
 
 Функция возращает тип - NUMBQ
 
 */

NUMBQ reductNumbQ(NUMBQ numb)
    {
        NUMBQ ans;
        if(numb.a.A && numb.b.A)
            {
                NUMBN nod = nodNumbN(numb.b, absNumbZ(numb.a));
                ans.a.b = numb.a.b;
                ans.a = divNumbZ(numb.a, getNumbZ(nod));
                ans.b = DivNumbN(numb.b, nod);
            }
        else
            printf("\nОшибка, число не существует!\n");
        
        return ans;
    }
