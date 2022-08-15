#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V, E;

vector<vector<int>> graph;
int color[20001]{}; // 0 non, 1 red, -1 blue

bool bBi = true;

void dfs(int v)
{
	for (auto& u : graph[v])
	{

		if (color[u] == 0)
		{
			color[u] = color[v] * -1;
			dfs(u);
		}
	}
}

bool checkBi()
{
	for (int i = 1; i <= V; ++i)
	{
		for (auto& u : graph[i])
		{
			if (color[i] == color[u])
				return false;
		}
	}
	return true;
}

int main()
{
	graph.resize(20001);
	int K;
	cin >> K;
	while (K--)
	{
		for (auto& vec : graph)
			vec.clear();
		memset(color, 0, sizeof(color));

		cin >> V >> E;
		int u, v;
		for (int i = 0; i < E; ++i)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; ++i)
		{
			if (color[i] == 0)
			{
				color[i] = 1;
				dfs(i);
			}
		}

		if (checkBi())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	return 0;
}