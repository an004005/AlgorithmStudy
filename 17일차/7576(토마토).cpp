#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int dy[4]{0, 0, 1, -1};
int dx[4]{1, -1, 0, 0};

int M, N;
int map[1000][1000]{};
bool visit[1000][1000]{};
// 1 : 익은, -1 없는, 0 : 안익은

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> map[i][j];
	}

	priority_queue<pair<int, pair<int, int>>> Q; // day, y, x

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == 1)
			{
				Q.push({0, {i, j}});
				visit[i][j] = true;
			}
		}
	}

	int maxDay = 0;

	while (Q.empty() == false)
	{
		int curDay = -Q.top().first;
		int y = Q.top().second.first;
		int x = Q.top().second.second;
		Q.pop();


		if (curDay > maxDay)
			maxDay = curDay;

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= M || nx >= N)
				continue;
			if (map[ny][nx] == 1 || map[ny][nx] == -1)
				continue;
			if (visit[ny][nx])
				continue;

			visit[ny][nx] = true;
			Q.push({-(curDay + 1), {ny, nx}});
		}
	}


	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] != -1 && visit[i][j] == 0)
			{
				cout << -1 << endl;
				exit(0);
			}
		}
	}

	cout << maxDay << endl;

	return 0;
}
