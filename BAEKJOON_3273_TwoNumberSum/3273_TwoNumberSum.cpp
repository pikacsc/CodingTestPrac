/*
https://www.acmicpc.net/problem/3273

����
n���� ���� �ٸ� ���� ���� a1, a2, ..., an���� �̷���� ������ �ִ�. 

ai�� ���� 1���� ũ�ų� ����, 1000000���� �۰ų� ���� �ڿ����̴�. 

�ڿ��� x�� �־����� ��, ai + aj = x (1 �� i < j �� n)�� �����ϴ� (ai, aj)���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٿ� ������ ũ�� n�� �־�����. ���� �ٿ��� ������ ���ԵǴ� ���� �־�����. ��° �ٿ��� x�� �־�����. (1 �� n �� 100000, 1 �� x �� 2000000)

���
������ ������ �����ϴ� ���� ������ ����Ѵ�.



���� �Է� 1
9
5 12 7 10 9 1 2 3 11
13

���� ��� 1
3

*/
#include <iostream>
#include <algorithm>
#include <vector>



int n, x;
int l, r;
int count;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;
	std::vector<int> arr(n, 0);

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	std::cin >> x;

	std::sort(arr.begin(), arr.end());


	/*
	1. �������� ����

	2. �迭 �糡�� ���� ���� L �� R�� Ī��
 
	L�� R�� ���� X�� ���ٸ� L++, R-- �� ����

	L�� R�� ���� X���� �۴ٸ�, ���� Ŀ�����ϹǷ�  L++

	L�� R�� ���� X���� ũ�ٸ�, ���� �۾����� �ϹǷ� R--

	3. L >= R �ɶ����� �ݺ�
	*/

	l = 0;
	r = n - 1;
	while (l < r)
	{
		int sum = arr[l] + arr[r];
		if (sum == x)
		{
			count++;
			l++;
			r--;
		}
		else if (sum < x)
			l++;
		else
			r--;
	}
	std::cout << count;

	return 0;
}
