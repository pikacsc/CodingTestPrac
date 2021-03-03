/*
https://www.acmicpc.net/problem/1100

����
ü������ 8*8ũ���̰�, ���� ĭ�� �Ͼ� ĭ�� �����ư��鼭 ��ĥ�Ǿ� �ִ�. 

���� ���� ��ĭ (0,0)�� �Ͼ���̴�. ü������ ���°� �־����� ��, �Ͼ� ĭ ���� ���� �� �� �ִ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٺ��� 8���� �ٿ� ü������ ���°� �־�����. ��.���� �� ĭ�̰�, ��F���� ���� ���� �ִ� ĭ�̴�.

���
ù° �ٿ� ������ ������ ����Ѵ�.



���� �Է� 1
.F.F...F
F...F.F.
...F.F.F
F.F...F.
.F...F..
F...F.F.
.F.F.F.F
..FF..F.

���� ��� 1
1

*/

#include <iostream>

std::string buffer;

int count;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int i = 1; i <= 8; i++)
	{
		std::cin >> buffer;
		for (int j = 1; j <= 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					if (buffer.c_str()[j - 1] == 'F')
						count++;
				}
			}
			else
			{
				if (j % 2 != 0)
				{
					if (buffer.c_str()[j - 1] == 'F')
						count++;
				}
			}
		}
	}
	
	std::cout << count;

	return 0;
}