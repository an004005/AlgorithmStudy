#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int A, B; // 가로 , 세로
int N, M; // 로봇개수, 명령 개수

int dy[4]{1,0,-1,0}; // N, E, S,W
int dx[4]{0,1,0,-1};


struct Robot
{
	int y;
	int x;
	int d;
};
Robot robots[101]; // 1~100
int land[101][101]{}; // 0 : empty, 1~100 : robot index

struct Command
{
	int idx;
	char order;
	int repeat;
};

int main()
{
	cin >> A >> B;
	cin >> N >> M;

	char dir;
	for (int i = 1; i <= N; ++i)
	{
		cin >> robots[i].x >> robots[i].y;
		cin >> dir;
		switch (dir)
		{
		case 'N':
			robots[i].d = 0;
			break;
		case 'E':
			robots[i].d = 1;
			break;
		case 'S':
			robots[i].d = 2;
			break;
		case 'W':
			robots[i].d = 3;
			break;
		}

		land[robots[i].y][robots[i].x] = i;
	}

	vector<Command> vecCommand;
	vecCommand.reserve(100);

	Command tmp;
	for (int i = 0; i < M; ++i)
	{
		cin >> tmp.idx >> tmp.order >> tmp.repeat;
		vecCommand.push_back(tmp);
	}

	for (int j = 0; j < M; ++j)
	{
		int idx = vecCommand[j].idx;
		char order = vecCommand[j].order;
		int repeat = vecCommand[j].repeat;

		switch (order)
		{
		case 'L': // 4번 회전 : 원점
			robots[idx].d = ((robots[idx].d - repeat) % 4 + 4) % 4;
			break;
		case 'R':
			robots[idx].d = (robots[idx].d + repeat) % 4;
			break;
		case 'F':
			for (int i = 0; i < repeat; ++i)
			{
				int ny = robots[idx].y + dy[robots[idx].d];
				int nx = robots[idx].x + dx[robots[idx].d];
				if (ny <= 0 || nx <= 0 || ny > B || nx > A)
				{
					printf("Robot %d crashes into the wall\n", idx);
					exit(0);
				}

				if (land[ny][nx])
				{
					printf("Robot %d crashes into robot %d\n", idx, land[ny][nx]);
					exit(0);
				}

				land[robots[idx].y][robots[idx].x] = 0;
				robots[idx].y = ny;
				robots[idx].x = nx;
				land[robots[idx].y][robots[idx].x] = idx;
			}
			break;
		}
	}


	cout << "OK" << endl;

	return 0;
}