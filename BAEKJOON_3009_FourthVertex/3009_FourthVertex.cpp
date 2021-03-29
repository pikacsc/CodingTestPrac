/*

https://www.acmicpc.net/problem/3009


����
�� ���� �־����� ��, �࿡ ������ ���簢���� ����� ���ؼ� �ʿ��� �� ��° ���� ã�� ���α׷��� �ۼ��Ͻÿ�.




�Է�
�� ���� ��ǥ�� �� �ٿ� �ϳ��� �־�����. ��ǥ�� 1���� ũ�ų� ����, 1000���� �۰ų� ���� �����̴�.

���
���簢���� �� ��° ���� ��ǥ�� ����Ѵ�.



���� �Է� 1
30 20
10 10
10 20

���� ��� 1
30 10


*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


int Xarr[1001];
int Yarr[1001];

int inputX;
int inputY;

int ansX;
int ansY;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &inputX, &inputY);

		
		if (Xarr[inputX] == 0)
			Xarr[inputX]++;
		else
			Xarr[inputX]--;

		if (Yarr[inputY] == 0)
			Yarr[inputY]++;
		else
			Yarr[inputY]--;

	}

	for (int i = 1; i <= 1000; i++)
	{
		if (Xarr[i] != 0)
			ansX = i;

		if (Yarr[i] != 0)
			ansY = i;
	}

	printf("%d %d", ansX, ansY);


	return 0;
}

