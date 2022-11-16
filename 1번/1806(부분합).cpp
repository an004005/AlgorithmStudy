#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int N, S;
int nums[100000];

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; ++i)
		scanf("%d", &nums[i]);

	int start = 0;
	int end = 0;
	int sum = 0;
	int len = 0;

	int minLen = numeric_limits<int>::max();

	while(true)
	{
		if (sum < S)
		{
			if (end >= N) break;

			sum += nums[end];
			++end;
			++len;
		}
		else
		{
			minLen = min(minLen, len);
			sum -= nums[start];
			++start;
			--len;
		}

	}

	if (minLen == numeric_limits<int>::max()) cout << 0 << endl;
	else cout << minLen << endl;

	return 0;
}