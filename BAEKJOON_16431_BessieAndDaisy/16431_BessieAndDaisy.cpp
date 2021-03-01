/*
https://www.acmicpc.net/problem/16431



문제
농부 존은 소 베시와 소 데이지를 키우고 있습니다.

두 소는 자유롭게 1,000 × 1,000 2차원 격자 목초지를 누비며 놀고 있습니다. 농부 존이 종을 치면 베시와 데이지가 농부 존이 있는 곳으로 달려갑니다.



베시가 B에 있을 때 1초 후에 움직일 수 있는 칸과 데이지가 D에 있을 때 1초 후에 움직일 수 있는 칸을 나타낸 그림


베시는 1초 후에 꼭짓점을 공유하는 8개의 칸 중 하나로 이동할 수 있고 데이지는 1초 후에 변을 공유하는 4개의 칸 중 하나로 이동할 수 있습니다. 
칸들은 충분히 넓어서 칸 하나에도 베시와 데이지 그리고 존이 같이 서 있을 수 있습니다.

베시와 데이지 두 소 모두 최단 경로로 존에게 갈 때 어떤 소가 더 빨리 도착할까요?



입력
첫 번째 줄에 베시의 좌표 Br, Bc (1 ≤ Br, Bc ≤ 1,000) 이 주어집니다.
두 번째 줄에 데이지의 좌표 Dr, Dc (1 ≤ Dr, Dc ≤ 1,000) 이 주어집니다.
세 번째 줄에 존의 좌표 Jr, Jc (1 ≤ Jr, Jc ≤ 1,000) 이 주어집니다.
처음에 존이 있는 칸에는 베시와 데이지가 없음이 보장됩니다.

출력
첫 번째 줄에 베시가 더 빨리 도착하면 'bessie', 데이지가 더 빨리 도착하면 'daisy', 동시에 도착하면 'tie' 를 출력합니다.



예제 입력 1
3 5
1 1
2 3

예제 출력 1
bessie


베시는 (3, 5) > (2, 4) > (2, 3) 경로로 이동하여 존에게 오는데 2초가 걸립니다.
반면 데이지는 (1, 1) > (1, 2) > (1, 3) > (2, 3) 경로로 이동하여 존에게 오는데 3초가 걸리므로 베시가 더 빨리 도착합니다.



예제 입력 2
13 13
11 11
11 12

예제 출력 2
daisy



예제 입력 3
4 5
5 4
4 4

예제 출력 3
tie


*/
#include <iostream>

struct Coord
{
	int x, y;
};

Coord bessie;
Coord Target;
Coord Daisy;

int DaisyCount;
int bessieCount;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> bessie.y >> bessie.x;

	std::cin >> Daisy.y >> Daisy.x;

	std::cin >> Target.y >> Target.x;

	//베시의 경우, 상하좌우, 대각선 이동 가능
	//x축의 거리차이와 y축의 거리 차이중 큰값 == 걸리는 시간
	bessieCount = std::max(std::abs(Target.x - bessie.x), std::abs(Target.y - bessie.y));


	//데이지의 경우 상하좌우 로만 이동 가능
	//x축의 거리차이와 y축의 거리차이의 합 == 걸리는 시간
	DaisyCount = std::abs(Target.x - Daisy.x) + std::abs(Target.y - Daisy.y);


	if (bessieCount < DaisyCount)
		std::cout << "bessie";
	else if (bessieCount > DaisyCount)
		std::cout << "daisy";
	else
		std::cout << "tie";

	return 0;
}