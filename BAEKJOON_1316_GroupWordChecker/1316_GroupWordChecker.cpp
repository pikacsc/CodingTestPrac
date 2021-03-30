/*
https://www.acmicpc.net/problem/1316

����
�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�. 

���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.

�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٿ� �ܾ��� ���� N�� ���´�. N�� 100���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ� �ܾ ���´�. �ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.

���
ù° �ٿ� �׷� �ܾ��� ������ ����Ѵ�.



���� �Է� 1
3
happy
new
year

���� ��� 1
3


���� �Է� 2
4
aba
abab
abcabc
a

���� ��� 2
1


*/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

int N;

char buffer[100];

int count;

bool flag;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", buffer);

		flag = true;

		for (int j = 0; j <= strlen(buffer); j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (buffer[j] != buffer[j - 1] && buffer[j] == buffer[k])
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
			count++;

	}

	printf("%d", count);


	return 0;
}