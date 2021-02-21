/*
https://www.acmicpc.net/problem/11575

Affine Cipher

����
���ʳ��󿡼� Ư���Ʒ��� ���� �����̴� ���ʳ���� ħ���� �ϰ� �Ǿ���. 
�پ �����̿��� �����̴� ���ʳ����� ������ �Լ��ϰ� �Ǿ��� ������ �����ϰ� ���ʳ���� �����ϱ� ���� ���� ��ȣ(Affine Cipher)�� �̿��ϱ�� �Ͽ���.
���� ��ȣ�� ������ ���� ���� ���� ���� �� �ִ�.

E(X) = (aX + b) mod 26

A���� Z������ ���ĺ��� ���ʴ�� 0, 1, 2, ... , 25 ��� ����. a = 3�̰�, b = 1�� ��쿡 ���ĺ� A�� ���� ��ȣ�Ŀ� �����ϸ� E(0) = (3 �� 0 + 1) mod 26 �� �Ǿ� ��ȣȭ�� ����� B�� �ȴ�.

a�� b, �׸��� ���ĺ� �빮�ڷθ� ������ ���� �־����� ��, �̸� ��ȣ������ ġȯ�ϴ� ���α׷��� �ۼ��϶�.

�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� ���� T(1 �� T �� 50) �� �־�����.

�� �׽�Ʈ ���̽��� ù ��° �ٿ��� �� ���� a�� b(0 < a, b �� 1,000,000)�� ���� �־�����. a�� 26�� ���μ��̴�.

�� �׽�Ʈ���̽��� �� ��° �ٿ��� �� s�� �־�����. ���� ���� |s|�� 0���� ũ�� 1,000,000���� �۴�.

���
�� �׽�Ʈ ���̽����� �� �ٿ� �� ���� �� s�� ��ȣ������ ġȯ�� ����� ����Ѵ�.



���� �Է� 1
2
3 1
IAMSPY
5 3
ABCDEFGHIJKLMNOPQRSTUVWXYZ


���� ��� 1
ZBLDUV
DINSXCHMRWBGLQVAFKPUZEJOTY

*/


#include <iostream>
#include <string>

#define MOD 26

int T;
int a, b;
std::string buffer;
std::string buffer2;


int main()
{
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		std::cin >> a >> b;
		std::cin >> buffer;

		for (int j = 0; j < (int)buffer.size(); j++)
		{
			//E(X) = (aX + b) mod 26
			char c = (char)(((a * (buffer.c_str()[j]) - 'A') + b) % MOD) + 'A';
			buffer2.push_back(c);
		}

		std::cout << buffer2 << std::endl;
		buffer2.clear();
		buffer.clear();
	}


	return 0;
}