/*

https://www.acmicpc.net/problem/3009


문제
세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.




입력
세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

출력
직사각형의 네 번째 점의 좌표를 출력한다.



예제 입력 1
30 20
10 10
10 20

예제 출력 1
30 10


*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


int Xarr[1001];
int Yarr[1001];

int inputX;
int inputY;

int ansX;
int ansY;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &inputX, &inputY);

		
		if (Xarr[inputX] == 0)
			Xarr[inputX]++;
		else
			Xarr[inputX]--;

		if (Yarr[inputY] == 0)
			Yarr[inputY]++;
		else
			Yarr[inputY]--;

	}

	for (int i = 1; i <= 1000; i++)
	{
		if (Xarr[i] != 0)
			ansX = i;

		if (Yarr[i] != 0)
			ansY = i;
	}

	printf("%d %d", ansX, ansY);


	return 0;
}

