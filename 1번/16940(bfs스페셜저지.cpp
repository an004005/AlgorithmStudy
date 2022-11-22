#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int N;
vector<unordered_set<int>> graph;
bool visit[100001]{};
int order[100000];

int main()
{
	cin >> N;
	graph.resize(N + 1);

	int u, v;
	for (int i = 0; i < N - 1; ++i)
	{
		scanf("%d %d", &u, &v);
		graph[u].insert(v);
		graph[v].insert(u);
	}

	for (int i = 0; i < N; ++i)
		cin >> order[i];
		// scanf("%d", order[i]);

	queue<int> Q;
	Q.push(1);
	visit[1] = true;

	int orderIdx = 1;

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();

		while(true)
		{
			if (graph[cur].find(order[orderIdx]) == graph[cur].end())
				break;
			if (visit[order[orderIdx]])
				break;

			visit[order[orderIdx]] = true;
			Q.push(order[orderIdx]);
			++orderIdx;
		}
	}


	for (int i = 1; i <= N; ++i)
	{
		if (visit[i] == false)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	cout << 1 << endl;

	return 0;
}