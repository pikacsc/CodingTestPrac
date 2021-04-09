/*
https://www.acmicpc.net/problem/10818


����
N���� ������ �־�����. �̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 1,000,000)�� �־�����. ��° �ٿ��� N���� ������ �������� �����ؼ� �־�����. ��� ������ -1,000,000���� ũ�ų� ����, 1,000,000���� �۰ų� ���� �����̴�.

���
ù° �ٿ� �־��� ���� N���� �ּڰ��� �ִ��� �������� ������ ����Ѵ�.




���� �Է� 1
5
20 10 35 30 7


���� ��� 1
7 35

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int N;

int max = -1000001;
int min = 1000001;

int input;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);

		max = max < input ? input : max;
		min = min > input ? input : min;

	}

	printf("%d %d", min, max);


	return 0;
}