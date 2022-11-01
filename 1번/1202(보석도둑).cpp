#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> gems; // value, weight
int K;
vector<int> bags; // 담을 수 있는 최대 무게

int main()
{
	cin >> N >> K;
	gems.reserve(N);
	bags.reserve(K);

	int M, V;
	for (int i = 0; i < N; ++i)
	{
		cin >> M >> V;
		gems.push_back({M, V});
	}
	int C;
	for (int i = 0; i < K; ++i)
	{
		cin >> C;
		bags.push_back(C);
	}

	std::sort(gems.begin(), gems.end());  // 오름차순, 무게 작은순서->높은
	std::sort(bags.begin(), bags.end()); // 오름차순,

	priority_queue<pair<int, int>> Q;
	size_t j = 0;


	unsigned long long maxSum = 0;
	for (size_t i = 0; i < bags.size(); ++i)
	{
		while (j < gems.size())
		{
			if (gems[j].first <= bags[i])
			{
				Q.push({gems[j].second, gems[j].first});
				++j;
			}
			else
			{
				break;
			}
		}

		if (!Q.empty())
		{
			maxSum += Q.top().first;
			Q.pop();
		}
	}

	cout << maxSum << endl;

	return 0;
}