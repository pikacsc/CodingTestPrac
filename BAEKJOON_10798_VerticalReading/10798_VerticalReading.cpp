/*
https://www.acmicpc.net/problem/10798

����
���� ���� �𸣴� �����̰� ���� �ɸ� ĥ�ǿ� �ڼ��� �پ��ִ� ���ڵ��� ���̴� �峭���� ������ ��� �ִ�.

�� �峭���� �ִ� ���ڵ��� ���� �빮�� ��A������ ��Z��, ���� �ҹ��� ��a������ ��z��, ���� ��0������ ��9���̴�. 
�����̴� ĥ�ǿ� ���ڵ��� �������� �Ϸķ� �ٿ��� �ܾ �����. �ٽ� �� �Ʒ��ʿ� ���ڵ��� �ٿ��� �� �ٸ� �ܾ �����. 
�̷� ������ �ټ� ���� �ܾ �����. �Ʒ� �׸� 1�� �����̰� ĥ�ǿ� �ٿ� ���� �ܾ���� ���̴�.

A A B C D D
a f z z
0 9 1 2 1
a 8 E W g 6
P 5 h 3 k x
<�׸� 1>

�� ���� �ܾ�� ���ڵ��� ��ĭ ���� �������� �����ؼ� �ִ� 15���� ���ڵ�� �̷������. ���� ������� �ټ� ���� �ܾ���� ���� ������ ���� �ٸ� �� �ִ�.

�ɽ����� �����̴� ĥ�ǿ� ������� �ټ� ���� �ܾ ���η� ������ �Ѵ�. ���η� ���� ��, �� �ܾ��� ù ��° ���ڵ��� ������ �Ʒ��� ���η� �д´�. 
������ �� ��° ���ڵ��� ���η� �д´�. �̷� ������ ���ʿ��� ���������� �� �ڸ��� �̵� �ϸ鼭 ������ �ڸ��� ���ڵ��� ���η� �о� ������. 
���� �׸� 1�� �ټ� ��° �ڸ��� ���� �� ��° ���� �ټ� ��° �ڸ��� ���ڴ� ����. �̷� ���ó�� ���η� ���� �� �ش� �ڸ��� ���ڰ� ������, ���� �ʰ� �� ���� ���ڸ� ��� �д´�. 
�׸� 1�� �ټ� ��° �ڸ��� ���η� ������ D1gk�� �д´�.

�׸� 1���� �����̰� ���η� ���� ������� ���ڵ��� ���� ���� ����ϸ� ������ ����:

Aa0aPAf985Bz1EhCz2W3D1gkD6x

ĥ�ǿ� �ٿ��� �ܾ���� �־��� ��, �����̰� ���η� ���� ������� ���ڵ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�� �ټ����� �Է��� �־�����. �� �ٿ��� �ּ� 1��, �ִ� 15���� ���ڵ��� ��ĭ ���� �������� �־�����. 
�־����� ���ڴ� ���� �빮�� ��A������ ��Z��, ���� �ҹ��� ��a������ ��z��, ���� ��0������ ��9�� �� �ϳ��̴�. �� ���� ���۰� �������� ��ĭ�� ����.

���
�����̰� ���η� ���� ������� ���ڵ��� ����Ѵ�. �̶�, ���ڵ��� ���� ���� �����ؼ� ����Ѵ�.



���� �Է� 1
ABCDE
abcde
01234
FGHIJ
fghij

���� ��� 1
Aa0FfBb1GgCc2HhDd3IiEe4Jj



���� �Է� 2
AABCDD
afzz
09121
a8EWg6
P5h3kx

���� ��� 2
Aa0aPAf985Bz1EhCz2W3D1gkD6x

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

char buffer[5][15];

int main()
{
	for (int i = 0; i < 5; i++)
	{
		scanf("%s", buffer[i]);
	}

	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (buffer[i][j] == NULL)
				continue;
			else
				printf("%c", buffer[i][j]);
		}
	}


	return 0;
}