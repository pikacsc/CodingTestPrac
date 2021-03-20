/*
https://www.acmicpc.net/problem/5585

����
Ÿ�δ� ���� JOI��ȭ������ ������ ���. 

JOI��ȭ������ �ܵ����� 500��, 100��, 50��, 10��, 5��, 1���� ����� �ְ�, ������ �Ž����� ������ ���� ���� �ܵ��� �ش�. 

Ÿ�ΰ� JOI��ȭ������ ������ ��� ī���Ϳ��� 1000�� ���� ���� ���� ��, ���� �ܵ��� ���Ե� �ܵ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ��� �Էµ� ��1�� ��쿡�� �Ʒ� �׸����� ó�� 4���� ����ؾ� �Ѵ�.




�Է�
�Է��� ���ٷ� �̷�����ְ�, Ÿ�ΰ� ������ ��(1 �̻� 1000�̸��� ����) 1���� �������ִ�.

���
������ ��� ������ 1�����θ� �Ǿ� �ִ�. �ܵ��� ���Ե� �ż��� ����Ͻÿ�.



���� �Է� 1
380

���� ��� 1
4


*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int pay;

int change;

int ans;

int main()
{
	scanf("%d", &pay);

	change = 1000 - pay;

	while (change - 500 >= 0)
	{
		change -= 500;
		ans++;
	}

	while (change - 100 >= 0)
	{
		change -= 100;
		ans++;
	}

	while (change - 50 >= 0)
	{
		change -= 50;
		ans++;
	}

	while (change - 10 >= 0)
	{
		change -= 10;
		ans++;
	}

	while (change - 5 >= 0)
	{
		change -= 5;
		ans++;
	}

	while (change - 1 >= 0)
	{
		change -= 1;
		ans++;
	}

	printf("%d", ans);

	return 0;
}