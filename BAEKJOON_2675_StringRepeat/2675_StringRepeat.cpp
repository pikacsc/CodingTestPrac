/*
https://www.acmicpc.net/problem/2675

����
���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, ù ��° ���ڸ� R�� �ݺ��ϰ�, �� ��° ���ڸ� R�� �ݺ��ϴ� ������ P�� ����� �ȴ�. S���� QR Code "alphanumeric" ���ڸ� ����ִ�.

QR Code "alphanumeric" ���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: �̴�.



�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. �� �׽�Ʈ ���̽��� �ݺ� Ƚ�� R(1 �� R �� 8), ���ڿ� S�� �������� ���еǾ� �־�����. S�� ���̴� ��� 1�̸�, 20���ڸ� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽��� ���� P�� ����Ѵ�.



���� �Է� 1
2
3 ABC
5 /HTP

���� ��� 1
AAABBBCCC
/////HHHHHTTTTTPPPPP


*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

int T;

char buffer[21];

int main()
{

	scanf("%d", &T);


	for (int i = 0; i < T; i++)
	{
		int len = 0;
		buffer[0] = NULL;
		scanf("%d %s", &len, buffer);

		for (size_t j = 0; j < strlen(buffer); j++)
		{
			for (int k = 0; k < len; k++)
				printf("%c", buffer[j]);

		}
		printf("\n");

	}


	return 0;
}