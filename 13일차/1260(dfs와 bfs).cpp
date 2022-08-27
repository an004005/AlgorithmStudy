#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

int N, M, V;
bool visit[1001]{};
bool graph[1001][1001]{};


void dfs(int v)
{
	visit[v] = true;
	printf("%d ", v);

	for (int i = 1; i <= N; ++i)
	{
		if (!graph[v][i]) continue;
		if (visit[i]) continue;
		dfs(i);
	}
}

void bfs(int v)
{
	queue<int> Q;
	Q.push(v);
	visit[v] = true;

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		printf("%d ", cur);

		for (int i = 1; i <= N; ++i)
		{
			if (!graph[cur][i]) continue;
			if (visit[i]) continue;
			visit[i] = true;
			Q.push(i);
		}
	}
}

int main()
{
	cin >> N >> M >> V;

	int a, b;
	for (int i = 1; i <= M; ++i)
	{
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}

	dfs(V);
	cout << endl;

	memset(visit, 0, sizeof(visit));
	bfs(V);
	cout << endl;

	return 0;
}