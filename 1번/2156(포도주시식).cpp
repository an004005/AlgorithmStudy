#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int wines[10000];
int dp[10001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> wines[i];

	dp[0] = 0;
	dp[1] = wines[0];
	dp[2] = wines[0] + wines[1];

	for (int i = 3; i < n + 1; ++i)
	{
		dp[i] = std::max({dp[i - 1], dp[i - 2] + wines[i-1], dp[i-3] + wines[i-1] + wines[i-2]});
	}
	cout << dp[n] << endl;
	return 0;
}