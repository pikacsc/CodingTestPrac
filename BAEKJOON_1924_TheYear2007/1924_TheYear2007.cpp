/*
https://www.acmicpc.net/problem/1924

����
������ 2007�� 1�� 1�� �������̴�. �׷��ٸ� 2007�� x�� y���� ���� �����ϱ�? �̸� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ĭ�� ���̿� �ΰ� x(1 �� x �� 12)�� y(1 �� y �� 31)�� �־�����. ����� 2007�⿡�� 1, 3, 5, 7, 8, 10, 12���� 31�ϱ���, 4, 6, 9, 11���� 30�ϱ���, 2���� 28�ϱ��� �ִ�.

���
ù° �ٿ� x�� y���� ���� ���������� ���� SUN, MON, TUE, WED, THU, FRI, SAT�� �ϳ��� ����Ѵ�.


���� �Է� 1
1 1

���� ��� 1
MON


���� �Է� 2
3 14

���� ��� 2
WED



���� �Է� 3
9 2

���� ��� 3
SUN



���� �Է� 4
12 25

���� ��� 4
TUE

*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int month;

int day;

int calendar[366];

enum e_Day
{
	MON = 1,
	TUE,
	WED,
	THU,
	FRI,
	SAT,
	SUN
};


int main()
{
	
	scanf("%d %d", &month, &day);

	
	//1   2    3    4    5     6   7
	//mon tue  wed  thur fri  sat  sun
	//1�� 1�Ϻ��� �������� �������� ���ʴ�� 
	//1,2,3,4,5,6,7 �� �ʱ�ȭ
	//������ ���ڰ� ������ ����
	for (int i = 1, count = 1; i <= 365; i++)
	{
		if (count == 8)
			count = 1;

		calendar[i] = count++;
	}



	//�Է��� ���� ���� ����
	//���İ� ������, ������ �ϼ��� ���
	int ans = 0;
	int addCount = 0;
	int endDate = 0;
	for (int i = 1; i < month; i++)
	{

		switch (i)
		{
		case 2:
			endDate = 28;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			endDate = 31;
			break;
		default:
			endDate = 30;
			break;
		}

		addCount += endDate;
	}

	//������ �ϼ� + �Է��� �ϼ�
	ans = calendar[addCount + day];
	

	switch (ans)
	{
	case MON:
		printf("MON");
		break;
	case TUE:
		printf("TUE");
		break;
	case WED:
		printf("WED");
		break;
	case THU:
		printf("THU");
		break;
	case FRI:
		printf("FRI");
		break;
	case SAT:
		printf("SAT");
		break;
	case SUN:
		printf("SUN");
		break;
	default:
		break;
	}
	
	return 0;
}