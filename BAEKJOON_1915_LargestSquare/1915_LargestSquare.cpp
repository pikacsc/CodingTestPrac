/*
https://www.acmicpc.net/problem/1915


����
n��m�� 0, 1�� �� �迭�� �ִ�. �� �迭���� 1�� �� ���� ū ���簢���� ũ�⸦ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

0	1	0	0
0	1	1	1
1	1	1	0
0	0	1	0
���� ���� ���������� ����� 2��2 �迭�� ���� ū ���簢���̴�.



�Է�
ù° �ٿ� n, m(1 �� n, m �� 1,000)�� �־�����. ���� n���� �ٿ��� m���� ���ڷ� �迭�� �־�����.

���
ù° �ٿ� ���� ū ���簢���� ���̸� ����Ѵ�.



���� �Է� 1
4 4
0100
0111
1110
0010

���� ��� 1
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