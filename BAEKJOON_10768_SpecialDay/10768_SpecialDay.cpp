/*
https://www.acmicpc.net/problem/10768


����
2�� 18���� ���� CCC�� �־ Ư���� ���̴�.

����ڷκ��� ������ ���� ���� �Է¹޾� ��¥�� 2�� 18������ ������ �������� ����ϴ� ���α׷��̴�.

���� ��¥�� 2�� 18�� ���̸�, "Before"�� ����Ѵ�. ���� ��¥�� 2�� 18�� �ĸ�, "After"�� ����Ѵ�. ���� 2�� 18���̶�� "Special" �� ����Ѵ�.

�Է�
�Է��� �� ���� ������ �� �ٿ� ���� �Էµȴ�. �� �������� 2015���� ��¥�� ���Եȴ�.

ù ��° ���� 1���� 12������ ���� �Է��Ѵ�.

�� ��° ���� 1���� 31������ �� �޿� ����ִ� ��¥�� �Է��Ѵ� .

���
������ �ٿ� "Before", "After"�� "Special"�� ����Ѵ�.


���� �Է� 1
1
7

���� ��� 1
Before


���� �Է� 2
8
31

���� ��� 2
After



���� �Է� 3
2
18

���� ��� 3
Special

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int month, day;

int special_month = 2;
int special_day = 18;

int main()
{
	scanf("%d %d", &month, &day);

	if (month == special_month)
	{
		if (day == special_day)
			printf("Special");
		else if (day > special_day)
			printf("After");
		else
			printf("Before");
	}
	else if (month > special_month)
	{
		printf("After");
	}
	else
	{
		printf("Before");
	}


	return 0;
}