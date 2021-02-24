/*
https://www.acmicpc.net/problem/2083

����
�� ��� ���� Ŭ���� ȸ������ ���κ� �Ǵ� û�ҳ�η� �з��ȴ�.

���̰� 17������ ���ų�, �����԰� 80kg �̻��̸� ���κ��̴�. �� �ۿ��� ��� û�ҳ���̴�. Ŭ�� ȸ������ �ùٸ��� �з��϶�.



�Է�
�� ���� �̸��� �� �ڿ����� �̷������. �� �ڿ����� ������� ���̿� �����Ը� ��Ÿ����. �Է��� ������ ���� # 0 0 �̴�. �� �Է��� ó������ �ʴ´�.

�̸��� ���ĺ� ��/�ҹ��ڷθ� �̷���� �ְ�, ���̴� 10�� ���� �ʴ´�.

���
�Է� ���� �� ȸ���� ���� �̸��� �з��� ����Ѵ�. ���κ� ȸ���̸� 'Senior', û�ҳ�� ȸ���̸� 'Junior'�� ����Ѵ�.



���� �Է� 1
Joe 16 34
Bill 18 65
Billy 17 65
Sam 17 85
# 0 0

���� ��� 1
Joe Junior
Bill Senior
Billy Junior
Sam Senior

*/

#include <iostream>

char buffer[11];
int age;
int weight;

int main()
{
	while (1)
	{
		std::cin >> buffer;
		if (buffer[0] != '#')
			std::cout << buffer;
		buffer[0] = 0;

		std::cin >> age;
		std::cin >> weight;
		if (age != 0 && weight != 0)
		{
			if (age > 17 || weight >= 80)
				std::cout << " Senior" << std::endl;
			else
				std::cout << " Junior" << std::endl;
		}
		else
		{
			break;
		}
	}
	

	return 0;
}