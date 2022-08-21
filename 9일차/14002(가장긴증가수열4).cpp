#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;
int arr[1000]{};
int dp[1000]{};

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	
	int len = 1;
	dp[0] = arr[0];

	for (int i = 1; i < N; ++i)
	{
		if (arr[i] > dp[len - 1])
			dp[len++] = arr[i];
		else
		{
			int upper = len - 1;
			int lower = 0;
			int ret;

			while (lower <= upper)
			{
				int mid = (upper + lower) / 2;
				if (dp[mid] <= arr[i])
				{
					ret = mid;
					upper = mid - 1;
				}
				else
					lower = mid + 1;
			}
			dp[ret] = arr[i];
		}
	}

	/*
	7
	3 2 5 2 3 1 4
	*/

	cout << len << endl;
	for (int i = 0; i < len; ++i)
		cout << dp[i] << " ";
	cout << endl;

	return 0;
}