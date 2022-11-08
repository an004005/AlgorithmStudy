#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int dy[4]{0, 0, 1, -1};
int dx[4]{1, -1, 0, 0};

int N, M;
int map[500][500]{};
int dp[500][500]{};

int dfs(int y, int x)
{
	if (y == N - 1 && x == M - 1) // 오른쪽 아래 도착
		return 1;

	int tmp = 0;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
			continue;
		if (map[y][x] <= map[ny][nx]) // 오르막 제거
			continue;

		if (dp[ny][nx] > -1)
			tmp += dp[ny][nx];
		else
			tmp += dfs(ny, nx);
	}

	dp[y][x] = tmp;
	return tmp;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;		
		}
	}

	cout << dfs(0,0) << endl;

	return 0;
}




// dp의 값이 0 이 될 수 있는 경우 고려못했음
// 될 수 없는값인 -1로 초기화하여 수정완료