#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int k;
int nums[12]{};
vector<int> stack;
vector<vector<int>> combies;

void dfs(int cur, int depth)
{
	if (depth == 6)
	{
		string tmp;
		for(auto e : stack)
		{
			char buff[10];
			sprintf(buff, "%d", e);
			tmp += buff;
		}
		combies.push_back(stack);

		return;
	}

	for (int i = cur; i < k; ++i)
	{
		stack.push_back(nums[i]);
		dfs(i + 1, depth + 1);
		stack.pop_back();
	}
}

int main()
{
	while(true)
	{
		cin >> k;
		if (k == 0) break;

		for (int i = 0; i < k; ++i)
			cin >> nums[i];

		stack.clear();
		combies.clear();
		dfs(0, 0);

		sort(combies.begin(), combies.end());

		for(auto& e : combies)
		{
			for(auto& ee : e)
			{
				cout << ee << " ";
			}
			cout << endl;
		}
		cout <<endl;
	}

	return 0;
}