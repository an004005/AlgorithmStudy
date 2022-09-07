#include <iostream>
#include <set>
#include <queue>
#include <array>
using namespace std;
using ballState = array<int, 4>; // red(y, x), blue(y, x)

int dy[4]{1, -1, 0, 0};
int dx[4]{0, 0, 1, -1};

char graph[10][10];
set<ballState> visit;
int N, M;

int moveBall(int d, ballState& state, bool bRed)
{
	if (bRed)
	{
		while (true) // red
		{
			int ny = state[0] + dy[d];
			int nx = state[1] + dx[d];
			if (graph[ny][nx] != '.')
			{
				if (graph[ny][nx] == 'O')
				{
					state[0] = -1;
					state[1] = -1;
					return 1;
				}
				break;
			}
			if (ny == state[2] && nx == state[3])
				break;
			state[0] = ny;
			state[1] = nx;
		}
	}
	else
	{
		while (true) // blue
		{
			int ny = state[2] + dy[d];
			int nx = state[3] + dx[d];
			if (graph[ny][nx] != '.')
			{
				if (graph[ny][nx] == 'O')
				{
					state[2] = -1;
					state[3] = -1;
					return 2;
				}
				break;
			}
			if (ny == state[0] && nx == state[1])
				break;
			state[2] = ny;
			state[3] = nx;
		}
	}
	return 0;
}

// 0: ok, 1 : red goal, 2 : blue goal
int moveBalls(int d, ballState& state)
{
	int red;
	int blue;
	if (d == 0) // up
	{
		if (state[2] > state[0]) // blue first
		{
			blue = moveBall(d, state, false);
			red = moveBall(d, state, true);
		}
		else // red first
		{
			red = moveBall(d, state, true);
			blue = moveBall(d, state, false);
		}
	}
	else if (d == 1) // down
	{
		if (state[2] < state[0]) // blue first
		{
			blue = moveBall(d, state, false);
			red = moveBall(d, state, true);
		}
		else // red first
		{
			red = moveBall(d, state, true);
			blue = moveBall(d, state, false);
		}
	}
	else if (d == 2) // right
	{
		if (state[3] > state[1]) // blue first
		{
			blue = moveBall(d, state, false);
			red = moveBall(d, state, true);
		}
		else // red first
		{
			red = moveBall(d, state, true);
			blue = moveBall(d, state, false);
		}
	}
	else if (d == 3) // left
	{
		if (state[3] < state[1]) // blue first
		{
			blue = moveBall(d, state, false);
			red = moveBall(d, state, true);
		}
		else // red first
		{
			red = moveBall(d, state, true);
			blue = moveBall(d, state, false);
		}
	}

	if (blue == 2)
		return 2;
	if (red == 1)
		return 1;

	return 0;
}

int main()
{
	ballState origin;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> graph[i];
		for (int j = 0; j < M; ++j)
		{
			if (graph[i][j] == 'R')
			{
				origin[0] = i;
				origin[1] = j;
				graph[i][j] = '.';
			}
			if (graph[i][j] == 'B')
			{
				origin[2] = i;
				origin[3] = j;
				graph[i][j] = '.';
			}
		}
	}

	priority_queue<pair<int, ballState>> Q;
	Q.push({0, origin});
	visit.insert(origin);

	while (Q.empty() == false)
	{
		int depth = -Q.top().first;
		ballState cur = Q.top().second;
		Q.pop();

		if (depth >= 10)
			continue;

		for (int i = 0; i < 4; ++i)
		{
			ballState ns = cur;
			int code = moveBalls(i, ns);

			//check ns state is goal or blue dead
			if (code == 0)
			{
				auto itr = visit.find(ns);
				if (itr == visit.end()) // not visit
				{
					visit.insert(ns);
					Q.push({-(depth + 1), ns});
				}
			}
			else if (code == 1)
			{
				cout << depth + 1 << endl;
				exit(0);
			}
		}
	}

	cout << -1 << endl;

	return 0;
}
