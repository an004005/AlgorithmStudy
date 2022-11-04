#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

int N;
int S[20];
vector<int> stack;
set<int> setSum;

void dfs(int depth, int cur)
{
	if (depth == 0)
	{
		return;
	}

	for (int i = cur; i < N; ++i)
	{
		stack.push_back(S[i]);
		setSum.insert(std::accumulate(stack.begin(), stack.end(), 0));
		dfs(depth - 1, i + 1);
		stack.pop_back();
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> S[i];

	dfs(N, 0);
	int min = 1;
	for (auto e : setSum)
	{
		if (e == min)
		{
			++min;
		}
	}

	cout << min <<endl;

	return 0;
}