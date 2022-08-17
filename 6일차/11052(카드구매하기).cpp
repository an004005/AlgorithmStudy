#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int P[1001]; // P[i] = c : ī�� i�� ����ִ� ī���� P[i]�� ���� c
int dp[1001]; // dp[i] = c : ī�� i�� �� �� �ִ밪 c



int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> P[i];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			// 4 3 2
			// 0 1 2
			dp[i] = std::max(dp[i], P[i - j + 1] + dp[j - 1]);
		}
	}

	cout << dp[N] << endl;

	return 0;
}