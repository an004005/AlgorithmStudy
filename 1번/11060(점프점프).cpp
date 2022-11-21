#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

const int IMAX = numeric_limits<int>::max();
int N;
int arr[1001];
int dp[1001]; // dp[n] : 발판 n개 있을 때오른쪽가는 최소 점프 회수


/*
 * if (arr[i] > n + 1 - i)
 *   list += dp[i] + 1;
 * dp[n + 1] = min(dp[n + 1], dp[i] + 1]
 */

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &arr[i]);
		dp[i] = IMAX;	
	}

	dp[1] = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (dp[i] == IMAX) continue;

		for (int j = 1; j <= arr[i]; ++j)
		{
			if (i + j > N) continue;
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}



	if (dp[N] == IMAX) cout << -1 << endl;
	else cout << dp[N] << endl;
	return 0;
}