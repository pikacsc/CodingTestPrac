/*
https://www.acmicpc.net/problem/2204

����
���� ���񿡰� ����ܾ���� ������ �� � �ܾ ��ҹ��ڸ� �������� �ʰ� ���������� ���� �ռ����� ���߸� �縻�� �־� ������ ������شٰ� �Ͽ���.

������ �μ��� ���� ���� ���� ��� �׷��� ���� �ʾұ� ������ ��ҹ��ڸ� ���� ����� �ܾ���� �����ߴ�. ���� ���, apPle�� Bat���� �ռ����� AnT���ٴ� �ڿ� �ִ� �ܾ��.

���񿡰� ����� �����л��̴�! �������� ���񿡰� ������ �������ֵ��� ����!





�Է�
�� �׽�Ʈ���̽��� ���� n (2 �� n �� 1000) ���� �����ϸ� �־����� �ܾ��� ������ ���Ѵ�.

���� �� n���� ���̰� �ִ� 20�� �ܾ �־����� ��ҹ����� ������ ������ �� �Ȱ��� �ܾ�� �־����� �ʴ´�.

������ �Է��� 0�� �־�����.



���
�� �ٿ� �� �׽�Ʈ���̽����� ������ ���� �ռ��� �ܾ ����Ѵ�.



���� �Է� 1
3
Cat
fat
bAt
4
call
ball
All
Hall
0

���� ��� 1
bAt
All

*/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ctype.h>

struct STR
{
	char data[21];
};

bool compare(STR st1, STR st2)
{
	for (auto& l : st1.data)
	{
		if (islower(l))
		{
			l = toupper(l);
		}
	}

	for (auto& l : st2.data)
	{
		if (islower(l))
		{
			l = toupper(l);
		}
	}


	if (strcmp(st1.data, st2.data) > 0)
	{
		return false;
	}
	return true;
}

int n;


char buffer[21];

int main()
{

	std::vector<STR> strVect;

	scanf("%d", &n);

	while (n != 0)
	{
		if ((int)strVect.size() < n)
		{
			strVect.reserve(n);
		}

		for (int i = 0; i < n; i++)
		{
			STR newStr = { 0 };
			scanf("%s", newStr.data);
			strVect.push_back(newStr);
		}

		std::sort(strVect.begin(), strVect.end(), compare);
		printf("%s\n", (*strVect.begin()).data);
		strVect.clear();
		scanf("%d", &n);
	}


	return 0;
}