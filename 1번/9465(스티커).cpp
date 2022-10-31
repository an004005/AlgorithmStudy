#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sticker[2][100000];
int dp[2][100000]; // dp[i][n] : n번 열 까지 스티커가 있을 때 최대값

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;

		for (int j = 0; j < 2; ++j)
		{
			for (int i = 0; i < n; ++i)
				scanf("%d", &sticker[j][i]);
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		if (n == 1)
		{
			cout << std::max(dp[1][n-1], dp[0][n-1])<<endl;
			continue;
		}
		dp[0][1] = dp[1][0] + sticker[0][1];
		dp[1][1] = dp[0][0] + sticker[1][1];
		if (n == 2)
		{
			cout << std::max(dp[1][n-1], dp[0][n-1])<<endl;
			continue;
		}

		for (int i = 2; i < n; ++i)
		{
			dp[0][i] = std::max({dp[1][i-1] + sticker[0][i], dp[0][i-2] + sticker[0][i], dp[1][i-2] + sticker[0][i]});
			dp[1][i] = std::max({dp[0][i-1] + sticker[1][i], dp[0][i-2] + sticker[1][i], dp[1][i-2] + sticker[1][i]});
		}
		cout << std::max(dp[1][n-1], dp[0][n-1])<<endl;
	}


	return 0;
}
