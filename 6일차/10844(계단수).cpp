#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
constexpr int MOD = 1'000'000'000;
int dp[10][101];

int main()
{
	int N;
	cin >> N;
	
	for (int i = 1; i < 10; ++i)
		dp[i][1] = 1;

	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j == 0)
			{
				dp[0][i + 1] = (dp[0][i + 1] + dp[1][i]) % MOD;//1 뒤 0만 가능
			}
			else if (j == 9)
			{
				dp[9][i + 1] = (dp[9][i + 1] + dp[8][i]) % MOD; // 9뒤 8만 가능
			}
			else
			{
				dp[j][i + 1] = (dp[j][i + 1] + dp[j - 1][i]) % MOD;
				dp[j][i + 1] = (dp[j][i + 1] + dp[j + 1][i]) % MOD;
			}
		};
	}

	int sum = 0;
	for (int i = 0; i <= 9; ++i)
		sum = (dp[i][N] + sum) % 1'000'000'000;

	cout << sum << endl;


	return 0;
}