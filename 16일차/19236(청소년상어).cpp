#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>

using namespace std;

struct Fish
{
	int idx;
	int dir;
	Fish() {}
	Fish(int idx, int dir) :idx(idx), dir(dir) {}
};

struct Shark
{
	int y = 0;
	int x = 0;
	int sum = 0;
	int dir = 0;
	
};

int dy[8]{-1, -1, 0, 1, 1, 1,0, -1 };
int dx[8]{0, -1, -1, -1, 0, 1, 1,1 };

constexpr int N = 4;
int maxSum = 0;

void dfs(Shark shark, Fish map[4][4])
{
	// move fish
	int fishIdx = 1;
	while (fishIdx <= 16)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (map[i][j].idx == fishIdx)
				{
					while (true)
					{
						int ny = i + dy[map[i][j].dir];
						int nx = j + dx[map[i][j].dir];
						if (ny < 0 || nx < 0 || ny >= N || nx >= N)
						{
							map[i][j].dir = (map[i][j].dir + 1) % 8;
							continue;
						}
						if (shark.y == ny && shark.x == nx)
						{
							map[i][j].dir = (map[i][j].dir + 1) % 8;
							continue;
						}

						Fish tmp;
						tmp = map[i][j];
						map[i][j] = map[ny][nx];
						map[ny][nx] = tmp;
						goto BreakLoop;
					}
				}
			}
		}

		BreakLoop:
		++fishIdx;
	}

	// shark move
	list<pair<int, int>> canEatfishList;
	while (true)
	{
		shark.y += dy[shark.dir];
		shark.x += dx[shark.dir];
		if (shark.y < 0 || shark.x < 0 || shark.y >= N || shark.x >= N)
			break;
		if (map[shark.y][shark.x].idx == 0)
			continue;

		canEatfishList.push_back({ shark.y, shark.x });
	}

	if (canEatfishList.empty())
	{
		if (maxSum < shark.sum)
			maxSum = shark.sum;
		return;
	}
	else
	{
		for (auto& pos : canEatfishList)
		{
			Fish copy[4][4];
			for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
				copy[i][j] = map[i][j];
			Shark copyShark = shark;
			copyShark.y = pos.first;
			copyShark.x = pos.second;

			copyShark.dir = copy[copyShark.y][copyShark.x].dir;
			copyShark.sum += copy[copyShark.y][copyShark.x].idx;
			copy[copyShark.y][copyShark.x].idx = 0;

			dfs(copyShark, copy);
		}
	}
}

int main()
{
	Fish origin[4][4];
	int idx, dir;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> idx >> dir; // 1 <= dir <= 8 change to  0~7
			origin[i][j] = { idx, dir - 1 };
		}
	}

	Shark shark;
	shark.dir = origin[0][0].dir;
	shark.sum += origin[0][0].idx;
	origin[0][0].idx = 0; // 0 mean empty

	dfs(shark, origin);

	cout << maxSum << endl;
	return 0;
}