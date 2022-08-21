#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int n;
int arr[100001]{};
int dp[100001]{};// dp[j] = c : j ~ 현 arr 인덱스 까지의 합
int maxNum = -1001;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	dp[0] = arr[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i] = std::max(dp[i - 1] + arr[i], arr[i]);
		maxNum = std::max(dp[i], maxNum);
	}

	cout << maxNum << endl;

	return 0;
}