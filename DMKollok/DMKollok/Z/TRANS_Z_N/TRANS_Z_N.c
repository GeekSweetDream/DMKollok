/*

getNatural

������� ����������� ����� ��������������� ����� � �����������.

���������:
numb - ����� �����

������� ���������� ����������� �����

*/

#include <stdio.h>
#include "numbZ.h"
#include "numbN.h"
#include "TRANS_Z_N.h"

NUMBN getNatural(NUMBZ numb)
{
	NUMBN outNumb;
	if (numb.A)
		if (numb.b == 1)
		{
			outNumb.n = numb.n;
			outNumb.A = (int*)malloc(outNumb.n * sizeof(int));
			for (int i = 0; i < n; i++)
				outNumb.A[i] = numb.A[i];
		}
		else
		{
			printf("������� ������������� �����, �������� �� ����� ���� ���������");
			outNumb = NULL;
		}
	else
	{
		printf("\n������, ����� �� ����������!\n");
		outNumb = NULL;
	}
	return outNumb;
}




