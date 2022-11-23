#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4]{0,0,1,-1};
int dx[4]{1,-1,0,0};

int N, M;
int map[1001][1001]{};
bool visit[1001][1001][2]{}; // y, x, break

int main()
{
	cin >> N >> M;
	char tmp[1001];
	for (int i = 1; i <= N; ++i)
	{
		scanf("%s", tmp);
		for (int j = 1; j <= M; ++j)
		{
			map[i][j] = tmp[j - 1] - '0';
		}
	}

	priority_queue<pair<int, pair<int, pair<int, int>>>> Q;
	Q.push({-1, {1,{1, 0}}});
	visit[1][1][0] = true;

	int minCost = -1;

	while (!Q.empty())
	{
		int cost = -Q.top().first;
		int y = Q.top().second.first;
		int x = Q.top().second.second.first;
		int iBreak= Q.top().second.second.second;
		Q.pop();

		if (y == N && x == M)
		{
			minCost = cost;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny <= 0 || nx <= 0 || ny > N || nx > M)
				continue;

			if (map[ny][nx] == 1)
			{
				if (iBreak == 0)
				{
					if (visit[ny][nx][1])
						continue;
					visit[ny][nx][1] = true;
					Q.push({-(cost + 1), {ny,{ nx, 1}}});
				}
			}
			else
			{
				if (visit[ny][nx][iBreak])
					continue;
				visit[ny][nx][iBreak] = true;
				Q.push({-(cost + 1), {ny, {nx, iBreak}}});
			}
		}
	}

	cout << minCost << endl;
	return 0;
}
