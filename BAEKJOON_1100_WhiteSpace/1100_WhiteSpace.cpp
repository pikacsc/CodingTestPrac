/*
https://www.acmicpc.net/problem/1100

문제
체스판은 8*8크기이고, 검정 칸과 하얀 칸이 번갈아가면서 색칠되어 있다. 

가장 왼쪽 위칸 (0,0)은 하얀색이다. 체스판의 상태가 주어졌을 때, 하얀 칸 위에 말이 몇 개 있는지 출력하는 프로그램을 작성하시오.



입력
첫째 줄부터 8개의 줄에 체스판의 상태가 주어진다. ‘.’은 빈 칸이고, ‘F’는 위에 말이 있는 칸이다.

출력
첫째 줄에 문제의 정답을 출력한다.



예제 입력 1
.F.F...F
F...F.F.
...F.F.F
F.F...F.
.F...F..
F...F.F.
.F.F.F.F
..FF..F.

예제 출력 1
1

*/

#include <iostream>

std::string buffer;

int count;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 1; i <= 8; i++)
	{
		std::cin >> buffer;
		for (int j = 1; j <= 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					if (buffer.c_str()[j - 1] == 'F')
						count++;
				}
			}
			else
			{
				if (j % 2 != 0)
				{
					if (buffer.c_str()[j - 1] == 'F')
						count++;
				}
			}
		}
	}
	
	std::cout << count;

	return 0;
}