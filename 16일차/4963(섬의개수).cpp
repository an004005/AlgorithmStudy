#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dy[8]{ 0,0,1,-1, -1,-1,1, 1 };
int dx[8]{ 1,-1,0,0,  -1,1 ,-1,1 };

int w, h;
int map[50][50]; //h, w
bool visit[50][50];
int cnt = 0;

void dfs(int y, int x)
{
	visit[y][x] = true;
	for (int i = 0; i < 8; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= h || nx >= w)
			continue;
		if (map[ny][nx] == 0)
			continue;
		if (visit[ny][nx])
			continue;

		dfs(ny, nx);
	}
}

int main()
{
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
				scanf("%d", &map[i][j]);
		}
		memset(visit, 0, sizeof(visit));
		cnt = 0;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (map[i][j] == 1 && !visit[i][j])
				{
					++cnt;
					dfs(i, j);
				}
			}
		}

		cout << cnt << endl;
	}


	return 0;
}