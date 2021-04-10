/*
https://www.acmicpc.net/problem/3047

문제
세 수 A, B, C가 주어진다. A는 B보다 작고, B는 C보다 작다.

세 수 A, B, C가 주어졌을 때, 입력에서 주어진 순서대로 출력하는 프로그램을 작성하시오.



입력
첫째 줄에 세 수 A, B, C가 주어진다. 하지만, 순서는 A, B, C가 아닐 수도 있다. 
세 수는 100보다 작거나 같은 자연수이다. 둘째 줄에는 A, B, C로 이루어진 세 글자가 주어지며, 이 순서대로 출력하면 된다.

출력
주어진 세 수를 주어진 출력 순서대로 출력하면 된다.



예제 입력 1
1 5 3
ABC

예제 출력 1
1 3 5



예제 입력 2
6 4 2
CAB

예제 출력 2
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