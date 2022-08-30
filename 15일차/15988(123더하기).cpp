#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

constexpr unsigned long long MOD = 1'000'000'009;
unsigned long long dp[1'000'001]{};

int main()
{
	int T;
	cin >> T;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	int exN = 2;

	while (T--)
	{
		int n;
		cin >> n;

		for (int i = exN + 1; i <= n; ++i)
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;

		cout << dp[n] << endl;
		exN = n;
	}
	return 0;
}
