#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, s;
int nums[20]{};
int cnt = 0;
int sum = 0;
int part = 0;

void dfs(int cur)
{
	if (cur == N)
	{
		if (part > 0 && sum == s)
			++cnt;
		return;
	}

	sum += nums[cur];
	part++;
	dfs(cur + 1);
	sum -= nums[cur];
	part--;


	dfs(cur + 1); // not add
}

int main()
{
	cin >> N >> s;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];

	dfs(0);

	cout << cnt << endl;

	return 0;
}

/*
4 0
1 -1 2 -2
*/