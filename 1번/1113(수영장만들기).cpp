#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

static constexpr int dy[4]{1, -1, 0, 0};
static constexpr int dx[4]{0, 0, 1, -1};

int N, M;
int pool[50][50]{};
bool visit[50][50]{};
int maxHeight = 0;

int water = 0;

void bfs(int h, int i, int j)
{
	queue<pair<int, int>> Q;
	Q.push({i, j});
	int cnt = 1;
	bool bOverflow = false;
	visit[i][j] = true;

	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			{
				bOverflow = true;
				continue;
			}
			if (visit[ny][nx])
				continue;
			if (pool[ny][nx] > h)
				continue;

			visit[ny][nx] = true;
			++cnt;
			Q.push({ny, nx});
		}
	}

	if (bOverflow == false)
	{
		water += cnt;
	}
}

int main()
{
	cin >> N >> M;

	string tmp;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		for (int j = 0; j < M; ++j)
		{
			pool[i][j] = tmp[j] - 48;
			maxHeight = std::max(pool[i][j], maxHeight);
		}
	}

	for (int h = 1; h <= maxHeight; ++h)
	{
		memset(visit, 0, sizeof (visit));

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (pool[i][j] > h) continue;

				if (visit[i][j] == false)
				{
					bfs(h, i, j);
				}
			}
		}
	}

	cout << water << endl;

	return 0;
}
