#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> dist;
bool visit[3001]{};
stack<int> S;
bool bRet = false;

void dfs(int cur, int pre)
{
	visit[cur] = true;
	S.push(cur);

	for (auto e : graph[cur])
	{
		if (bRet) return;

		if (e == pre)
			continue;

		if (visit[e] == false)
		{
			dfs(e, cur);
		}
		else
		{
			dist[e] = 0;
			while (S.top() != e)
			{
				dist[S.top()] = 0;
				S.pop();
			}
			bRet = true;
			return;
		}
	}

	if (bRet) return;

	visit[cur] = false;
	S.pop();
}

int main()
{
	cin >> N;
	graph.resize(N + 1);
	dist.resize(N + 1, -1);

	int a, b;
	for (int i = 1; i <= N; ++i)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0);


	for (int i = 1; i <= N; ++i)
	{
		if (dist[i] == -1)
		{
			memset(visit, 0, sizeof(visit));
			queue<pair<int, int>> Q; // dist, V
			Q.push({0, i});
			visit[i] = true;

			while (Q.empty() == false)
			{
				int curDist = Q.front().first;
				int cur = Q.front().second;
				Q.pop();

				for (auto e : graph[cur])
				{
					if (dist[e] == 0) // fin
					{
						dist[i] = curDist + 1;
						goto LOOPOUT;
					}
					if (!visit[e])
					{
						visit[e] = true;
						Q.push({curDist + 1, e});
					}
				}
			}

			LOOPOUT:
			int a = 3;
		
		}
	}

	for (int i = 1; i <= N; ++i)
		printf("%d ", dist[i]);
	cout << endl;


	return 0;
}
