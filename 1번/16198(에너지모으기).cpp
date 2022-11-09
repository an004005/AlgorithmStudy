#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> W;

int maxW = 0;

void dfs(const vector<int>& vecW, int sum)
{
	if (vecW.size() == 2)
	{
		maxW = std::max(sum, maxW);
		return;
	}


	for (size_t i = 1; i < vecW.size() - 1; ++i)
	{
		vector<int> tmp(vecW.begin(), vecW.end());
		tmp.erase(tmp.begin() + i);
		int selectedW = sum + vecW[i - 1] * vecW[i + 1];
		dfs(tmp, selectedW);
	}
}


int main()
{
	cin >> N;
	W.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> W[i];

	dfs(W, 0);

	cout << maxW << endl;
	return 0;
}
