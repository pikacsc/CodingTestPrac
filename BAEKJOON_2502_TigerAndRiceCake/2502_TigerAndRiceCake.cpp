/*
https://www.acmicpc.net/problem/2502

����
�Ϸ翡 �� �� ���� �Ѿ�� �� ��� �ҸӴϴ� ȣ���̿��� ���� �־�� ���� �Ѿ �� �ִµ�, 

��� ���� ȣ���̴� ���� ���� ���� ������ ������ ���� ���� ������ ���� ��ŭ�� ���� �޾ƾ߸� �ҸӴϸ� ������ ���� �شٰ� �Ѵ�.

���� ��� ù° ���� ���� 1�� �־���, ��° ������ ���� 2�� �־��ٸ� ��° ������ 1+2=3��, ��° ������ 2+3=5��, �ټ�° ������ 3+5=8��, ����° ������ 5+8=13���� �־�߸� ������ ���� �Ѿ �� �ִ�.

�츮�� ���� ������ �Ѿ�� �ҸӴϿ��� ���� ȣ���̿��� �� ���� ���� �־�����, �׸��� ������ ȣ���̸� ���� ���� ���� ��ĥ�� �Ǿ������� �˾Ƴ�����.

�ҸӴϰ� ȣ���̸� ������ ������ �Ѿ�� D° ���� �� ���� ������ K������ �� ��, �������� �ҸӴϰ� ȣ���̸� ó�� ���� ����  �� ���� ���� A, �׸��� �� ���� ���� ȣ���̿��� �� ���� ���� B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. �� ���������� �׻� 1��A��B �̴�.

���� ��� ���� ��° ���� ���� ������ �Ѿ�� �ҸӴϰ� ȣ���̿��� �� ���� ��� 41�����, ȣ���̸� ���� ù ���� �� ���� ���� 2��, ��° ���� �� ���� ���� 7���̴�. 

�� ��° ������ 9��, ��° ������ 16��, �ټ�° ������ 25��, ����°  ������ 41���̴�. ���� A=2, B=7 �� �ȴ�. 

�� � ��쿡�� ���� �Ǵ� A, B�� �ϳ� �̻��� ���� �ִµ� �� ��쿡�� �� �� �ϳ��� ���ؼ� ����ϸ� �ȴ�.



�Է�
ù° �ٿ��� �ҸӴϰ� �Ѿ�� �� D (3 �� D �� 30)�� �� �� ȣ���̿��� �� ���� ���� K (10 �� K �� 100,000)�� �ϳ��� ��ĭ�� ���̿� �ΰ� �־�����.

���
ù�ٿ� ù ���� �� ���� ���� A�� ����ϰ� �� ���� ��° �ٿ��� ��° ���� �� ���� ���� B�� ����Ѵ�. �� �������� �־��� D, K�� ���ؼ��� �׻� ���� A, B (1��A��B)�� �����Ѵ�.



���� �Է� 1
6 41


���� ��� 1
2
7

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int A[33];
int B[33];

int D, K;

int main()
{
	scanf("%d %d", &D, &K);

	A[1] = 1;
	B[2] = 1;


	for (int i = 3; i < 31; i++)
	{
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}

	int a = A[D];
	int b = B[D];

	for (int i = 1; i <= 1000000; i++)
	{
		if ((K - a * i) % b == 0)
		{
			printf("%d\n%d", i, (K - a * i) / b);
			return 0;
		}
	}


	return 0;
}