/*
https://www.acmicpc.net/problem/11004


����
�� N�� A1, A2, ..., AN�� �־�����. A�� �������� �������� ��, �տ������� K��° �ִ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٿ� N(1 �� N �� 5,000,000)�� K (1 �� K �� N)�� �־�����.

��°���� A1, A2, ..., AN�� �־�����. (-109 �� Ai �� 109)



���
A�� �������� ��, �տ������� K��° �ִ� ���� ����Ѵ�.





���� �Է� 1
5 2
4 1 2 3 5


���� ��� 1
2


*/

#include <iostream>
#include <algorithm>
#include <vector>

int N;
int K;
int input;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N >> K;
	std::vector<int> vect;

	for (int i = 0; i < N; i++)
	{
		std::cin >> input;
		vect.push_back(input);
	}

	std::sort(vect.begin(), vect.end());

	std::cout << vect[K - 1];
	return 0;
}