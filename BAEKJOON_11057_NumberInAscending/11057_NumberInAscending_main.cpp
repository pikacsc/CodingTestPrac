/*
https://www.acmicpc.net/problem/11057


문제
오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.

예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.

수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.



입력
첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.

출력
첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.



예제 입력 1
1

예제 출력 1
10


예제 입력 2
2

예제 출력 2
55


예제 입력 3
3

예제 출력 3
220

*/

//오르막수는 길이가 몇 이든간에 가장 마지막 숫자로 오르막수 판별을 한다

//길이가 N인 오르막 수에서, 가장 마지막 숫자가 L일때, 만들어 질 수 있는 오르막 수는 C개 이다
//F[N][L] = C 

//길이(N)가 1일때를 살펴보면,
//0 ~ 9 까지 모두 오르막 수가 된다, L을 만족하기 때문이다
//F[1][0 ~ 9] = 1 이다


//길이(N)가 2일때부터 L이 중요해진다, L이 0이고 x가 이전수일떄
//x0 이 된다 이때 x에 올수 있는 수는 0 밖에 존재하지 않는다
//10,20,30 ,,, L보다 큰 수는 오르막수 가 될수없기 떄문이다
//이또한 역시 1이다 즉 F[2][0] = 1 이된다.


//길이(N)가 2이면서 L이 1 이라면
//x1 이 될것이고
//x 에 올수 있는 수는 0, 1 이될 것이다


//이를 수식으로 표현 하면
//F[2][L] = F[1][0] + F[1][1] + ... + F[1][L]  가 된다.

//정리하면
//F[1][0 ~9] = 1
//
//F[2][0] = F[1][0]
//F[2][1] = F[1][0] + F[1][1]
//F[2][2] = F[1][0] + F[1][1] + F[1][2] 
//F[2][3] = F[1][0] + F[1][1] + F[1][2] + F[1][3]
//F[2][4] = F[1][0] + F[1][1] + F[1][2] + F[1][3] + F[1][4]
// 위와같다


//다시 정리하면 
//F[2][0] = F[1][0]
//F[2][1] = F[2][0] + F[1][1]
//F[2][2] = F[2][1] + F[1][2] 
//F[2][3] = F[2][2] + F[1][3]
//F[2][4] = F[2][3] + F[1][4]
//위와 같다, 즉 L 이 0인경우는 모두 1이고
//나머지는 아래와 같은 점화식의 구조와 같다
//F[N][L] = F[N][L-1] + F[N-1][L] 

#include <iostream>

int N;
int L;
int F[1001][10];

int ans;

int main()
{
	for (int i = 0; i <= 9; i++)
	{
		F[1][i] = 1; 
	}


	std::cin >> N;

	for (int i = 2; i <= N; i++)
	{
		F[i][0] = 1; //즉 L 이 0인경우는 모두 1이다
		for (L = 1; L <= 9; L++)
			F[i][L] = (F[i][L - 1] + F[i - 1][L]) % 10007;
		//F[N][L] = F[N][L-1] + F[N-1][L] 
	}

	
	for (int i = 0; i <= 9; i++)
		ans += F[N][i];

	std::cout << ans % 10007;


	return 0;
}