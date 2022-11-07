#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dy[4]{0,0,1,-1};
int dx[4]{1,-1,0,0};

int N, M;
char board[20][20];
struct Coin
{
	int y[2];
	int x[2];
};

bool CheckDrop(int y, int x)
{
	return y < 0 || x < 0 || y >= N || x >= M;
}

bool IsWall(int y, int x)
{
	return board[y][x] == '#';
}

int main()
{
	cin >> N >> M;
	string tmp;

	Coin init;
	int coinCnt = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		for (int j = 0; j < M; ++j)
		{
			if (tmp[j] == 'o')
			{
				init.y[coinCnt] = i;
				init.x[coinCnt] = j;
				++coinCnt;
			}
			else
			{
				board[i][j] = tmp[j];
			}
		}
	}


	queue<pair<int, Coin>> Q; // cnt, coin
	Q.push({0, init});

	while (!Q.empty())
	{
		Coin cur = Q.front().second;
		const int cnt = Q.front().first;
		Q.pop();

		if (cnt >= 10)
			continue;

		for (int i = 0; i < 4; ++i)
		{
			Coin next;
			next.y[0] = cur.y[0] + dy[i];
			next.x[0] = cur.x[0] + dx[i];

			next.y[1] = cur.y[1] + dy[i];
			next.x[1] = cur.x[1] + dx[i];

			bool bDrop0 = CheckDrop(next.y[0], next.x[0]);
			if (bDrop0 == false && IsWall(next.y[0], next.x[0])) // not drop and can not move
			{
				next.y[0] = cur.y[0];
				next.x[0] = cur.x[0];
			}

			bool bDrop1 = CheckDrop(next.y[1], next.x[1]);
			if (bDrop1 == false && IsWall(next.y[1], next.x[1])) // not drop and can not move roll back
			{
				next.y[1] = cur.y[1];
				next.x[1] = cur.x[1];
			}

			if (bDrop0 && bDrop1)
				continue;
			if (bDrop0 || bDrop1)
			{
				cout << cnt + 1 << endl;
				return 0;
			}

			Q.push({cnt + 1, next});
		}
	}


	cout << -1 << endl;

	return 0;
}