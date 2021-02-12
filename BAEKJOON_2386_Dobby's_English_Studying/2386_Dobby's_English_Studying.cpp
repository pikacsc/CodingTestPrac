/*

https://www.acmicpc.net/problem/2386

������ ���� ����

����
���� ������ ������ ���� ��� ����ġ��� ����ߴ�. 

������ ����� �ٺ��� ABC���� ����� �Ѵ�.

�׷��� ���� ���� ����� ���ĺ� �ϳ��� �־����� �� ���ĺ��� ���忡�� �� �� ��Ÿ�������� ���� �������� ���־���. 

������ ����� ������� �İ��� �������.

�������� ���� ���� ������ ���� �˷��ִ� ���α׷��� ����� �������̴�!



�Է�
�Է��� �� ���� �ٵ�� �̷������.

�� �ٿ��� �ϳ��� �ҹ��ڿ� ���� ������ �������� ���еǾ� �־�����.

�� ������ ���̰� 1���� 250�̸� �Է��� �������� #�̴�.


���
����� �� ���� �Է����� �־��� �ҹ��ڿ� �� �ҹ��� ���ĺ��� ��Ÿ�� Ƚ���� �̷������. �̶� ���忡�� �ش� ���ĺ��� �ҹ��ڷ� ��Ÿ���� �빮�ڷ� ��Ÿ���� ��� ���� �Ѵ�.


���� �Է� 1
g Programming Contest
n New Zealand
x This is quite a simple problem.
#

���� ��� 1
g 2
n 2
x 0

*/

#include <iostream>
#include <string>
#include <algorithm>

std::string buffer;
char input;
int charCount;
int main()
{
	std::cin >> input;
	while (input != '#')
	{
		std::getline(std::cin, buffer);
		std::transform(buffer.begin(), buffer.end(), buffer.begin(), tolower);

		for (auto& l : buffer)
			if (l == input) charCount++;

		std::cout << input << " " << charCount << std::endl;
		charCount = 0;
		buffer.clear();
		std::cin >> input;
	}
	return 0;
}