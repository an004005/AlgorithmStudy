#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;

int dy[4]{ 0,0,1,-1 };
int dx[4]{ 1,-1,0,0 };

int n, d, c;
vector<vector<pair<int, int>>> depends;
vector<int> dist;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> d >> c;
		depends.clear();
		dist.clear();
		depends.resize(n + 1);
		dist.resize(n + 1, std::numeric_limits<int>::max());

		int a, b, s;
		for (int i = 0; i < d; ++i)
		{
			cin >> a >> b >> s;
			depends[b].push_back({ a, s }); // v, cost
		}

		priority_queue<pair<int, int>> Q; // -cost, V
		dist[c] = 0;
		for (auto& e : depends[c])
		{
			dist[e.first] = e.second;
			Q.push({ -e.second, e.first });
		}

		while (!Q.empty())
		{
			int cur = Q.top().second;
			Q.pop();

			for (auto& e : depends[cur])
			{
				if (dist[e.first] > dist[cur] + e.second)
				{
					dist[e.first] = dist[cur] + e.second;
					Q.push({ -dist[e.first], e.first });
				}
			}
		}

		int cnt = 0;
		int time = 0;
		for (auto& e : dist)
		{
			if (e != std::numeric_limits<int>::max())
			{
				++cnt;
				if (time < e)
					time = e;
			}
		}

		cout << cnt << " " << time << endl;

	}

	return 0;
}