#include<iostream>
#include <vector>
#include <queue>
#include<limits>
#include<algorithm>
using namespace std;

int T;
int n, d, c; // 컴퓨터 개수 n, 의존성 개수 d, 해킹당한 컴퓨터의 번호 c
vector<vector<pair<int, int>>> map; // 컴번호, 의존성, 시간
int dist[10001]{};
bool visit[10001]{};


int main()
{
	cin >> T;
	map.resize(10001);
	while (T--)
	{
		cin >> n >> d >> c;
		for (int i = 1; i <= n; ++i)
		{
			map[i].clear();
			dist[i] = std::numeric_limits<int>::max();
			visit[i] = false;
		}

		int a, b, s; // 컴퓨터 a가 컴퓨터 b를 의존하며, 컴퓨터 b가 감염되면 s초 뒤 a감염
		for (int i = 0; i < d; ++i)
		{
			cin >> a >> b >> s;
			map[b].push_back({ a, s });
		}

		priority_queue<pair<int, int>> q;

		visit[c] = true;
		dist[c] = 0;
		for (auto& e : map[c])
		{
			dist[e.first] = e.second;
			q.push({ -e.second, e.first });// -cost, to
		}

		while (!q.empty())
		{
			int cur = q.top().second;
			q.pop();

			for (auto& e : map[cur])
			{
				if (visit[e.first] == false)
				{
					int to = e.first;
					int cost = e.second;
					if (dist[to] > dist[cur] + cost)
					{
						dist[to] = dist[cur] + cost;
						q.push({ -dist[to], to });
					}
				}
			}
		}

		int m = 0;
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (dist[i] < std::numeric_limits<int>::max())
			{
				cnt++;
				m = std::max(m, dist[i]);
			}
		}

		cout << cnt << " " << m << endl;
	}

	return 0;
}