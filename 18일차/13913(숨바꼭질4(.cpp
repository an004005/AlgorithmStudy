#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
using namespace std;

int N, K;
vector<pair<int, int>> visit; // time, from

int main()
{
	visit.resize(100001, {std::numeric_limits<int>::max(), 0});
	cin >> N >> K;

	if (N >= K)
	{
		cout << N - K << endl;
		for (int i = N; i >= K; --i)
			printf("%d ", i);
		cout << endl;
	}
	else
	{
		priority_queue<pair<int, int>> Q; // time, cur
		Q.push({0, N});
		visit[N].first = 0;
		visit[N].second = N;


		while (Q.empty() == false)
		{
			int time = -Q.top().first;
			int cur = Q.top().second;
			Q.pop();

			if (cur == K)
			{
				cout << time << endl;
				stack<int> s;
				while (true)
				{
					s.push(cur);
					cur = visit[cur].second;
					if (cur == N)
						break;
				}
				s.push(cur);

				while (s.empty() == false)
				{
					printf("%d ", s.top());
					s.pop();
				}

					
				break;
			}

			for (int i = 0; i < 3; ++i)
			{
				int ncur;
				if (i == 0)
					ncur = cur + 1;
				else if (i == 1)
					ncur = cur - 1;
				else if (i == 2)
					ncur = cur * 2;
				if (ncur < 0 || ncur > 100000)
					continue;

				if (visit[ncur].first > time + 1)
				{
					visit[ncur].first = time + 1;
					visit[ncur].second = cur;

					Q.push({-(time + 1), ncur});
				}
			}
		}
	}
	return 0;
}
