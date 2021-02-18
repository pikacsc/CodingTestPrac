/*
https://www.acmicpc.net/problem/14593


문제
아주대학교 프로그래밍 경시대회(Ajou Programming Contest, APC)는 2009년 제1회를 시작으로 2014년 제6회까지 개최된 아주대학교 학생들을 위한 프로그래밍 경시대회이다. 
2017년, 다른 학교에서 활발히 진행되는 교내대회를 보던 현정이는 3년 만에 APC를 부활시키기로 결심했다.

2017 APC 운영 방식은 다음과 같다.

문제는 Small 데이터와 Large 데이터로 이루어져 있다.
문제를 풀기 위해서는 입력 파일을 다운로드 받고, 5분 이내로 이에 맞는 출력 파일과 소스 코드를 업로드해야 한다.
Small 데이터 문제를 해결해야 Large 데이터 입력 파일을 다운로드 받을 수 있다.
각 문제의 Small, Large 데이터를 해결하면 점수를 얻을 수 있으며, 이 점수는 각각 다르다.
제출 횟수는 점수를 획득한 문제를 맞기 까지 인풋을 다운로드 받은 횟수의 총합이다.
즉, 점수를 획득하지 못한 문제의 다운로드 횟수는 포함되지 않는다.
위 운영 방식에 따라 순위는 다음과 같이 결정된다.

해결한 문제 점수의 총합이 높은 참가자가 더 높은 순위를 가진다.
점수의 총합이 같은 경우, 제출 횟수가 적은 참가자가 더 높은 순위를 가진다.
점수의 총합과 제출 횟수가 같은 경우, 마지막으로 점수를 획득한 문제의 업로드 시간이 빠른 참가자가 더 높은 순위를 가진다.
매우 유감스럽게도 현정이는 며칠째 잠을 제대로 자지 못해 흉폭해져있다. 현정이의 일을 덜어 잠깐이라도 잘 수 있도록 참가자들의 순위를 계산하는 프로그램을 작성해주자.




입력
첫 번째 줄에는 참가자의 수를 나타내는 자연수 N (1 ≤ N ≤ 10,000) 이 주어진다.

두 번째 줄부터 N 개의 줄에 걸쳐 세개의 정수 Si, Ci, Li (0 ≤ Si ≤ 620, 0 ≤ Ci ≤ 50, 0 ≤ Li ≤ 179)가 주어진다.

(1+i) 번째 줄의 각 값은 차례로 i 번째 참가자의 점수, 제출 횟수, 마지막으로 점수를 획득한 문제의 업로드 시간을 나타낸다. 세 값이 모두 같은 참가자는 존재하지 않는다.


출력
1등을 하는 참가자의 번호를 한 줄에 출력한다.



예제 입력 1
2
620 7 179
300 5 100

예제 출력 1
1



예제 입력 2
3
300 5 100
620 7 179
600 9 150

예제 출력 2
2

*/
#include <iostream>
#include <queue>

int S, C, L, N;

struct Student
{
	int index;
	int s;
	int c;
	int l;
};

struct Compare
{
	bool operator()(Student& s1, Student& s2)
	{
		if (s1.s == s2.s)
		{
			if (s1.c == s2.c)
			{
				return s1.l > s2.l;
			}
			return s1.c > s2.c;
		}
		return s1.s < s2.s;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);

	std::priority_queue<Student, std::vector<Student>, Compare> pq;

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		Student st = { 0 };
		st.index = i + 1;
		std::cin  >> st.s >> st.c >> st.l;
		pq.push(st);
	}

	std::cout << pq.top().index;
	

	return 0;
}