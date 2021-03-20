/*
https://www.acmicpc.net/problem/2480

����
1�������� 6������ ���� ���� 3���� �ֻ����� ������ ������ ���� ��Ģ�� ���� ����� �޴� ������ �ִ�.

���� ���� 3���� ������ 10,000��+(���� ��)*1,000���� ����� �ް� �ȴ�.
���� ���� 2���� ������ ��쿡�� 1,000��+(���� ��)*100���� ����� �ް� �ȴ�.
��� �ٸ� ���� ������ ��쿡�� (�� �� ���� ū ��)*100���� ����� �ް� �ȴ�.
���� ���, 3���� �� 3, 3, 6�� �־����� ����� 1,000+3*100���� ���Ǿ� 1,300���� �ް� �ȴ�. 
�� 3���� ���� 2, 2, 2�� �־����� 10,000+2*1,000 ���� ���Ǿ� 12,000���� �ް� �ȴ�. 
3���� ���� 6, 2, 5�� �־����� ���� ���� ū ���� 6�̹Ƿ� 6*100���� ���Ǿ� 600���� ������� �ް� �ȴ�.

3�� �ֻ����� ���� ���� �־��� ��, ����� ����ϴ� ���α׷��� �ۼ� �Ͻÿ�.

�Է�
ù° �ٿ� 3���� ���� ��ĭ�� ���̿� �ΰ� ���� �־�����.

���
ù° �ٿ� ������ ����� ��� �Ѵ�.

���� �Է� 1
3 3 6
���� ��� 1
1300

*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int a, b, c;
int ans;

int main()
{
	scanf("%d %d %d", &a, &b, &c);

	//���� ���� 3���� ������ 10,000��+(���� ��)*1,000���� ����� �ް� �ȴ�.
	if (a == b && b == c)
		ans += 10000 + ((a) * 1000);
	//���� ���� 2���� ������ ��쿡�� 1,000��+(���� ��)*100���� ����� �ް� �ȴ�.
	else if (a == b)
		ans += 1000 + (a * 100);
	else if (b == c)
		ans += 1000 + (b * 100);
	else if (a == c)
		ans += 1000 + (c * 100);
	else //��� �ٸ� ���� ������ ��쿡�� (�� �� ���� ū ��)*100���� ����� �ް� �ȴ�.
	
	{
		ans += std::max(a, std::max(b, c)) * 100;
	}

	printf("%d", ans);
	
	return 0;
}