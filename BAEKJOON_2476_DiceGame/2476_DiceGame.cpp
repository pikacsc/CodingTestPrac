/*
https://www.acmicpc.net/problem/2476


문제
1에서부터 6까지의 눈을 가진 3개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이 있다.

같은 눈이 3개가 나오면 10,000원+(같은 눈)*1,000원의 상금을 받게 된다.
같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)*100원의 상금을 받게 된다.
모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)*100원의 상금을 받게 된다.
예를 들어, 3개의 눈 3, 3, 6이 주어지면 상금은 1,000+3*100으로 계산되어 1,300원을 받게 된다. 

또 3개의 눈이 2, 2, 2로 주어지면 10,000+2*1,000 으로 계산되어 12,000원을 받게 된다. 3개의 눈이 6, 2, 5로 주어지면 그 중 가장 큰 값이 6이므로 6*100으로 계산되어 600원을 상금으로 받게 된다.

N(2 ≤ N ≤ 1,000)명이 주사위 게임에 참여하였을 때, 가장 많은 상금을 받은 사람의 상금을 출력하는 프로그램을 작성하시오.


입력
첫째 줄에는 참여하는 사람 수 N이 주어지고 그 다음 줄부터 N개의 줄에 사람들이 주사위를 던진 3개의 눈이 빈칸을 사이에 두고 각각 주어진다.

출력
첫째 줄에 가장 많은 상금을 받은 사람의 상금을 출력한다.


예제 입력 1
3
3 3 6
2 2 2
6 2 5

예제 출력 1
12000


*/


#include <iostream>
#include <queue>

int dice[7];
int sum;
int d1, d2, d3;
int N;
bool flag;

int main()
{
	std::ios_base::sync_with_stdio(false);

	std::cin >> N;
	std::priority_queue<int, std::vector<int>, std::less<>> pq;

	for (int i = 0; i < N; i++)
	{
		sum = 0;
		flag = false;

		std::cin >> d1 >> d2 >> d3;
		dice[d1]++;
		dice[d2]++;
		dice[d3]++;

		flag = (d1 != d2) && (d2 != d3) && (d3 != d1);

		for (int i = 6; i >= 1; i--)
		{
			if (dice[i] == 3)
			{
				sum += (10000 + i * 1000);
				break;
			}

			if (dice[i] == 2)
			{
				sum += (1000 + i * 100);
				break;
			}

			if (flag && dice[i] == 1)
			{
				sum += (i * 100);
				break;
			}
		}
		dice[d1] = 0;
		dice[d2] = 0;
		dice[d3] = 0;
		pq.push(sum);
	}
	std::cout << pq.top();

	return 0;
}