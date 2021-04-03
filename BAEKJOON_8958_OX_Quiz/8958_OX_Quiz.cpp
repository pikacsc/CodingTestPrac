/*
https://www.acmicpc.net/problem/8958

����
"OOXXOXXOOO"�� ���� OX������ ����� �ִ�. O�� ������ ���� ���̰�, X�� ������ Ʋ�� ���̴�. 
������ ���� ��� �� ������ ������ �� �������� ���ӵ� O�� ������ �ȴ�. ���� ���, 10�� ������ ������ 3�� �ȴ�.

"OOXXOXXOOO"�� ������ 1+2+0+0+1+0+0+1+2+3 = 10���̴�.

OX������ ����� �־����� ��, ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���̰� 0���� ũ�� 80���� ���� ���ڿ��� �־�����. ���ڿ��� O�� X������ �̷���� �ִ�.


���
�� �׽�Ʈ ���̽����� ������ ����Ѵ�.




���� �Է� 1
5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX

���� ��� 1
10
9
7
55
30

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

int T;


char buffer[80];


int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int ans = 0;
		int score = 0;
		scanf("%s", buffer);

		bool flag = false;

		for (int i = 0; i <= strlen(buffer); i++)
		{
			if (buffer[i] == 'O')
			{
				score++;
				ans += score;
			}
			else
			{
				score = 0;
			}
		}
		printf("%d\n", ans);
	}




	return 0;
}