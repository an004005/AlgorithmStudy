#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<utility>
using namespace std;

int dy[4]{ 0,1,0,-1 };
int dx[4]{ 1,0,-1,0 }; // ¿À, ¾Æ·¡, ¿Þ, À§

int N, K, L;
bool map[101][101]{};

pair<int, char> commands[100];


int main()
{
	cin >> N >> K;
	int y, x;
	for (int i = 0; i < K; ++i)
	{
		cin >> y >> x;
		map[y][x] = true;
	}

	cin >> L;
	int time;
	char command;
	for (int i = 0; i < L; ++i)
	{
		cin >> time >> command;
		commands[i] = pair<int, char>{ time, command };
	}

	int curTime = 0;
	int dir = 0;
	int cury = 1;
	int curx = 1;
	int commandIdx = 0;
	vector<pair<int, int>> body;

	while (true)
	{
		++curTime;

		int ny = cury + dy[dir];
		int nx = curx + dx[dir];

		if (ny <= 0 || nx <= 0 || ny > N || nx > N) // check wall
			goto gotoEnd;

		// check body
		for (auto& b : body)
		{
			if (b.first == ny && b.second == nx)
				goto gotoEnd;
		}

		if (map[ny][nx]) //apple
		{
			body.push_back({ cury, curx });
			map[ny][nx] = false;
		}
		else
		{
			for (int i = 0; i < body.size(); ++i)
			{
				if (i == body.size() - 1)
					body.back() = { cury, curx };
				else
					body[i] = body[i + 1];
			}
		}

		// reposition
		cury = ny;
		curx = nx;

		// command
		if (commandIdx < L && commands[commandIdx].first == curTime)
		{
			if (commands[commandIdx].second == 'D')
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;
			++commandIdx;
		}
	}

gotoEnd:
	cout << curTime << endl;

	return 0;
}