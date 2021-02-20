/*
https://www.acmicpc.net/problem/3029

경고

문제
창영마을에서 정인이의 반란은 실패로 끝났다. (3028번)

테러리스트로 변신한 정인이는 창영마을에 경고를 하려고 한다.

사실 정인이는 창영마을에서 제일 착한사람이다. 따라서, 사람들을 다치지 않게하려고 한다.

유튜브에서 폭발에 대한 동영상을 찾아보다가, 그는 나트륨을 물에 던지면 폭발한다는 사실을 알게 되었다.

정인이는 창영마을의 중심을 지나는 "강산강" 근처에 숨어있다가, 나트륨을 위의 동영상처럼 물에 던질 것이다.

현재 시간과 정인이가 나트륨을 던질 시간이 주어졌을 때, 정인이가 얼마나 숨어있어야 하는지 구하는 프로그램을 작성하시오. (정인이는 적어도 1초를 기다리며, 많아야 24시간을 기다린다.)



입력
첫째 줄에 현재 시간이 hh:mm:ss 형식으로 주어진다. (시, 분, 초) hh는 0보다 크거나 같고, 23보다 작거나 같으며, 분과 초는 0보다 크거나 같고, 59보다 작거나 같다.

둘째 줄에는 나트륨을 던질 시간이 위와 같은 형식으로 주어진다.

출력
첫째 줄에 정인이가 기다려야 하는 시간을 입력과 같은 형식으로 출력한다.




예제 입력 1
20:00:00
04:00:00

예제 출력 1
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