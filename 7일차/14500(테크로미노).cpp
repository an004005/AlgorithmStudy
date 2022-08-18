#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dy[4]{ -1,0,1,0 };
int dx[4]{ 0,1,0,-1 };

int N, M;
int map[500][500]{};
bool visit[500][500]{};
int sumMax = 0;
int sumStack = 0;

void dfs(int y, int x, int depth)
{
	if (depth == 0)
	{
		if (sumStack > sumMax)
			sumMax = sumStack;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;
		if (visit[ny][nx])
			continue;

		visit[ny][nx] = true;
		sumStack += map[ny][nx];
		dfs(ny, nx, depth - 1);
		sumStack -= map[ny][nx];
		visit[ny][nx] = false;

	}
}

void exceptBlock(int y, int x)
{
	for (int i = 0; i < 4; ++i)
	{
		int exceptSum = map[y][x];
		for (int j = 0; j < 3; ++j)
		{
			int ny = y + dy[(i + j) % 4];
			int nx = x + dx[(i + j) % 4];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				break;

			exceptSum += map[ny][nx];
		}

		if (exceptSum > sumMax)
			sumMax = exceptSum;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			scanf("%d", &map[i][j]);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			memset(visit, 0, sizeof(visit));
			visit[i][j] = true;
			sumStack += map[i][j];
			dfs(i, j, 3);
			sumStack -= map[i][j];
			exceptBlock(i, j);
			visit[i][j] = false;
		}
	}

	cout << sumMax << endl;

	return 0;
}