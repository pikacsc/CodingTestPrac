/*
https://www.acmicpc.net/problem/11403

����
����ġ ���� ���� �׷��� G�� �־����� ��, ��� ���� (i, j)�� ���ؼ�, i���� j�� ���� ��ΰ� �ִ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٺ��� N�� �ٿ��� �׷����� ���� ����� �־�����.
i��° ���� j��° ���ڰ� 1�� ��쿡�� i���� j�� ���� ������ �����Ѵٴ� ���̰�, 0�� ���� ���ٴ� ���̴�. i��° ���� i��° ���ڴ� �׻� 0�̴�.

���
�� N���� �ٿ� ���ļ� ������ ������ ������� �������� ����Ѵ�. ���� i���� j�� ���� ��ΰ� ������ i��° ���� j��° ���ڸ� 1��, ������ 0���� ����ؾ� �Ѵ�.



���� �Է� 1
3
0 1 0
0 0 1
1 0 0

���� ��� 1
1 1 1
1 1 1
1 1 1




���� �Է� 2
7
0 0 0 1 0 0 0
0 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 1 1 0
1 0 0 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0

���� ��� 2
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 0 0 0 0 0
1 0 1 1 1 1 1
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 1 0 0 0 0

*/



#include <iostream>
#include <algorithm>
#include <string.h>

int arr[100][100];
bool visited[100];
int n;

void DFS(int v)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[v][i] == 1 && visited[i] == false)
		{
			visited[i] = true;
			DFS(i);
		}
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	std::cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> arr[i][j];

	for (int i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		DFS(i);

		for (int j = 0; j < n; j++)
		{
			if (visited[j])
				arr[i][j] = 1;
		}

	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}