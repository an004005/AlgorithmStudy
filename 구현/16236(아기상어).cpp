#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include<utility>
#include <list>
#include <cstring>
#include <algorithm>
using namespace std;

int dy[4]{ -1,0,0,1 }; // À§, ¿Þ, ¿À, ¾Æ·¡
int dx[4]{ 0,-1,1,0 };

int N;
int map[20][20]{};
int ssize = 2;
int eat = 0;
int time = 0;
pair<int, int> cur;

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				cur.first = i;
				cur.second = j;
			}
		}
	}


	vector<pair<int, int>> edibleList;
	edibleList.reserve(20);
	bool visit[20][20]{};
	int stopTime = -1;

	while (true)
	{
		// find edible fish
		queue<pair<int, pair<int, int>>> Q; // move, y, x
		Q.push({ time, cur });
		
		memset(visit, 0, sizeof(visit));
		visit[cur.first][cur.second] = true;

		edibleList.clear();
		stopTime = -1;

		while (!Q.empty())
		{
			cur = Q.front().second;
			int curTime = Q.front().first;
			Q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int ny = cur.first + dy[i];
				int nx = cur.second + dx[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (visit[ny][nx])
					continue;
				if (map[ny][nx] != 0 && map[ny][nx] > ssize)
					continue;

				if (stopTime == -1)
				{
					if (map[ny][nx] != 0 && map[ny][nx] < ssize)
					{
						stopTime = curTime + 1;
						edibleList.push_back({ ny, nx });
						continue;
					}
				}
				else if (stopTime == curTime + 1)
				{
					if (map[ny][nx] != 0 && map[ny][nx] < ssize)
					{
						edibleList.push_back({ ny, nx });
						continue;
					}
				}

				visit[ny][nx] = true;
				Q.push({ curTime + 1, { ny, nx } });
			}
		}

		if (!edibleList.empty())
		{
			time = stopTime;
			sort(edibleList.begin(), edibleList.end());
			cur = edibleList.front();

			++eat;
			if (eat == ssize)
			{
				eat = 0;
				++ssize;
			}
			map[cur.first][cur.second] = 0;

		}
		else
		{
			break;
		}
	}

	cout << time << endl;

	return 0;
}