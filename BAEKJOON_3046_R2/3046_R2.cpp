/*
https://www.acmicpc.net/problem/3046

����
�� ���� R1�� R2�� ���� ��, �� ���� ��� S�� (R1+R2)/2�� ����. 

����̴� ������ ���� ������ �� ���� R1�� R2�� �ַ��� �Ѵ�. 

���� ��Ƽ���� ����̴� �����̿��� �� �� ���ڸ� �����ְ�, �����̴� �� ���ڸ� �޾� ���´�. �׸��� ���� ��� �������� 1�⵿�� �� ���ڸ� �ܿ�鼭 ���.

����̴� R1�� R2�� ��û�� ���� ���� ���ߴ�. �۳⿡�� R1�� R2�� ��Ծ �ƹ� ���ڳ� ���ؼ� �־��� ������, ���ش� ����� �ʱ� ���ؼ� ��� S�� ���� ����Ϸ��� �Ѵ�.

������ ������ �����̴�. 5�� �Ŀ� ����̴� ���� ������ �� ���� R1�� R2�� �����־�� ������, ��Ÿ���Ե� R2�� ��԰� ���Ҵ�. ������ R1�� S�� ����ϰ� �ִ�!

����̸� ���� R2�� �� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٿ� �� ���� R1�� S�� �־�����. �� ���� -1000���� ũ�ų� ����, 1000���� �۰ų� ����.

���
ù° �ٿ� R2�� ����Ѵ�.



���� �Է� 1
11 15

���� ��� 1
19


���� �Է� 2
4 3

���� ��� 2
2

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

int R1, S;

int R2;

int main()
{
	
	//S == (R1 + R2) / 2
	scanf("%d %d", &R1, &S);


	//S == (R1 + R2) / 2
	//2S == R1 + R2
	//2S - R1 == R2
	printf("%d", 2 * S - R1);
	return 0;
}