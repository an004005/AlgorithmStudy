#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N;
int T[16]{};
int P[16]{};

int maxCost = 0;

void dfs(int curDay, int cost)
{
	if (maxCost < cost)
		maxCost = cost;
	if (curDay > N)
		return;

	// °í¸§
	int Nextday = curDay + T[curDay];
	int NextCost = cost + P[curDay];

	if (Nextday <= N + 1)
		dfs(Nextday, NextCost);

	if (curDay <= N)
		dfs(curDay + 1, cost);
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> T[i] >> P[i];


	dfs(1, 0);

	cout << maxCost << endl;
	return 0;
}
