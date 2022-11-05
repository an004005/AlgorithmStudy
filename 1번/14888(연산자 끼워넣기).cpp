#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int N;
int A[11]{};
int ops[4]{};

int MaxNum = std::numeric_limits<int>::min();
int MinNum = std::numeric_limits<int>::max();
int curNum = 0;

void dfs(int depth)
{
	if (depth == N)
	{
		MaxNum = std::max(curNum, MaxNum);
		MinNum = std::min(curNum, MinNum);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (ops[i] == 0) continue;

		--ops[i];
		const int preNum = curNum;

		switch (i)
		{
		case 0: // +
			curNum += A[depth];
			dfs(depth + 1);
			curNum = preNum;
			break;
		case 1: // -
			curNum -= A[depth];
			dfs(depth + 1);
			curNum = preNum;
			break;
		case 2: // *
			curNum *= A[depth];
			dfs(depth + 1);
			curNum = preNum;
			break;
		case 3: // /
			curNum /= A[depth];
			dfs(depth + 1);
			curNum = preNum;
			break;
		}
		++ops[i];
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];

	for (int i = 0; i < 4; ++i)
		cin >> ops[i];

	curNum = A[0];

	dfs(1);

	cout << MaxNum << endl;
	cout << MinNum << endl;

	return 0;
}
