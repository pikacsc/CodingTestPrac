/*
https://www.acmicpc.net/problem/11068

문제
어떤 수를 왼쪽부터 읽어도, 오른쪽부터 읽어도 같을 때 이 수를 회문인 수라고 한다. 
예를 들어, 747은 회문인 수이다. 255도 회문인 수인데, 16진수로 표현하면 FF이기 때문이다. 
양의 정수를 입력받았을 때, 이 수가 어떤 B진법 (2 ≤ B ≤ 64)으로 표현하면 회문이 되는 경우가 있는지 알려주는 프로그램을 작성하시오. 
B진법이란, 한 자리에서 수를 표현할 때 쓸 수 있는 수의 가짓수가 B라는 뜻이다. 예를 들어, 십진법에서 B는 10이다.



입력
입력 데이터는 표준입력을 사용한다. 입력은 T개의 테스트 데이터로 구성된다. 
입력의 첫 번째 줄에는 테스트 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터는 64 이상 1,000,000 이하인 하나의 정수로 주어진다.

출력
출력은 표준출력을 사용한다. 하나의 테스트 데이터에 대한 답을 하나의 줄에 출력한다.
각 테스트 데이터에 대해, 주어진 수가 어떤 B진법 (2 ≤ B ≤ 64)으로 표현하여 회문이 될 수 있다면 1을, 그렇지 않다면 0을 출력한다.




예제 입력 1
3
747
255
946734


예제 출력 1
1
1
0


*/

#include <iostream>
#include <stack>
#include <string>

std::string buffer;
std::string buffer2;
int T;
int input;


bool IsPalindrome(int input)
{

	for (int j = 2; j <= 64; j++)
	{
		int num = input;
		buffer.clear();
		buffer2.clear();

		while (num)
		{
			buffer.push_back(num % j);
			num /= j;
		}

		for (int i = buffer.length() - 1; i >= 0; i--)
			buffer2.push_back(buffer[i]);


		if (buffer == buffer2)
			return true;
	}
	return false;
}

int main()
{
	
	std::cin >> T;
	for (int i = 0; i < T; i++)
	{
		std::cin >> input;
		std::cout << IsPalindrome(input) << std::endl;
	}
	
	return 0;
}