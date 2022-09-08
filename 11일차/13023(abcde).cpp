#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M;
vector<vector<int>> graph;
bool visit[2000]{};
stack<int> s;

void dfs(int cur)
{
	visit[cur] = true;
	s.push(cur);
	if (s.size() >= 5)
	{
		cout << 1 << endl;
		exit(0);
	}
	
	for (auto& next : graph[cur])
	{
		if (!visit[next])
			dfs(next);
	}

	visit[cur] = false;
	s.pop();
}

int main()
{
	graph.resize(2000);
	int a, b;

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < N; ++i)
		dfs(i);

	cout << 0 << endl;


	return 0;
}