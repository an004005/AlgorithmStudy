#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
using uint64 = unsigned long long;

int N;
int nums[101];
uint64 dp[101][21]{}; // N개 수일 때, [0,20]을 만들 개수 저장
uint64 answer = 0;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> nums[i];

	dp[1][nums[1]] = 1;

	for (int i = 2; i <= N - 1; ++i)
	{
		for (int j = 0; j <= 20; ++j)
		{
			if (dp[i - 1][j] > 0)
			{
				int minus = j - nums[i];
				if (minus >= 0 && minus <= 20)
					dp[i][minus] += dp[i - 1][j];

				int plus = j + nums[i];
				if (plus >= 0 && plus <= 20)
					dp[i][plus] += dp[i - 1][j];
			}
		}
	}

	answer = dp[N - 1][nums[N]];
	cout << answer << endl;

	return 0;
}
