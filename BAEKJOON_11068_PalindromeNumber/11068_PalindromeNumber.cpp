/*
https://www.acmicpc.net/problem/11068

����
� ���� ���ʺ��� �о, �����ʺ��� �о ���� �� �� ���� ȸ���� ����� �Ѵ�. 
���� ���, 747�� ȸ���� ���̴�. 255�� ȸ���� ���ε�, 16������ ǥ���ϸ� FF�̱� �����̴�. 
���� ������ �Է¹޾��� ��, �� ���� � B���� (2 �� B �� 64)���� ǥ���ϸ� ȸ���� �Ǵ� ��찡 �ִ��� �˷��ִ� ���α׷��� �ۼ��Ͻÿ�. 
B�����̶�, �� �ڸ����� ���� ǥ���� �� �� �� �ִ� ���� �������� B��� ���̴�. ���� ���, ���������� B�� 10�̴�.



�Է�
�Է� �����ʹ� ǥ���Է��� ����Ѵ�. �Է��� T���� �׽�Ʈ �����ͷ� �����ȴ�. 
�Է��� ù ��° �ٿ��� �׽�Ʈ �������� ���� ��Ÿ���� ���� T�� �־�����. �� �׽�Ʈ �����ʹ� 64 �̻� 1,000,000 ������ �ϳ��� ������ �־�����.

���
����� ǥ������� ����Ѵ�. �ϳ��� �׽�Ʈ �����Ϳ� ���� ���� �ϳ��� �ٿ� ����Ѵ�.
�� �׽�Ʈ �����Ϳ� ����, �־��� ���� � B���� (2 �� B �� 64)���� ǥ���Ͽ� ȸ���� �� �� �ִٸ� 1��, �׷��� �ʴٸ� 0�� ����Ѵ�.




���� �Է� 1
3
747
255
946734


���� ��� 1
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