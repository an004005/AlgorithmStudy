#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int weight[101]{};
int value[101]{};
int dp[101][100001]{}; // n가지 물건이 있을 때, w무게 사용할 경우 최대 가치 dp

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		cin >> weight[i] >> value[i];

	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			if (weight[i] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = std::max(value[i] + dp[i - 1][j - weight[i]], dp[i - 1][j]);
			}
		}
	}
	cout << dp[N][K] << endl;

	return 0;
}