/*
https://www.acmicpc.net/problem/10844


10844
���� ��� ��

����
45656�̶� ���� ����.

�� ���� ������ ��� �ڸ����� ���̰� 1�� ����. �̷� ���� ��� ����� �Ѵ�.

�����̴� ���� ���̰� N�� ��� ���� �� �� �ִ��� �ñ�������.

N�� �־��� ��, ���̰� N�� ��� ���� �� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (0���� �����ϴ� ���� ����.)



�Է�
ù° �ٿ� N�� �־�����. N�� 1���� ũ�ų� ����, 100���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� ������ 1,000,000,000���� ���� �������� ����Ѵ�.



���� �Է� 1
1

���� ��� 1
9


���� �Է� 2
2

���� ��� 2
17

*/
#include <iostream>

using namespace std;

int mod = 1000000000;
int dp[101][101];
int n;
int result;

int main()
{
    cin >> n;

    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;


    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];

            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]);

            dp[i][j] %= mod;
        }
    }


    for (int i = 0; i <= 9; i++)
    {
        result = (result + dp[n][i]) % mod;
    }
    cout << result;
    return 0;
}