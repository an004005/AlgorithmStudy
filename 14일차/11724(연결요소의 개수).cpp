#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool graph[1001][1001]{};
bool visit[1001]{};

void dfs(int n)
{
	visit[n] = true;

	for (int i = 1; i <= N; ++i)
	{
		if (visit[i]) continue;
		if (!graph[n][i]) continue;
		dfs(i);
	}
}

int main()
{
	cin >> N >> M;
	int u, v;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v;
		graph[u][v] = true;
		graph[v][u] = true;
	}

	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (visit[i]) continue;

		++cnt;
		dfs(i);
	}

	cout << cnt << endl;
	return 0;
}