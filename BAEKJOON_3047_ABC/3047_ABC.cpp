/*
https://www.acmicpc.net/problem/3047

����
�� �� A, B, C�� �־�����. A�� B���� �۰�, B�� C���� �۴�.

�� �� A, B, C�� �־����� ��, �Է¿��� �־��� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٿ� �� �� A, B, C�� �־�����. ������, ������ A, B, C�� �ƴ� ���� �ִ�. 
�� ���� 100���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� A, B, C�� �̷���� �� ���ڰ� �־�����, �� ������� ����ϸ� �ȴ�.

���
�־��� �� ���� �־��� ��� ������� ����ϸ� �ȴ�.



���� �Է� 1
1 5 3
ABC

���� ��� 1
1 3 5



���� �Է� 2
6 4 2
CAB

���� ��� 2
6 2 4

*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

char buffer[3];

int main()
{
	std::vector<int> intVect(3, 0);

	scanf("%d %d %d", &intVect[0], &intVect[1], &intVect[2]);
	scanf("%s", buffer);

	std::sort(intVect.begin(), intVect.end());

	for (auto& l : buffer)
	{
		if (l == 'A')
			printf("%d ", intVect[0]);

		if (l == 'B')
			printf("%d ", intVect[1]);

		if (l == 'C')
			printf("%d ", intVect[2]);
	}


	return 0;
}