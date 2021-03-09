/*
https://www.acmicpc.net/problem/13460


����
��ŸƮ��ũ���� �Ǹ��ϴ� ��̿� �峭�� �߿��� ���� �αⰡ ���� ��ǰ�� ���� Ż���̴�. ���� Ż���� ���簢�� ���忡 ���� ������ �Ķ� ������ �ϳ��� ���� ����, ���� ������ ������ ���� ������ �����̴�.

������ ���� ũ��� N, ���� ũ��� M�̰�, ���ǻ� 1��1ũ���� ĭ���� �������� �ִ�. ���� �ٱ� ��� ���� ��� ������ �ְ�, ���忡�� ������ �ϳ� �ִ�. 

���� ������ �Ķ� ������ ũ��� ���忡�� 1��1ũ���� ĭ�� ���� ä��� �������̰�, ���� �ϳ��� �� �ִ�. ������ ��ǥ�� ���� ������ ������ ���ؼ� ������ ���̴�. �̶�, �Ķ� ������ ���ۿ� ���� �� �ȴ�.

�̶�, ������ ������ �ǵ帱 ���� ����, �߷��� �̿��ؼ� �̸� ���� ������ �Ѵ�. �������� ����̱�, ���������� ����̱�, �������� ����̱�, �Ʒ������� ����̱�� ���� �� ���� ������ �����ϴ�.

������ ���ۿ��� ���� ���ÿ� �����δ�. ���� ������ ���ۿ� ������ ����������, �Ķ� ������ ���ۿ� ������ �����̴�. ���� ������ �Ķ� ������ ���ÿ� ���ۿ� ������ �����̴�. 

���� ������ �Ķ� ������ ���ÿ� ���� ĭ�� ���� �� ����. ��, ���� ������ �Ķ� ������ ũ��� �� ĭ�� ��� �����Ѵ�. ����̴� ������ �׸��ϴ� ���� �� �̻� ������ �������� ���� �� �����̴�.

������ ���°� �־����� ��, �ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù ��° �ٿ��� ������ ����, ���� ũ�⸦ �ǹ��ϴ� �� ���� N, M (3 �� N, M �� 10)�� �־�����. ���� N���� �ٿ� ������ ����� ��Ÿ���� ���� M�� ���ڿ��� �־�����. 

�� ���ڿ��� '.', '#', 'O', 'R', 'B' �� �̷���� �ִ�. '.'�� �� ĭ�� �ǹ��ϰ�, '#'�� ���� �̵��� �� ���� ��ֹ� �Ǵ� ���� �ǹ��ϸ�, 'O'�� ������ ��ġ�� �ǹ��Ѵ�. 'R'�� ���� ������ ��ġ, 'B'�� �Ķ� ������ ��ġ�̴�.

�ԷµǴ� ��� ������ �����ڸ����� ��� '#'�� �ִ�. ������ ������ �� �� �̸�, ���� ������ �Ķ� ������ �׻� 1���� �־�����.



���
�ּ� �� �� ���� ���� ������ ������ ���� ���� �� �ִ��� ����Ѵ�. ����, 10�� ���Ϸ� �������� ���� ������ ������ ���� ���� �� ������ -1�� ����Ѵ�.



���� �Է� 1
5 5
#####
#..B#
#.#.#
#RO.#
#####

���� ��� 1
1



���� �Է� 2
7 7
#######
#...RB#
#.#####
#.....#
#####.#
#O....#
#######

���� ��� 2
5



���� �Է� 3
7 7
#######
#..R#B#
#.#####
#.....#
#####.#
#O....#
#######

���� ��� 3
5



���� �Է� 4
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.#.#..#
#...#.O#.#
##########

���� ��� 4
-1



���� �Է� 5
3 7
#######
#R.O.B#
#######

���� ��� 5
1



���� �Է� 6
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.##...#
#O..#....#
##########

���� ��� 6
7



���� �Է� 7
3 10
##########
#.O....RB#
##########

���� ��� 7
-1

*/


#include <iostream>
#include <string>
#include <queue>

enum e_Maze
{
	ROAD = 0,
	WALL = 1,
	REDBALL = 2,
	BLUEBALL = 3,
	HOLE = 4
};


typedef struct tagPoint
{
	int redX;
	int redY;
	int blueX;
	int blueY;
} POINT;


int maze[11][11];

int N, M;

std::string buffer;

bool visited[11][11][11][11];

constexpr int deltaY[] = { -1, 1, 0, 0 };
constexpr int deltaX[] = { 0, 0, -1, 1 };

int BFS(POINT spot)
{
	int cnt = 0;
	std::queue<POINT> q;
	q.push(spot);


	while (!q.empty()) 
	{
		int size = q.size();

		for (int i = 0; i < size; i++) 
		{
			int rx = q.front().redX;
			int ry = q.front().redY;
			int bx = q.front().blueX;
			int by = q.front().blueY;
			q.pop();

			if (maze[ry][rx] == HOLE && maze[by][bx] != maze[ry][rx]) 
				return cnt;
			
			for (int j = 0; j < 4; j++) {

				int rxt = rx;
				int ryt = ry; 
				int bxt = bx; 
				int byt = by;

				while (maze[ryt + deltaY[j]][rxt + deltaX[j]] != WALL && maze[ryt][rxt] != HOLE)
				{
					rxt += deltaX[j]; 
					ryt += deltaY[j];
				}

				while (maze[byt + deltaY[j]][bxt + deltaX[j]] != WALL && maze[byt][bxt] != HOLE) 
				{
					bxt += deltaX[j]; 
					byt += deltaY[j];
				}

				if (bxt == rxt && byt == ryt) 
				{
					
					if (maze[ryt][rxt] == HOLE) 
						continue;
					
					if (abs(rxt - rx) + abs(ryt - ry) > abs(byt - by) + abs(bxt - bx)) 
					{
						ryt -= deltaY[j]; 
						rxt -= deltaX[j];
					}
					else {
						bxt -= deltaX[j]; 
						byt -= deltaY[j];
					}

				}
				
				if (visited[rxt][ryt][bxt][byt])
					continue;
				
				q.push(POINT{rxt,ryt,bxt,byt});
				
				visited[rxt][ryt][bxt][byt] = 1;
			}

		}
		
		if (cnt == 10) 
			return -1;
		
		cnt++;
	}
	return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	std::cin >> N >> M;

	std::cin.ignore();

	POINT start = { 0 };

	for (int i = 0; i < N; i++)
	{
		std::cin >> buffer;
		for (int j = 0; j < M; j++)
		{
			char c = buffer.c_str()[j];
			if (c == '#')
				maze[i][j] = WALL;
			else if (c == '.')
				maze[i][j] = ROAD;
			else if (c == 'R')
			{
				maze[i][j] = REDBALL;
				start.redX = j;
				start.redY = i;
			}
			else if (c == 'B')
			{
				maze[i][j] = BLUEBALL;
				start.blueX = j;
				start.blueY = i;
			}
			else if (c == 'O')
				maze[i][j] = HOLE;
		}
	}

	std::cout << BFS(start);



	return 0;
}

