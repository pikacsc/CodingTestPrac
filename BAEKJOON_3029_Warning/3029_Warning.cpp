/*
https://www.acmicpc.net/problem/3029

���

����
â���������� �������� �ݶ��� ���з� ������. (3028��)

�׷�����Ʈ�� ������ �����̴� â�������� ��� �Ϸ��� �Ѵ�.

��� �����̴� â���������� ���� ���ѻ���̴�. ����, ������� ��ġ�� �ʰ��Ϸ��� �Ѵ�.

��Ʃ�꿡�� ���߿� ���� �������� ã�ƺ��ٰ�, �״� ��Ʈ���� ���� ������ �����Ѵٴ� ����� �˰� �Ǿ���.

�����̴� â�������� �߽��� ������ "���갭" ��ó�� �����ִٰ�, ��Ʈ���� ���� ������ó�� ���� ���� ���̴�.

���� �ð��� �����̰� ��Ʈ���� ���� �ð��� �־����� ��, �����̰� �󸶳� �����־�� �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (�����̴� ��� 1�ʸ� ��ٸ���, ���ƾ� 24�ð��� ��ٸ���.)



�Է�
ù° �ٿ� ���� �ð��� hh:mm:ss �������� �־�����. (��, ��, ��) hh�� 0���� ũ�ų� ����, 23���� �۰ų� ������, �а� �ʴ� 0���� ũ�ų� ����, 59���� �۰ų� ����.

��° �ٿ��� ��Ʈ���� ���� �ð��� ���� ���� �������� �־�����.

���
ù° �ٿ� �����̰� ��ٷ��� �ϴ� �ð��� �Է°� ���� �������� ����Ѵ�.




���� �Է� 1
20:00:00
04:00:00

���� ��� 1
08:00:00

*/

#include <iostream>
#include <string>

std::string time1, time2;
int hour, min, sec;
int main()
{
	std::ios_base::sync_with_stdio(false);

	std::getline(std::cin, time1);
	std::getline(std::cin, time2);

	int time1_hour = atoi(time1.substr(0, 2).c_str()); 
	int time1_min = atoi(time1.substr(3, 5).c_str());  
	int time1_sec = atoi(time1.substr(6, 8).c_str());  
													   
	int time2_hour = atoi(time2.substr(0, 2).c_str());
	int time2_min = atoi(time2.substr(3, 5).c_str()); 
	int time2_sec = atoi(time2.substr(6, 8).c_str()); 

	int cts = time1_hour * 3600 + time1_min * 60 + time1_sec;
	int tts = time2_hour * 3600 + time2_min * 60 + time2_sec;
	int ans = (cts < tts) ? tts - cts : 86400 - cts + tts;

	hour = ans / 3600;
	min = ans % 3600 / 60;
	sec = ans % 60;

	std::cout.fill('0');
	std::cout.width(2);
	std::cout << hour << ':';

	std::cout.fill('0');
	std::cout.width(2);
	std::cout << min << ':';

	std::cout.fill('0');
	std::cout.width(2);
	std::cout << sec;

	return 0;
}