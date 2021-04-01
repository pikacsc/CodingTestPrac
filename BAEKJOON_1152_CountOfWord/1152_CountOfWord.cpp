/*
https://www.acmicpc.net/problem/1152

����
���� ��ҹ��ڿ� ���⸸���� �̷���� ���ڿ��� �־�����.
�� ���ڿ����� �� ���� �ܾ ������? �̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �� �ܾ ���� �� �����ϸ� ������ Ƚ����ŭ ��� ����� �Ѵ�.




�Է�
ù �ٿ� ���� ��ҹ��ڿ� ����� �̷���� ���ڿ��� �־�����. 
�� ���ڿ��� ���̴� 1,000,000�� ���� �ʴ´�. �ܾ�� ���� �� ���� ���еǸ�, ������ �����ؼ� ������ ���� ����. ���� ���ڿ��� �հ� �ڿ��� ������ ���� ���� �ִ�.

���
ù° �ٿ� �ܾ��� ������ ����Ѵ�.




���� �Է� 1
The Curious Case of Benjamin Button

���� ��� 1
6



���� �Է� 2
 Mazatneunde Wae Teullyeoyo

���� ��� 2
3


���� �Է� 3
Teullinika Teullyeotzi

���� ��� 3
2

*/

#include <iostream>
#include <cstring>
#include <string>


std::string buffer;

int count = 0;

int main()
{
	std::getline(std::cin, buffer);

	for (int i = 0; i < (int)buffer.length(); i++)
	{
		if (buffer[i] == ' ')
			count++;
	}

	if (buffer[0] == ' ')
		count--;

	if (buffer[buffer.length() - 1] == ' ')
		count--;


	std::cout << count + 1;


	return 0;
}