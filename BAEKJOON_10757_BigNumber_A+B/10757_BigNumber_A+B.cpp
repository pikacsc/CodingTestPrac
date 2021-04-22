/*
https://www.acmicpc.net/problem/10757

문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 1010000)

출력
첫째 줄에 A+B를 출력한다.

예제 입력 1
9223372036854775807 9223372036854775808

예제 출력 1
18446744073709551615

*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

char buffer1[10001];
char buffer2[10001];

int a[10004];
int b[10004];
int sum[10004];
int carry;

int main()
{
	scanf("%s %s", buffer1, buffer2);

	for (int i = 0; i < (int)strlen(buffer1); ++i)
		a[strlen(buffer1) - i] = buffer1[i] - '0';
	
	for (int i = 0; i < (int)strlen(buffer2); ++i)
		b[strlen(buffer2) - i] = buffer2[i] - '0';
	
	int maxlen = std::max(strlen(buffer1), strlen(buffer2));
	for (int i = 1; i <= maxlen; ++i)
	{
		sum[i] = a[i] + b[i] + carry;
		if (sum[i] >= 10)
		{
			sum[i] -= 10;
			carry = 1;
		}
		else
			carry = 0;
	}

	if (carry != NULL)
		printf("1");

	for (int i = 0; i < maxlen; ++i)
		printf("%d", sum[maxlen - i]);


	return 0;
}
