/*
https://www.acmicpc.net/problem/9095

9095 1,2,3 더하기


문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.



입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.



출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.



예제 입력 1
3
4
7
10


예제 출력 1
7
44
274

*/

#include <iostream>
#include <vector>

int t;



int main()
{
	std::cin >> t;
	
	std::vector<int> n(t, 0);
	std::vector<int> dp(11, 0);

	for (int i = 0; i < t; i++)
		std::cin >> n[i];


	/*
	f(1) = 1
	f(2) = 2
	f(3) = 4 
	f(4) = 7 = f(3) + f(2) + f(1) = 4 + 2 + 1
	f(5) = 13  = f(4) + f(3) + f(2) = 7 + 4 + 2
	*/

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2; 
	dp[3] = 4; 
	dp[4] = 7;  

	//dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3];

	for (int i = 5; i < 11; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for(auto&l : n)
		std::cout << dp[l] << std::endl;
	


	return 0;
}