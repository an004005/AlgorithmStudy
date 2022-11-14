#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int k;
char inEq[10];
vector<int> stack;
bool bUsed[10]{};
vector<string> nums;

bool checkInEq()
{
	for (size_t i = 0; i < stack.size() - 1; ++i)
	{
		if (inEq[i] == '<')
		{
			if (stack[i] >= stack[i + 1])
				return false;
		}
		else if (inEq[i] == '>')
		{
			if (stack[i] <= stack[i + 1])
				return false;
		}
	}

	return true;
}

void dfs(int depth)
{
	if (depth > k)
	{
		if (checkInEq())
		{
			stringstream ss;
			for (auto e : stack)
				ss << e;
			nums.push_back(ss.str());
		}
		return;
	}

	for (int i = 0; i <= 9; ++i)
	{
		if (bUsed[i]) continue;

		bUsed[i] = true;
		stack.push_back(i);
		if (checkInEq())
			dfs(depth + 1);
		stack.pop_back();
		bUsed[i] = false;
	}
}

int main()
{
	cin >> k;
	for (int i = 0; i < k; ++i)
		cin >> inEq[i];

	dfs(0);

	sort(nums.begin(), nums.end());
	cout << nums.back() << endl;
	cout << nums.front() << endl;

	return 0;
}