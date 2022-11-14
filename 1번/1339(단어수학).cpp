#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

int N;
unsigned int maxValue = 0;
string inputs[10];

int alphaNums[30]{};
vector<char> usedAlpha;
bool bUsed[10]{};

void dfs(int depth)
{
	if (depth >= usedAlpha.size())
	{
		unsigned int sum = 0;
		for (int i = 0; i < N; ++i)
		{
			const int len = inputs[i].size();
			int deci = 1;
			for (int j = len - 1; j >= 0; --j)
			{
				sum += alphaNums[inputs[i][j] - 65] * deci;
				deci *= 10;
			}
		}
		maxValue = std::max(sum, maxValue);

		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (bUsed[i]) continue;
		
		bUsed[i] = true;
		alphaNums[usedAlpha[depth] - 65] = i;
		dfs(depth + 1);
		bUsed[i] = false;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> inputs[i];

	set<char> chars;
	for (int i = 0; i < N; ++i)
	{
		for (auto c : inputs[i])
			chars.insert(c);
	}
	usedAlpha.assign(chars.begin(), chars.end());

	dfs(0);

	cout << maxValue << endl;


	return 0;
}