/*
https://www.acmicpc.net/problem/11053

����
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.



�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.

��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.



���� �Է� 1
6
10 20 10 30 20 50

���� ��� 1
4

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
	std::vector<int> lis(1001, 0);


	std::cin >> N;

	for (int i = 0; i < N; i++)
		std::cin >> vect[i];

	lis[0] = vect[0];

	int i = 1;
	int j = 0;
	while (i < N)
	{
		if (lis[j] < vect[i])
		{
			lis[j + 1] = vect[i];
			j++;
		}
		else
		{
			int ans = std::lower_bound(lis.begin(), lis.begin() + j , vect[i]) - lis.begin() + 1;
			lis[ans - 1] = vect[i];
		}
		i++;
	}
	std::cout << j + 1;

	return 0;
}