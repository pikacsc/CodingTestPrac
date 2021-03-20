/*
https://www.acmicpc.net/problem/1507


문제
강호는 N개의 도시로 이루어진 나라에 살고 있다. 각 도시는 M개의 도로로 연결되어 있으며, 각 도로를 지날 때 필요한 시간이 존재한다. 도로는 잘 연결되어 있기 때문에, 도시 A에서 B로 이동할 수 없는 경우는 존재하지 않는다.

도시 A에서 도시 B로 바로 갈 수 있는 도로가 있거나, 다른 도시를 거쳐서 갈 수 있을 때, 도시 A에서 B를 갈 수 있다고 한다.

강호는 모든 쌍의 도시에 대해서 최소 이동 시간을 구해놓았다. 민호는 이 표를 보고 원래 도로가 몇 개 있는지를 구해보려고 한다.

예를 들어, 예제의 경우에 모든 도시 사이에 강호가 구한 값을 가지는 도로가 존재한다고 해도 된다. 하지만, 이 도로의 개수는 최솟값이 아니다. 예를 들어, 도시 1-2, 2-3, 1-4, 3-4, 4-5, 3-5를 연결하는 도로만 있다고 가정해도, 강호가 구한 모든 쌍의 최솟값을 구할 수 있다. 이 경우 도로의 개수는 6개이고, 모든 도로의 시간의 합은 55이다.

모든 쌍의 도시 사이의 최소 이동 시간이 주어졌을 때, 이 나라에 존재할 수 있는 도로의 개수의 최솟값과 그 때, 모든 도로의 시간의 합을 구하는 프로그램을 작성하시오.



입력
첫째 줄에 도시의 개수 N(1 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에 각각의 도시 사이에 이동하는데 필요한 시간 (≤ 10,000)이 주어진다. A에서 B로 가는 시간과 B에서 A로 가는 시간은 같다. 또, A와 B가 같은 경우에는 필요한 시간은 0이다.

출력
첫째 줄에 도로 개수가 최소일 때, 모든 도로의 시간의 합을 출력한다. 불가능한 경우에는 -1을 출력한다.



예제 입력 1
5
0 6 15 2 6
6 0 9 8 12
15 9 0 16 18
2 8 16 0 4
6 12 18 4 0


예제 출력 1
55

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int N;

int adj[21][21];
int arr[21][21];


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &adj[i][j]);
			arr[i][j] = adj[i][j];
		}
	}

	int oldCost = 0;
	int newCost = 0;

	for (int stopover = 0; stopover < N; stopover++) //stopover : 경유지, 거쳐가는 노드
	{
		for (int start = 0; start < N; start++)
		{
			for (int goal = 0; goal < N; goal++)
			{
				//출발점 또는 도착점이 경유지와 동일 할경우 무시
				if (start == stopover || goal == stopover)
					continue;


				//불가능한 경우
				if (adj[start][goal] > adj[start][stopover] + adj[goal][stopover])
				{
					printf("-1\n");
					return 0;
				}

				//출발점에서 도착점으로 가능 경로가 경유지를 거쳐가능 경우와 같은경우
				//출발점에서 도착점으로 가능 경로는 필요없게됨, 0으로 초기화
				if (adj[start][goal] == adj[start][stopover] + adj[stopover][goal])
					arr[start][goal] = 0;

			}
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans += arr[i][j];
		}
	}

	//출발점 -> 도착점, 도착점 -> 출발점, 둘다 계산한 상태이므로
	//반으로 나눠줌
	printf("%d\n", ans / 2);

	return 0;
}