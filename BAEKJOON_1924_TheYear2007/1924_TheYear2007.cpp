/*
https://www.acmicpc.net/problem/1924

문제
오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 빈 칸을 사이에 두고 x(1 ≤ x ≤ 12)와 y(1 ≤ y ≤ 31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

출력
첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.


예제 입력 1
1 1

예제 출력 1
MON


예제 입력 2
3 14

예제 출력 2
WED



예제 입력 3
9 2

예제 출력 3
SUN



예제 입력 4
12 25

예제 출력 4
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
	//1월 1일부터 월요일을 기준으로 차례대로 
	//1,2,3,4,5,6,7 을 초기화
	//각각의 숫자가 요일을 뜻함
	for (int i = 1, count = 1; i <= 365; i++)
	{
		if (count == 8)
			count = 1;

		calendar[i] = count++;
	}



	//입력한 월의 전달 까지
	//거쳐간 월마다, 누적된 일수를 계산
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

	//누적된 일수 + 입력한 일수
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