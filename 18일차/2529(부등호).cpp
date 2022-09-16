#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>
using namespace std;

int k;
char unequal[9]{};
bool used[10]{};
string S;

unsigned long long minNum = std::numeric_limits<unsigned long long>::max();
unsigned long long maxNum = std::numeric_limits<unsigned long long>::min();
string minNumStr;
string maxNumStr;

void dfs(int depth)
{
	if (depth == k + 1)
	{
		int a = 3;
		unsigned long long outnum = stoull(S);
		if (outnum < minNum)
		{
			minNum = outnum;
			minNumStr = S;
		}
		if (outnum > maxNum)
		{
			maxNum = outnum;
			maxNumStr = S;
		}
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (used[i] == false)
		{
			if (depth != 0)
			{
				int lastNum = S.back() - 48;
				if (unequal[depth - 1] == '<')
				{
					if (lastNum > i)
						continue;
				}
				else
				{
					if (lastNum < i)
						continue;
				}
			}

			S.push_back(i + 48);
			used[i] = true;
			dfs(depth + 1);
			used[i] = false;
			S.pop_back();

		}
	}
}

int main()
{
	S.reserve(10);
	cin >> k;
	for (int i = 0; i < k; ++i)
		cin >> unequal[i];

	dfs(0);

	cout << maxNumStr << endl;
	cout << minNumStr << endl;

	return 0;
}
