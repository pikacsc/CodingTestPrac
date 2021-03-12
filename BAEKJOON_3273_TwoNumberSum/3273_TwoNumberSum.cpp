/*
https://www.acmicpc.net/problem/3273

문제
n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. 

ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다. 

자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.



입력
첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)

출력
문제의 조건을 만족하는 쌍의 개수를 출력한다.



예제 입력 1
9
5 12 7 10 9 1 2 3 11
13

예제 출력 1
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
	1. 오름차순 정렬

	2. 배열 양끝의 수를 각각 L 과 R로 칭함
 
	L과 R의 합이 X와 같다면 L++, R-- 를 수행

	L과 R의 합이 X보다 작다면, 수가 커져야하므로  L++

	L과 R의 합이 X보다 크다면, 수가 작아져야 하므로 R--

	3. L >= R 될때까지 반복
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
