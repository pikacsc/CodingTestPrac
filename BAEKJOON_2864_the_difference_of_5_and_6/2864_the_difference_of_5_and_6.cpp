/*
https://www.acmicpc.net/problem/2864


����
����̴� 2863������ ǥ�� �ʹ� ������ ���� ������ 5�� 6�� �򰥸��� �����ߴ�.

����̰� ���� 5�� �� ��, 5�� �� ���� ������, 6���� �߸� �� ���� �ְ�, 6�� �� ����, 6���� �� ���� ������, 5�� �߸� �� ���� �ִ�.

�� �� A�� B�� �־����� ��, ����̴� �� �� ���� ���Ϸ��� �Ѵ�. 

�̶�, ����̰� ���� �� �ִ� �� ���� ������ �� ��, �ּڰ��� �ִ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٿ� �� ���� A�� B�� �־�����. (1 <= A,B <= 1,000,000)


���
ù° �ٿ� ����̰� ���� �� �ִ� �� ���� �� �� �ּڰ��� �ִ��� ����Ѵ�.



���� �Է� 1
1430 4862


���� ��� 1
6282 6292

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

int A_Max, B_Max;
int A_Min, B_Min;

int A_origin, B_origin;

char aBuffer[8];
char bBuffer[8];


int main()
{
	scanf("%s %s", aBuffer, bBuffer);

	int aLen = (int)strlen(aBuffer);
	int bLen = (int)strlen(bBuffer);

	//a : 5 -> 6
	//a : 6 -> 5

	//b : 5 -> 6
	//b : 6 -> 5


	A_origin = atoi(aBuffer);
	B_origin = atoi(bBuffer);

	for (int i = 0; i <= aLen; i++)
	{
		if (aBuffer[i] - '0' == 5)
		{
			aBuffer[i] = '6';
		}
	}

	A_Max = atoi(aBuffer);

	for (int i = 0; i <= bLen; i++)
	{
		if (bBuffer[i] - '0' == 5)
		{
			bBuffer[i] = '6';
		}
	}

	B_Max = atoi(bBuffer);

	sprintf(aBuffer, "%d", A_origin);
	sprintf(bBuffer, "%d", B_origin);

	for (int i = 0; i <= aLen; i++)
	{
		if (aBuffer[i] - '0' == 6)
		{
			aBuffer[i] = '5';
		}
	}

	A_Min = atoi(aBuffer);

	for (int i = 0; i <= bLen; i++)
	{
		if (bBuffer[i] - '0' == 6)
		{
			bBuffer[i] = '5';
		}
	}

	B_Min = atoi(bBuffer);

	printf("%d %d", A_Min + B_Min, A_Max + B_Max);


	return 0;
}

