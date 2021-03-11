/*
https://www.acmicpc.net/problem/14881﻿

문제
용량이 a, b 리터인 두 물통이 있다. 이때, 물을 적절히 부어서 정확하게 c리터를 만들 수 있는지 아닌지 구하는 프로그램을 작성하시오. 물은 무한히 많다.

입력
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 10,000)가 주어진다.

둘째 줄부터 T개의 줄에는 테스트 케이스가 한 줄에 하나씩 주어진다. 각 테스트 케이스는 3개의 정수 a, b, c로 이루어져 있다. (1 ≤ a, b, c ≤ 109)

출력
각각의 테스트 케이스에 대해서, 정확하게 c리터를 만들 수 있으면 "YES", 없으면 "NO"를 출력한다.


예제 입력 1
2
5 3 4
3 6 4


예제 출력 1
YES
NO


힌트
첫 번째 테스트 케이스의 경우에 다음과 같은 방법으로 4리터를 만들 수 있다.
a를 채운다. (a = 5, b = 0)
a의 물을 b로 붓는다. (a = 2, b = 3)
b에 들어있는 물을 버리고, a에 들어있는 물을 b로 붓는다. (a = 0, b = 2)
a를 채운다. (a = 5, b = 2)
a의 물을 b로 붓는다. (a = 4, b = 3)

*/

#include <iostream>

int T, a, b, c;


int main()
{
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		std::cin >> a >> b >> c;

		if (c > a && c > b)
		{
			std::cout << "NO" << std::endl;
			continue;
		}
		
		//두 물통을 큰것 작은것으로 분류하기
		int max, min;
		max = a < b ? b : a;
		min = max == a ? b : a;


		/*
		1. c를 담을 물통은 a 또는 b 물통 이므로 a와 b보다 c가 크다면 만들 수 없다, "NO"
		
		2. a 와 b사이에 최대공약수가 없다면 a 나 b이하의 모든 리터의 물을 만들 수 있다.
		(단, c 리터를 최대 공약수로 나누어 떨어질때도 "YES")

		*/
		
		//최대공약수 구하기
		int r = 0;
		while (min != 0)
		{
			r = max % min;
			max = min;
			min = r;
		}


		//max == 1 인경우 최대 공약수가 없는것이고
		//max 가 2이상 이라면 최대공약수가 존재하는 것이다. 
		if (max == 1 || c % max == 0)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}

	return 0;
}