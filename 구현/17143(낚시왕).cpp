#include <iostream>
#include <vector>
#include <list>
using namespace std;

enum DIR
{
	UP = 1,
	DOWN,
	RIGHT,
	LEFT
};

struct shark
{
	int s; // 속도
	DIR d; // 방향
	int z; // 크기
	bool bMoved = false;
	shark(int s, DIR d, int z) : s(s), d(d), z(z) {}
	shark() {}
};

constexpr int di[5]{ 0, -1,1,0,0 };
constexpr int dx[5]{ 0, 0,0,1,-1 };

int R, C, M;
list<shark> map[101][101];
long long totalZ;
int fisher = 0;

void FishShark()
{
	for (int i = 1; i <= R; ++i)
	{
		if (map[i][fisher].size() > 0)
		{
			totalZ += map[i][fisher].back().z;
			map[i][fisher].pop_back();
			--M;
			return;
		}
	}
}

void MoveShark()
{
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (map[i][j].size() > 0)
			{
					shark sha = map[i][j].front();
					if (sha.bMoved) continue;

					map[i][j].pop_front();

					int moveCnt = (sha.d == UP || sha.d == DOWN) ? R : C;
					moveCnt = moveCnt * 2 - 2;
					int minMove = sha.s % moveCnt;

					int y = i;
					int x = j;

					while (minMove--)
					{
						int ny = y + di[sha.d];
						int nx = x + dx[sha.d];

						if (ny < 1 || nx < 1 || ny > R || nx > C)
						{
							switch (sha.d)
							{
							case UP:
								sha.d = DOWN;
								break;
							case DOWN:
								sha.d = UP;
								break;
							case RIGHT:
								sha.d = LEFT;
								break;
							case LEFT:
								sha.d = RIGHT;
								break;
							}
							ny = y + di[sha.d];
							nx = x + dx[sha.d];
						}

						y = ny;
						x = nx;
					}

					sha.bMoved = true;
					map[y][x].push_back(std::move(sha));
			}
		}
	}

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (map[i][j].size() == 1)
			{
				map[i][j].front().bMoved = false;
			}
			else if (map[i][j].size() > 1)
			{
				list<shark>& sharkList = map[i][j];
				shark Largest;
				Largest.z = 0;
				while (!sharkList.empty())
				{
					if (sharkList.front().z > Largest.z)
						Largest = sharkList.front();
					sharkList.pop_front();
					--M;
				}

				++M;
				Largest.bMoved = false;
				sharkList.push_back(std::move(Largest));
			}
		}
	}
}

//void print()
//{
//	for (int i = 1; i <= R; ++i)
//	{
//		for (int j = 1; j <= C; ++j)
//		{
//			if (map[i][j].size() > 0)
//			{
//				cout << "O";
//			}
//			else
//			{
//				cout << "X";
//			}
//		}
//		cout << endl;
//	}
//
//	cout << endl<<endl; 
//}

int main()
{
	cin >> R >> C >> M; // y, x ,상어수

	int r, c, s, d, z; // 상어 y, x,속력, 이동방향, 크기
	for (int i = 0; i < M; ++i)
	{
		cin >> r >> c >> s >> d >> z;	
		map[r][c].push_back({ s, DIR(d), z });
	}

	while (fisher < C && M > 0)
	{
		++fisher;
		FishShark();
		MoveShark();

	}


	cout << totalZ << endl;
	return 0;
}