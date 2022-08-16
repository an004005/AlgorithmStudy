#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int dp[1000001]{};

int dfs(int n)
{
	if (dp[n])
		return dp[n];

	if (n == 1)
	{
		return 0;
	}

	int minCnt = std::numeric_limits<int>::max();

	if (n % 3 == 0)
	{
		minCnt = std::min(minCnt, dfs(n / 3) + 1);
	}

	if (n % 2 == 0)
	{
		minCnt = std::min(minCnt, dfs(n / 2) + 1);
	}

	minCnt = std::min(minCnt, dfs(n - 1) + 1);
	dp[n] = minCnt;
	return dp[n];
}

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		dfs(i);
	}

	cout << dp[N] << endl;


	return 0;
}