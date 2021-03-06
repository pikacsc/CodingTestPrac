/*
https://www.acmicpc.net/problem/2225


2225번
합분해

문제
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.

덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.



입력
첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.

출력
첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.



예제 입력 1
20 2

예제 출력 1
21

*/





#include <iostream>

int N, K;

int sum;

long long DP[201][201];

int main()
{
	std::cin >> N;
	std::cin >> K;

	for (int i = 1; i < 201; i++)
		DP[0][i] = 1;

	/*
	dp[1][1] = 1 -> 1개
	dp[1][2] = 01 10 -> 2개
	dp[1][3] = 100 010 001 ->3개
	dp[1][4] = 1000 0100 0010 0001 ->4개
	dp[1][5] = 10000 01000 00100, 00010 00001 -> 5개


	dp[2][1] = 2 -> 1개
	dp[2][2] = 02 11 20 -> 3개
	dp[2][3] = 110 101 001 200 020 002 ->6개
	dp[2][4] = 1100 1010 1001 0110 0101 0011 2000 0200 0020 0002 ->10
	dp[2][5] = 11000 10100 10010 10001 01100 01010 01001 00110 00101 00011 20000 02000 00200 00020 00002 -> 15개

	d[2][k] = d[1][k] + d[2][k-1]

	
	*/

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
			DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 1000000000;



	std::cout << DP[N][K];


	return 0;
}