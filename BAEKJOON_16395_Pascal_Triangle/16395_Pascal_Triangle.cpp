/*
https://www.acmicpc.net/problem/16395

파스칼의 삼각형

문제
파스칼의 삼각형은 이항계수를 삼각형 형태로 배열한 것인데, 블레즈 파스칼(1623-1662)을 따라 이름 붙여졌다.

단순한 형태로, 파스칼의 삼각형은 다음과 같은 방법으로 만들 수 있다.

N번째 행에는 N개의 수가 있다.
첫 번째 행은 1이다.
두 번째 행부터, 각 행의 양 끝의 값은 1이고, 나머지 수의 값은 바로 위 행의 인접한 두 수의 합이다.
예를 들어, n=3이면 3번째 행의 2번째 수는 위 행의 인접한 두 수 (1과 1)을 더해서 만든다.

n=6일 때, 파스칼 삼각형의 6번째 행의 10은 5번째 행의 인접한 두 수(4와 6)을 더해서 구한다.



같은 방식으로 n=11일 때, 다음과 같은 파스칼의 삼각형을 만들 수 있다.



정수 n과 k가 주어졌을 때 파스칼의 삼각형에 있는 n번째 행에서 k번째 수를 출력하는 프로그램을 작성하시오.  이때, 이 수는 이항계수 C(n-1,k-1)임에 주의하시오.



입력
첫째 줄에 정수 n과 k가 빈칸을 사이에 두고 차례로 주어진다. 이 때, 1 ≤ k ≤ n ≤ 30을 만족한다.


출력
첫째 줄에 n번째 행에 있는 k번째 수를 출력한다.



예제 입력 1
5 3

예제 출력 1
6



예제 입력 2
11 3

예제 출력 2
45

*/

#include <iostream>

int n; //행
int k; //열
int dp[31][31];

int main()
{
	std::cin >> n;
	std::cin >> k;

	dp[1][1] = 1;
	
	dp[2][1] = 1;
	dp[2][2] = 1;

	//dp[3][1] = 1;
	//dp[3][2] = 2; // dp[2][1] + dp[2][2]
	//dp[3][3] = 1; 

	//dp[4][1] = 1;
	//dp[4][2] = 3; // dp[3][1] + dp[3][2]
	//dp[4][3] = 3; // dp[3][2] + dp[3][3]
	//dp[4][4] = 1;

	//dp[5][1] = 1; 
	//dp[5][2] = 4; // dp[4][1] + dp[4][2];
	//dp[5][3] = 6; // dp[4][2] + dp[4][3]
	//dp[5][4] = 4; // dp[4][3] + dp[4][4]
	//dp[5][5] = 1;

	
	for (int i = 3; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	std::cout << dp[n][k];


	return 0;
}