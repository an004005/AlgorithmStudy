#include<iostream>
#include <queue>
using namespace std;

int N, M;
int H, W, Sr, Sc, Fr, Fc;
int map[1001][1001]{};
bool visit[1001][1001]{};

// 아래, 위, 왼쪽 ,오른쪽 이동
constexpr int dy[4]{ 1,-1,0,0 };
constexpr int dx[4]{ 0,0,-1,1 };

struct Info
{
	int dist;
	int y;
	int x;
	Info(int _y, int _x, int _dist) : y(_y), x(_x), dist(_dist) {}
};


bool checkOut(int dir, int y, int x)
{
	if (dir == 0) // 아래
	{
		int botY = y + H - 1;
		if (botY > N) return false;
		for (int i = 0; i < W; ++i)
		{
			if (map[botY][i + x] == 1)
				return false;
		}

	}
	else if (dir == 1)//위
	{
		if (y < 1) return false;
		for (int i = 0; i < W; ++i)
		{
			if (map[y][i + x] == 1)
				return false;
		}
	}
	else if (dir == 2)//왼쪽
	{
		if (x < 1) return false;
		for (int i = 0; i < H; ++i)
		{
			if (map[i + y][x] == 1)
				return false;
		}
	}
	else//오른쪽
	{
		int rightX = x + W - 1;
		if (rightX > M) return false;
		for (int i = 0; i < H; ++i)
		{
			if (map[i + y][rightX] == 1)
				return false;
		}
	}

	return true;
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
			cin >> map[i][j];
	}
	cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

	queue<Info> Q;
	Q.push({Sr, Sc, 0});
	visit[Sr][Sc] = true;

	while (!Q.empty())
	{
		Info cur = Q.front();
		Q.pop();

		if (cur.y == Fr && cur.x == Fc)
		{
			cout << cur.dist << endl;
			exit(0);
		}

		// 아래, 위, 왼쪽 ,오른쪽 이동
		for (int i = 0; i < 4; ++i)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			
			if (!checkOut(i, ny, nx))
				continue;
			if (visit[ny][nx])
				continue;

			visit[ny][nx] = true;
			Q.push({ ny, nx, cur.dist + 1 });
		}
	}

	cout << -1 << endl;


	return 0;
}