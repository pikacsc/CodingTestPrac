/*
https://www.acmicpc.net/problem/2711

����
��â���� �ǳ� ��Ÿ�� ����. â���̰� ��Ÿ�� �� ����� ��Ÿ�� �� ��ġ�� �־����� ��, ��Ÿ�� ���� ���ڿ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

â���̴� ��Ÿ�� �ݵ�� 1���� ����.



�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1<=T<=1,000)�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �����Ǿ� �ִ�. 

ù ���ڴ� â���̰� ��Ÿ�� �� ��ġ�̰�, �� ��° ���ڿ��� â���̰� ģ ���ڿ��̴�. 

���ڿ��� ���� ù ���ڴ� 1��° �����̰�, ���ڿ��� ���̴� 80�� ���� �ʰ�, �빮�ڷθ� �̷���� �ִ�. ��Ÿ�� �� ��ġ�� ���ڿ� ���̺��� �۰ų� ����.

���
�� �׽�Ʈ ���̽��� ���� ��Ÿ�� ���� ���ڿ��� ����Ѵ�.



���� �Է� 1
4
4 MISSPELL
1 PROGRAMMING
7 CONTEST
3 BALLOON

���� ��� 1
MISPELL
ROGRAMMING
CONTES
BALOON

*/

#include <iostream>

int T;

int J;

std::string buffer;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		std::cin >> J;
		J--;
		std::cin.ignore();
		std::cin >> buffer;
		buffer.erase(buffer.begin() + J, buffer.begin() + J + 1);
		std::cout << buffer << std::endl;
		buffer.clear();
	}

	return 0;
}