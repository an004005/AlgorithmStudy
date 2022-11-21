#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <array>
using namespace std;
// À§¿Þ, À§¿À, ¿À, ¾Æ·¡¿À, ¾Æ·¡¿Þ, ¿Þ
int dy[6]{-1,-1, 0, 1, 1, 0};
int dx[6]{0, 1,  1, 0, -1, -1};

int N;
bool graph[50][50]{};
int color[50][50]{};
bool visit[50][50]{};

void bfs(int i, int j)
{
	queue<pair<int, int>> Q;
	Q.push({i, j});
	visit[i][j] = true;

	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		array<pair<int, int>, 6> nearCood{};
		array<bool, 6> near{false,false,false,false,false,false};
		int nearCnt = 0;

		for (int d = 0; d < 6; ++d)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (graph[ny][nx] == false)
				continue;

			near[d] = true;
			++nearCnt;
			nearCood[d] = {ny, nx};

			if (visit[ny][nx])
				continue;

			visit[ny][nx] = true;
			Q.push({ny, nx});
		}

		array<bool, 4> colors{false, false, false, false};
		for (int d = 0; d < 6; ++d)
		{
			if (near[d])
				colors[color[nearCood[d].first][nearCood[d].second]] = true;
		}

		for (int d = 1; d < 4; ++d)
		{
			if (colors[d] == false)
			{
				color[y][x] = d;
				break;
			}
		}

	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string tmp;
		cin >>tmp;
		for (int j = 0; j < N; ++j)
		{
			if (tmp[j] == 'X')
				graph[i][j] = true;
		}
	}


	for (int i = 0; i <	N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (graph[i][j] && !visit[i][j])
				bfs(i, j);
		}
	}

	int answer = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			answer = max(color[i][j], answer);
		}
	}

	cout << answer << endl;

	return 0;
}