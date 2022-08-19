#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

constexpr int R = 10;
constexpr int C = 10;

// 0 : down, 1 : up, 2 : right, 3 : left
constexpr int di[4]{ 1,-1,0,0 };
constexpr int dx[4]{ 0,0,1,-1 };

using Pair = pair<float, pair<int, int>>; //f, y, x

struct Node
{
	int fromY, fronX;
	float f, g, h; // f = g + h
	Node() { f = 99999.f; g = 0.f; h = 0.f; }
};


int map[R][C] {
	{ 0,0,1,0,0,1,0,0,0,0 },
	{ 0,0,1,0,1,1,0,0,0,0 },
	{ 0,0,1,0,0,1,0,0,0,0 },
	{ 0,0,1,1,0,1,0,1,1,1 },
	{ 0,0,0,0,0,1,0,0,0,0 },
	{ 0,1,1,1,1,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,1,0 },
	{ 0,0,0,0,0,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 }
};

float heuristic(int y, int x, int destY, int destX)
{
	return sqrtf((destY - y) * (destY - y) + (destX - x) * (destX - x));
}


void AStar()
{
	Node starMap[R][C];
	bool closed[R][C]{};
	priority_queue<Pair> Q; // open list

	int sy = 0;
	int sx = 0;

	int desty = 0;
	int destx = 9;

	starMap[sy][sx].f = heuristic(sy, sx, desty, destx);
	closed[sy][sx] = true;
	Q.push({ -starMap[sy][sx].f, {sy,sx} });

	while (!Q.empty())
	{
		Pair cur = Q.top();
		Q.pop();
		float f = -cur.first;
		int y = cur.second.first;
		int x = cur.second.second;
		Node& curNode = starMap[y][x];

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + di[i];
			int nx = x + dx[i];
			if (ny == desty && nx == destx)
			{
				while (true)
				{
					if (y == sy && x == sx)
						break;
					map[y][x] = 9;
					Node& n = starMap[y][x];
					y = n.fromY;
					x = n.fronX;
				}

				for (int i = 0; i < R; ++i)
				{
					for (int j = 0; j < C; ++j)
					{
						cout << map[i][j];
					}
					cout << endl;
				}

				return;
			}

			if (ny < 0 || nx < 0 || ny >= R || nx >= C)
				continue;
			if (map[ny][nx] == 1)
				continue;
			if (closed[ny][nx])
				continue;

			closed[ny][nx] = true;
			Node& nNode = starMap[ny][nx];
			nNode.fromY = y;
			nNode.fronX = x;
			nNode.g = curNode.g + 1;
			nNode.h = heuristic(ny, nx, desty, destx);
			nNode.f = nNode.g * nNode.h;
			Q.push({ -nNode.f, {ny, nx} });

			//int nf, ng, nh;
			//ng = curNode.g + 1;
			//nh = heuristic(ny, nx, desty, destx);
			//nf = ng + nh;

			//Node& nNode = starMap[ny][nx];
			//if (nNode.f > nf)
			//{
			//	nNode.fromY = y;
			//	nNode.fronX = x;
			//	nNode.g = ng;
			//	nNode.h = nh;
			//	nNode.f = nf;
			//	Q.push({ -nNode.f, {ny, nx} });
			//}
		}
	}
}

int main()
{
	AStar();



	return 0;
}