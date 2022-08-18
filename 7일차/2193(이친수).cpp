#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

unsigned long long dp[2][91]{};

int main()
{
	int N;
	cin >> N;
	dp[0][1] = 1;
	dp[0][2] = 1;

	for (int i = 3; i <= N; ++i)
	{
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}


	cout << dp[0][N] + dp[1][N] << endl;

	return 0;
}