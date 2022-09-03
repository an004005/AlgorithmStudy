#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int dp[100001]{};

int main()
{
	int N;
	cin >> N;

	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= N; ++i)
	{
		dp[i] = (dp[i- 1] * 2 + dp[i - 2]) % 9901;
	}

	cout << dp[N] % 9901 << endl;


	return 0;
}