/*
https://www.acmicpc.net/problem/10987

����
���ĺ� �ҹ��ڷθ� �̷���� �ܾ �־�����. �̶�, ����(a, e, i, o, u)�� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ܾ �־�����. �ܾ��� ���̴� 1���� ũ�ų� ����, 100���� �۰ų� ������, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

���
ù° �ٿ� ������ ������ ����Ѵ�.



���� �Է� 1
baekjoon


���� ��� 1
4

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

char buffer[101];

int count;

int main()
{
	scanf("%s", buffer);

	for (int i = 0; i <= strlen(buffer); i++)
	{
		if (buffer[i] == 'a')
			count++;
		if (buffer[i] == 'e')
			count++;
		if (buffer[i] == 'i')
			count++;
		if (buffer[i] == 'o')
			count++;
		if (buffer[i] == 'u')
			count++;
	}
	printf("%d", count);



	return 0;
}