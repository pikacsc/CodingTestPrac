/*
https://www.acmicpc.net/problem/2225


2225��
�պ���

����
0���� N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

������ ������ �ٲ� ���� �ٸ� ���� ����(1+2�� 2+1�� ���� �ٸ� ���). ���� �� ���� ���� ���� �� �� ���� �ִ�.



�Է�
ù° �ٿ� �� ���� N(1 �� N �� 200), K(1 �� K �� 200)�� �־�����.

���
ù° �ٿ� ���� 1,000,000,000���� ���� �������� ����Ѵ�.



���� �Է� 1
20 2

���� ��� 1
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
	dp[1][1] = 1 -> 1��
	dp[1][2] = 01 10 -> 2��
	dp[1][3] = 100 010 001 ->3��
	dp[1][4] = 1000 0100 0010 0001 ->4��
	dp[1][5] = 10000 01000 00100, 00010 00001 -> 5��


	dp[2][1] = 2 -> 1��
	dp[2][2] = 02 11 20 -> 3��
	dp[2][3] = 110 101 001 200 020 002 ->6��
	dp[2][4] = 1100 1010 1001 0110 0101 0011 2000 0200 0020 0002 ->10
	dp[2][5] = 11000 10100 10010 10001 01100 01010 01001 00110 00101 00011 20000 02000 00200 00020 00002 -> 15��

	d[2][k] = d[1][k] + d[2][k-1]

	
	*/

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= K; j++)
			DP[i][j] = (DP[i - 1][j] + DP[i][j - 1]) % 1000000000;



	std::cout << DP[N][K];


	return 0;
}