/*
https://www.acmicpc.net/problem/1915


문제
n×m의 0, 1로 된 배열이 있다. 이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.

0	1	0	0
0	1	1	1
1	1	1	0
0	0	1	0
위와 같은 예제에서는 가운데의 2×2 배열이 가장 큰 정사각형이다.



입력
첫째 줄에 n, m(1 ≤ n, m ≤ 1,000)이 주어진다. 다음 n개의 줄에는 m개의 숫자로 배열이 주어진다.

출력
첫째 줄에 가장 큰 정사각형의 넓이를 출력한다.



예제 입력 1
4 4
0100
0111
1110
0010

예제 출력 1
4

*/


#include <iostream>

int arr[1001][1001];

int n, m, max;

std::string buffer;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m;
	std::cin.ignore();

	for (int i = 1; i <= n; i++)
	{
		std::cin >> buffer;
		for (int j = 0; j < (int)buffer.length(); j++)
		{
			arr[i][j + 1] = buffer[j] - '0';
		}
		buffer.clear();
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] != 0)
			{
				arr[i][j] = std::min(arr[i - 1][j - 1], std::min(arr[i - 1][j], arr[i][j - 1])) + 1;
				if (max < arr[i][j])
					max = arr[i][j];
			}
		}
	}
	std::cout << max * max;

	return 0;
}