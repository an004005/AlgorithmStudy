#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dp[101];
bool visit[101]{};
int ladder, snake;

int main()
{
	for (int i = 1; i <= 100; ++i)
		dp[i] = i;
	cin >> ladder >> snake;
	int total = ladder + snake;
	int from, to;
	while (total--)
	{
		cin >> from >> to;
		dp[from] = to;
	}

	priority_queue<pair<int, int>> Q; // roll cnt, cur
	Q.push({0, 1});
	visit[1] = true;

	while (!Q.empty())
	{
		int cnt = -Q.top().first;
		int loc = Q.top().second;
		Q.pop();

		if (loc == 100)
		{
			cout << cnt << endl;
			break;
		}

		for (int i = 1; i <= 6; ++i)
		{
			int next = loc + i;

			if (next > 100|| visit[next])
				continue;
			visit[next] = true;

			int moved = dp[next];
			if (moved != next)
			{
				next = moved;
				if (visit[next])
					continue;
				visit[next] = true;	
			}

			Q.push({-(cnt + 1), next});
		}
	}


	return 0;
}
