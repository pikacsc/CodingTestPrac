/*
https://www.acmicpc.net/problem/14563

������

����
��� �ڿ��� N�� ���ؼ� N�� ������ ���(�����)�� ���� N�� �Ǵ� �ڿ����� ��������� �Ѵ�. 

���� ���, 6�� ����� 1, 2, 3, 6�ε� 1+2+3�� 6�̱� ������ �������̴�. 

�� ������� ���� �ڱ� �ڽź��� ���� ��츦 ������, ������� ���� �ڱ� �ڽź��� ū ��츦 ���׼���� �Ѵ�.

�̶�, � ���� �־��� �� �� ���� ����������, ����������, ���׼������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٿ� �ڿ����� ���� T�� �־�����. T�� 1000���� ���� ���̴�.

��° �ٿ��� ������ ���̿� �ΰ� ���������� ���ؾ� �Ǵ� �ڿ��� N�� �־�����.(N<10000)


���
T�� �ٿ� ���ļ� �� �ڿ����� ���ؼ� �������� ��Perfect��, �������� ��Deficient��, ���׼��� ��Abundant���� ����Ѵ�.



���� �Է� 1
3
28 21 36


���� ��� 1
Perfect
Deficient
Abundant


*/

#include <iostream>

int T;

int numArr[1000];
int input;
int main()
{
	std::cin >> T;

	for (int i = 0; i < T; i++)
		std::cin >> numArr[i];

	for (int i = 0, sum = 0; i < T; i++)	
	{
		sum = 0;
		for (int j = 1; j <= numArr[i]; j++)
		{
			if (numArr[i] % j == 0 && numArr[i] / j != numArr[i])
				sum += numArr[i] / j;
		}
		if (sum == numArr[i])
			std::cout << "Perfect" <<std::endl;
		else if(sum < numArr[i])
			std::cout << "Deficient" <<std::endl;
		else if (sum > numArr[i])
			std::cout << "Abundant" << std::endl;
	}

	return 0;
}