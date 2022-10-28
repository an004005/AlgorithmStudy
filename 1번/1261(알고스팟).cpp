#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int M, N;//가로 세로
int maze[101][101]{}; // 1,1 ~ 100, 100
bool visit[101][101]{};

int dx[4]{0,0,1,-1};
int dy[4]{1,-1,0,0};

int main()
{
	cin >> M >> N;
	for (int i = 1; i <= N; ++i)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; ++j)
		{
			if (tmp[j] == '1')
				maze[i][j + 1] = 1;
		}
	}

	priority_queue<pair<int, pair<int, int>>> Q;//부순 벽 개수, 현 위치(y, x)
	Q.push({0, {1,1}});

	while (!Q.empty())
	{
		int curWall = -Q.top().first;
		int y = Q.top().second.first;
		int x = Q.top().second.second;
		Q.pop();

		if (y == N && x == M)
		{
			cout << curWall<<endl;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 1 || nx < 1 || ny > N || nx > M)
				continue;
			if (visit[ny][nx])
				continue;
			visit[ny][nx] = true;
			int nWall = maze[ny][nx] == 1 ? curWall + 1 : curWall;
			Q.push({-nWall, {ny, nx}});
		}
	}

	return 0;
}