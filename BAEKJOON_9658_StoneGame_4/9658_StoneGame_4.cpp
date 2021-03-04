/*
https://www.acmicpc.net/problem/9658

����
�� ������ �� ���̼� ���� ��մ� �����̴�.

Ź�� ���� �� N���� �ִ�. ����̿� â���̴� ���� �����ư��鼭 ���� ��������, ���� 1��, 3�� �Ǵ� 4�� ������ �� �ִ�. ������ ���� �������� ����� ������ ���� �ȴ�.

�� ����� �Ϻ��ϰ� ������ ���� ��, �̱�� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ������ ����̰� ���� �����Ѵ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N �� 1000)

���
����̰� ������ �̱�� SK��, â���̰� ������ �̱�� CY�� ����Ѵ�.


���� �Է� 1
6

���� ��� 1
SK

*/


#include <iostream>
#include <algorithm>

enum e_Flag
{
	CY = 0,
	SK = 1
};


int n;
int dp[1001];


int main()
{

	std::cin >> n;

	dp[1] = CY; //����� ���� 1�� ��������, â�� ��
	dp[2] = SK; //����� 1�� ��������, â���� ���� 1�� �������� ��� ��
	dp[3] = CY; //��� 1��, â�� 1��, ������ 1���� ����� ��������, â����
	dp[4] = SK; //��� 3�� �������� ������ 1���� â���� ������, ��� ��


	for (int i = 5; i <= n; i++)
	{
		//����� ��������, ����� ������ 1���� �������� �ľ�, true == ����� ������ 1���� �������� ���, �� â�� ��
		if (std::min({ dp[i - 1], dp[i - 3], dp[i - 4] }) == 1) 
			dp[i] = CY;
		else
			dp[i] = SK;
	}

	if (dp[n] == SK)
		std::cout << "SK";
	else
		std::cout << "CY";
		

	return 0;
}