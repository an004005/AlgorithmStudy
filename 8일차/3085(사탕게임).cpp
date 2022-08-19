#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

int N;
char candy[51][51]{};
int maxSum = 0;

void check()
{
	int result = 1;
	for (int i = 0; i < N; ++i)
	{
		int tmp = 1;
		for (int j = 1; j < N; ++j)
		{
			if (candy[i][j - 1] == candy[i][j])
			{
				++tmp;
			}
			else
			{
				result = max(result, tmp);
				tmp = 1;
			}
		}
		result = max(result, tmp);
	}

	for (int i = 0; i < N; ++i)
	{
		int tmp = 1;
		for (int j = 0; j < N - 1; ++j)
		{
			if (candy[j + 1][i] == candy[j][i])
			{
				++tmp;
			}
			else
			{
				result = max(result, tmp);
				tmp = 1;
			}
		}
		result = max(result, tmp);
	}

	maxSum = max(result, maxSum);
}



int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> candy[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - 1; ++j) // 가로 확인
		{
			std::swap(candy[i][j], candy[i][j + 1]);
			check();
			std::swap(candy[i][j], candy[i][j + 1]);
		}
	}

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < N; ++j) // 세로 확인
		{
			std::swap(candy[i][j], candy[i + 1][j]);
			check();
			std::swap(candy[i][j], candy[i + 1][j]);
		}
	}

	cout << maxSum << endl;
	return 0;
}