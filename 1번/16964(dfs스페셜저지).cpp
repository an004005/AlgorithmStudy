#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int N;
vector<unordered_set<int>> graph;
bool visit[100001];
int order[100000];
int orderIdx = 1;

void dfs(int cur)
{
	if (visit[cur])
		return;

	visit[cur] = true;

	while(true)
	{
		if (graph[cur].find(order[orderIdx]) == graph[cur].end())
			break;

		++orderIdx;
		dfs(order[orderIdx - 1]);
	}
}

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

	dfs(1);

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