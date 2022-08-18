#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include<vector>
#include<algorithm>
using namespace std;

int height[9];
list<int> s;

void combination(int n, int depth)
{
	if (depth == 0)
	{
		int sum = 0;
		for (auto& n : s)
		{
			sum += height[n];
		}

		if (sum == 100)
		{
			vector<int> vec;
			for (auto& n : s)
				vec.push_back(height[n]);
			sort(vec.begin(), vec.end());

			for (auto& n : vec)
				cout << n << endl;
			exit(0);
		}
		return;
	}

	for (int i = n; i < 9; ++i)
	{
		s.push_back(i);
		combination(i + 1, depth - 1);
		s.pop_back();
	}
}

int main()
{
	for (int i = 0; i < 9; ++i)
		cin >> height[i];

	combination(0, 7);

	return 0;
}