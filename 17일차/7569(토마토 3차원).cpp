#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int dy[6]{1, -1, 0, 0, 0, 0};
int dx[6]{0, 0, 1, -1, 0, 0};
int dz[6]{0, 0, 0, 0, 1, -1};

int M, N, H; // 가로, 세로, 높이
int map[100][100][100]{}; // 높이, 세로, 가로
bool visit[100][100][100]{};
// 1 : 익은, 0 : 안익은, -1 : 없는
int main()
{
	cin >> M >> N >> H;

	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
				scanf("%d", &map[k][i][j]);
		}
	}

	priority_queue<pair<int, pair<int, pair<int, int>>>> Q; // day, z, y, x

	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (map[k][i][j] == 1)
				{
					Q.push({0, {k, {i, j}}});
					visit[k][i][j] = true;
				}
			}
		}
	}

	int minDay = 0;
	while (Q.empty() == false)
	{
		int curDay = -Q.top().first;
		int z = Q.top().second.first;
		int y = Q.top().second.second.first;
		int x = Q.top().second.second.second;
		Q.pop();

		if (curDay > minDay)
			minDay = curDay;

		for (int i = 0; i < 6; ++i)
		{
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M)
				continue;
			if (visit[nz][ny][nx])
				continue;
			if (map[nz][ny][nx] == 1 || map[nz][ny][nx] == -1)
				continue;

			visit[nz][ny][nx] = true;
			Q.push({-(curDay + 1), {nz, {ny, nx}}});
		}
	}

	
	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (visit[k][i][j] == false && map[k][i][j] == 0)
				{
					cout << - 1<<endl;
					exit(0);
				}
			}
		}
	}

	cout << minDay << endl;


	return 0;
}
