#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int dp[31];

int main()
{
	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;

	for (int i = 4; i <= N; ++i)
	{
		if (i % 2 == 1)
			dp[i] = 0;
		else
			dp[i] = (dp[i - 2] * 3 + dp[i - 4] * 2);
	}

	cout << dp[N] << endl;

	return 0;
}