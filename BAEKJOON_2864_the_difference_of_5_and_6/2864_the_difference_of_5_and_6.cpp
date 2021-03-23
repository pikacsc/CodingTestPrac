/*
https://www.acmicpc.net/problem/2864


문제
상근이는 2863번에서 표를 너무 열심히 돌린 나머지 5와 6을 헷갈리기 시작했다.

상근이가 숫자 5를 볼 때, 5로 볼 때도 있지만, 6으로 잘못 볼 수도 있고, 6을 볼 때는, 6으로 볼 때도 있지만, 5로 잘못 볼 수도 있다.

두 수 A와 B가 주어졌을 때, 상근이는 이 두 수를 더하려고 한다. 

이때, 상근이가 구할 수 있는 두 수의 가능한 합 중, 최솟값과 최댓값을 구해 출력하는 프로그램을 작성하시오.



입력
첫째 줄에 두 정수 A와 B가 주어진다. (1 <= A,B <= 1,000,000)


출력
첫째 줄에 상근이가 구할 수 있는 두 수의 합 중 최솟값과 최댓값을 출력한다.



예제 입력 1
1430 4862


예제 출력 1
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

