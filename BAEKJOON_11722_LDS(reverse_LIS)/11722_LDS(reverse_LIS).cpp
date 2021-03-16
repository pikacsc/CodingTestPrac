/*
https://www.acmicpc.net/problem/11722


문제
수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.




입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.



예제 입력 1
6
10 30 10 20 20 10

예제 출력 1
3

*/


#include <iostream>
#include <algorithm>
#include <vector>

int N;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<int> vect(1001, 0);
	std::vector<int> lds(1001, 0);


	std::cin >> N;

	for (int i = 0; i < N; i++)
		std::cin >> vect[i];

	lds[0] = vect[0];

	int i = 1;
	int j = 0;
	while (i < N)
	{
		if (lds[j] > vect[i])
		{
			lds[j + 1] = vect[i];
			j++;
		}
		else
		{
			int ans = std::lower_bound(lds.begin(), lds.begin() + j, vect[i], std::greater<int>()) - lds.begin() + 1;
			lds[ans - 1] = vect[i];
		}
		i++;
	}
	std::cout << j + 1;

	return 0;
}