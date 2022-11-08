#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

constexpr int _INF_ = std::numeric_limits<int>::max();

int V, E;
int S;

vector<vector<pair<int, int>>> graph; // from, to, cost
vector<int> dist;


int main()
{
	cin >> V >> E;
	cin >> S;
	graph.resize(V + 1);
	dist.resize(V + 1, _INF_);// fill inf

	int u, v, w;
	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({v, w}); // 1 <= w <= 10
	}

	dist[S] = 0;

	priority_queue<pair<int, int>> Q; // cost, from
	Q.push({0, S});

	while (!Q.empty())
	{
		int cost = -Q.top().first;
		int from = Q.top().second;
		Q.pop();

		for (auto& e : graph[from])
		{
			int to = e.first;
			int toCost = e.second;

			if (dist[to] > cost + toCost)
			{
				dist[to] = cost + toCost;
				Q.push({-dist[to], to});
			}
		}
	}

	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == _INF_)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}