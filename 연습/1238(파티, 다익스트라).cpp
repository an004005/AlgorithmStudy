#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>
using namespace std;

int N, M, X;

vector<vector<pair<int, int>>> map; // to, cost
int maxDist = 0;
int dist[1001];
bool visit[1001];

int roundCost[1001]{};

int getSmallIndex()
{
	int curMin = std::numeric_limits<int>::max();
	int index = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (visit[i] == false && dist[i] < curMin)
		{
			curMin = dist[i];
			index = i;
		}
	}

	return index;
}


void dijkstra(int start)
{
	for (int i = 1; i <= N; ++i)
	{
		dist[i] = std::numeric_limits<int>::max();
		visit[i] = false;
	}

	dist[start] = 0;
	visit[start] = true;
	for (auto& e : map[start])
		dist[e.first] = e.second;


	while (true)
	{
		int cur = getSmallIndex();
		if (cur == 0)
			break;

		visit[cur] = true;

		for (auto& e : map[cur])
		{
			int to = e.first;
			int cost = e.second; // cur에서 to로 가는 비용

			if (visit[to] == false)
			{
				if (dist[to] > cost + dist[cur])
					dist[to] = cost + dist[cur]; // cur를 거쳐가는게 더 빠르면
			}
		}
	}

	if (start == X)
	{
		for (int i = 1; i <= N; ++i)
			roundCost[i] += dist[i];
	}
	else
		roundCost[start] += dist[X];
}

int main()
{
	cin >> N >> M >> X;
	map.resize(N + 1);

	int from, to, cost;
	for (int i = 1; i <= M; ++i)
	{
		cin >> from >> to >> cost;
		map[from].push_back({ to, cost });
	}

	for (int i = 1; i <= N; ++i)
		dijkstra(i);

	for (int i = 1; i <= N; ++i)
		maxDist = std::max(maxDist, roundCost[i]);
	
	cout << maxDist << endl;
	return 0;
}