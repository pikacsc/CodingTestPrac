/*
https://www.acmicpc.net/problem/16199


문제
한국에서 나이는 총 3가지 종류가 있다.

만 나이: 국제적인 표준 방법이다. 한국에서도 법에서는 만 나이만을 사용한다.
세는 나이: 한국에서 보통 나이를 물어보면 세는 나이를 의미한다.
연 나이: 법률에서 일괄적으로 사람을 구분하기 위해서 사용하는 나이이다.


만 나이는 생일을 기준으로 계산한다. 어떤 사람이 태어났을 때, 그 사람의 나이는 0세이고, 생일이 지날 때마다 1세가 증가한다. 
예를 들어, 생일이 2003년 3월 5일인 사람은 2004년 3월 4일까지 0세이고, 2004년 3월 5일부터 2005년 3월 4일까지 1세이다.

세는 나이는 생년을 기준으로 계산한다. 어떤 사람이 태어났을 때, 그 사람의 나이는 1세이고, 연도가 바뀔 때마다 1세가 증가한다. 
예를 들어, 생일이 2003년 3월 5일인 사람은 2003년 12월 31일까지 1세이고, 2004년 1월 1일부터 2004년 12월 31일까지 2세이다.

연 나이는 생년을 기준으로 계산하고, 현재 연도에서 생년을 뺀 값이다. 예를 들어, 생일이 2003년 3월 5일인 사람은 2003년 12월 31일까지 0세이고, 2004년 1월 1일부터 2004년 12월 31일까지 1세이다.



어떤 사람의 생년월일과 기준 날짜가 주어졌을 때, 기준 날짜를 기준으로 그 사람의 만 나이, 세는 나이, 연 나이를 모두 구하는 프로그램을 작성하시오.

입력
첫째 줄에 어떤 사람이 태어난 연도, 월, 일이 주어진다. 생년월일은 공백으로 구분되어져 있고, 항상 올바른 날짜만 주어진다.

둘째 줄에 기준 날짜가 주어진다. 기준 날짜도 공백으로 구분되어져 있으며, 올바른 날짜만 주어진다.

입력으로 주어지는 생년월일은 기준 날짜와 같거나 그 이전이다.

입력으로 주어지는 연도는 1900년보다 크거나 같고, 2100년보다 작거나 같다.



출력
첫째 줄에 만 나이, 둘째 줄에 세는 나이, 셋째 줄에 연 나이를 출력한다.



예제 입력 1
2003 3 5
2003 4 5

예제 출력 1
0
1
0


예제 입력 2
2003 3 5
2004 1 1

예제 출력 2
0
2
1


예제 입력 3
2005 1 1
2007 1 1

예제 출력 3
2
3
2


예제 입력 4
2005 12 31
2007 1 1

예제 출력 4
1
3
2


예제 입력 5
2006 1 1
2007 1 1

예제 출력 5
1
2
1


예제 입력 6
2005 1 2
2007 1 1

예제 출력 6
1
3
2

*/



//만나이 = 생일전 까지는 연나이 - 1, 생일 당일 또는 후에는 다음생일 까지 연나이 
//세는나이 = 현재연도 - 생년 + 1
//연나이 = 현재연도 - 생년

//
//#include <iostream>
//
//int birth_year;
//int birth_month;
//int birth_day;
//
//int this_year;
//int this_month;
//int this_day;
//
//int age1; //만나이
//int age2; //세는나이
//int age3; //연나이
//
//int main()
//{
//	std::cin >> birth_year >> birth_month >> birth_day;
//	std::cin >> this_year >> this_month >> this_day;
//	
//	//만나이 계산
//	if (this_month >= birth_month)
//	{
//		if (this_day >= birth_day)
//		{
//			age1 = this_year - birth_year;
//		}
//		else
//		{
//			age1 = this_year - birth_year - 1;
//		}
//	}
//	else
//	{
//		age1 = this_year - birth_year - 1;
//	}
//	
//	//세는나이 계산
//	age2 = this_year - birth_year + 1;
//
//	//연나이 계산
//	age3 = this_year - birth_year;
//
//	std::cout << age1 << std::endl;
//	std::cout << age2 << std::endl;
//	std::cout << age3 << std::endl;
//
//	return 0;
//}



#include <iostream>

int birth_year;
int birth_month;
int birth_day;

int this_year;
int this_month;
int this_day;

int age1; //만나이
int age2; //세는나이
int age3; //연나이

int main()
{
	std::cin >> birth_year >> birth_month >> birth_day;
	std::cin >> this_year >> this_month >> this_day;
	
	age2 = this_year - birth_year + 1;
	age3 = this_year - birth_year;

	if (birth_year == this_year)
		age1 = 0;
	else
	{
		if (birth_month < this_month)
		{
			age1 = this_year - birth_year;
		}
		else if(birth_month == this_month)
		{
			if (birth_day > this_day)
				age1 = this_year - birth_year - 1;
			else
				age1 = this_year - birth_year;
		}
		else
		{
			age1 = this_year - birth_year - 1;
		}
			
	}

	std::cout << age1 << std::endl;
	std::cout << age2 << std::endl;
	std::cout << age3 << std::endl;


	return 0;
}