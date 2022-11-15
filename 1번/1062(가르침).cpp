#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
string words[50];
bool bKnown[26]{};

int maxVal = 0;

void dfs(int depth, int idx)
{
	if (depth <= 0)
	{
		int sum = 0;
		for (int i = 0; i < N; ++i)
		{
			bool bCanRead = true;
	
			for (auto c : words[i])
			{
				if (bKnown[c - 'a'] == false)
				{
					bCanRead = false;
					break;
				}
			}
	
			if (bCanRead) ++sum;
		}
	
		maxVal = std::max(maxVal, sum);
		return;
	}
	
	for (int i = idx; i < 26; ++i)
	{
		if (bKnown[i]) continue;

		bKnown[i] = true;
		dfs(depth - 1, idx + 1);
		bKnown[i] = false;
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	if (K < 5)
	{
		cout << 0 << endl;
		return 0;
	}

	K -= 5;
	bKnown['a' - 'a'] = true;
	bKnown['n' - 'a'] = true;
	bKnown['t' - 'a'] = true;
	bKnown['i' - 'a'] = true;
	bKnown['c' - 'a'] = true;

	for (int i = 0; i < N; ++i)
	{
		cin >> words[i];
	}

	dfs(K, 0);
	
	cout << maxVal << endl;

	return 0;
}
