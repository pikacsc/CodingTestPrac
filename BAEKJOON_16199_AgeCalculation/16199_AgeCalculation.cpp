/*
https://www.acmicpc.net/problem/16199


����
�ѱ����� ���̴� �� 3���� ������ �ִ�.

�� ����: �������� ǥ�� ����̴�. �ѱ������� �������� �� ���̸��� ����Ѵ�.
���� ����: �ѱ����� ���� ���̸� ����� ���� ���̸� �ǹ��Ѵ�.
�� ����: �������� �ϰ������� ����� �����ϱ� ���ؼ� ����ϴ� �����̴�.


�� ���̴� ������ �������� ����Ѵ�. � ����� �¾�� ��, �� ����� ���̴� 0���̰�, ������ ���� ������ 1���� �����Ѵ�. 
���� ���, ������ 2003�� 3�� 5���� ����� 2004�� 3�� 4�ϱ��� 0���̰�, 2004�� 3�� 5�Ϻ��� 2005�� 3�� 4�ϱ��� 1���̴�.

���� ���̴� ������ �������� ����Ѵ�. � ����� �¾�� ��, �� ����� ���̴� 1���̰�, ������ �ٲ� ������ 1���� �����Ѵ�. 
���� ���, ������ 2003�� 3�� 5���� ����� 2003�� 12�� 31�ϱ��� 1���̰�, 2004�� 1�� 1�Ϻ��� 2004�� 12�� 31�ϱ��� 2���̴�.

�� ���̴� ������ �������� ����ϰ�, ���� �������� ������ �� ���̴�. ���� ���, ������ 2003�� 3�� 5���� ����� 2003�� 12�� 31�ϱ��� 0���̰�, 2004�� 1�� 1�Ϻ��� 2004�� 12�� 31�ϱ��� 1���̴�.



� ����� ������ϰ� ���� ��¥�� �־����� ��, ���� ��¥�� �������� �� ����� �� ����, ���� ����, �� ���̸� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� � ����� �¾ ����, ��, ���� �־�����. ��������� �������� ���еǾ��� �ְ�, �׻� �ùٸ� ��¥�� �־�����.

��° �ٿ� ���� ��¥�� �־�����. ���� ��¥�� �������� ���еǾ��� ������, �ùٸ� ��¥�� �־�����.

�Է����� �־����� ��������� ���� ��¥�� ���ų� �� �����̴�.

�Է����� �־����� ������ 1900�⺸�� ũ�ų� ����, 2100�⺸�� �۰ų� ����.



���
ù° �ٿ� �� ����, ��° �ٿ� ���� ����, ��° �ٿ� �� ���̸� ����Ѵ�.



���� �Է� 1
2003 3 5
2003 4 5

���� ��� 1
0
1
0


���� �Է� 2
2003 3 5
2004 1 1

���� ��� 2
0
2
1


���� �Է� 3
2005 1 1
2007 1 1

���� ��� 3
2
3
2


���� �Է� 4
2005 12 31
2007 1 1

���� ��� 4
1
3
2


���� �Է� 5
2006 1 1
2007 1 1

���� ��� 5
1
2
1


���� �Է� 6
2005 1 2
2007 1 1

���� ��� 6
1
3
2

*/



//������ = ������ ������ ������ - 1, ���� ���� �Ǵ� �Ŀ��� �������� ���� ������ 
//���³��� = ���翬�� - ���� + 1
//������ = ���翬�� - ����

//
//#include <iostream>
//
//int birth_year;
//int birth_month;
//int birth_day;
//
//int this_year;
//int this_month;
//int this_day;
//
//int age1; //������
//int age2; //���³���
//int age3; //������
//
//int main()
//{
//	std::cin >> birth_year >> birth_month >> birth_day;
//	std::cin >> this_year >> this_month >> this_day;
//	
//	//������ ���
//	if (this_month >= birth_month)
//	{
//		if (this_day >= birth_day)
//		{
//			age1 = this_year - birth_year;
//		}
//		else
//		{
//			age1 = this_year - birth_year - 1;
//		}
//	}
//	else
//	{
//		age1 = this_year - birth_year - 1;
//	}
//	
//	//���³��� ���
//	age2 = this_year - birth_year + 1;
//
//	//������ ���
//	age3 = this_year - birth_year;
//
//	std::cout << age1 << std::endl;
//	std::cout << age2 << std::endl;
//	std::cout << age3 << std::endl;
//
//	return 0;
//}



#include <iostream>

int birth_year;
int birth_month;
int birth_day;

int this_year;
int this_month;
int this_day;

int age1; //������
int age2; //���³���
int age3; //������

int main()
{
	std::cin >> birth_year >> birth_month >> birth_day;
	std::cin >> this_year >> this_month >> this_day;
	
	age2 = this_year - birth_year + 1;
	age3 = this_year - birth_year;

	if (birth_year == this_year)
		age1 = 0;
	else
	{
		if (birth_month < this_month)
		{
			age1 = this_year - birth_year;
		}
		else if(birth_month == this_month)
		{
			if (birth_day > this_day)
				age1 = this_year - birth_year - 1;
			else
				age1 = this_year - birth_year;
		}
		else
		{
			age1 = this_year - birth_year - 1;
		}
			
	}

	std::cout << age1 << std::endl;
	std::cout << age2 << std::endl;
	std::cout << age3 << std::endl;


	return 0;
}