#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dy[4]{0, 0, 1, -1};
int dx[4]{1, -1, 0, 0};

int N, M;
int board[50][50]{};
bool visit[50][50]{};
int dp[50][50]{};

int dfs(int y, int x)
{
	int tmpDp = 1;

	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i] * board[y][x];
		int nx = x + dx[i] * board[y][x];

		if (ny <0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (board[ny][nx] == 0)
			continue;
		if (visit[ny][nx])
		{
			cout << -1 << endl;
			exit(0);
		}

		visit[y][x] = true;
		if (dp[ny][nx])
			tmpDp = std::max(dp[ny][nx] + 1, tmpDp);
		else
			tmpDp = std::max(dfs(ny, nx) + 1, tmpDp);
		visit[y][x] = false;
	}

	dp[y][x] = tmpDp;

	return tmpDp;
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
			if (tmp[j] == 'H')
			{
				board[i][j] = 0;
			}
			else
			{
				board[i][j] = tmp[j] - 48;
			}
		}
	}

	visit[0][0] = true;
	cout << dfs(0,0)<<endl;


	return 0;
}
