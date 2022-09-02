#include <iostream>
#include <queue>
#include <cstring>
#define   MAX 301

using namespace std;

int n, m;
int dist[MAX][MAX] = { 0 };
bool dist[MAX][MAX];
int moveWidth[4] = { -1, -2, 1, 2 };
int moveUp[4] = { 2, 1, 2, 1 };
int moveDown[4] = { -2, -1, -2, -1 };
int endx, endy;

void bfs(int start_x, int start_y)
{
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	dist[start_x][start_y] = true;
	dist[start_x][start_y] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + moveWidth[i];
			int nyu = y + moveUp[i];
			int nyd = y + moveDown[i];

			if (nx >= 0 && nx < m && nyu >= 0 && nyu < m)
			{
				if (dist[nx][nyu])
				{
					if (dist[nx][nyu] > dist[x][y] + 1)
					{
						q.push({ nx, nyu });
						dist[nx][nyu] = dist[x][y] + 1;
					}
				}
				else
				{
					q.push({ nx, nyu });
					dist[nx][nyu] = true;
					dist[nx][nyu] = dist[x][y] + 1;
				}
			}

			if (nx >= 0 && nx < m && nyd >= 0 && nyd < m)
			{
				if (dist[nx][nyd])
				{
					if (dist[nx][nyd] > dist[x][y] + 1)
					{
						q.push({ nx, nyd });
						dist[nx][nyd] = dist[x][y] + 1;
					}
				}
				else
				{
					q.push({ nx, nyd });
					dist[nx][nyd] = true;
					dist[nx][nyd] = dist[x][y] + 1;
				}
			}
		}
	}

}

int main(void)
{
	cin >> n;

	int startx, starty;

	while (n--)
	{
		memset(dist, 0, sizeof(dist));
		memset(dist, 0, sizeof(dist));

		cin >> m;
		cin >> startx >> starty;
		cin >> endx >> endy;

		bfs(startx, starty);

		cout << dist[endx][endy] << '\n';
	}

	return 0;
}