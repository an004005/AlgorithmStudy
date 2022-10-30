#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> vec;
int maxValue = 0;

void permu(int start, int end)
{
	if (start == end)
	{
		int sum = 0;
		for (int i = 0; i < N - 1; ++i)
			sum += abs(vec[i] - vec[i + 1]);
		maxValue = std::max(sum, maxValue);
	}
	else
	{
		for (int i = start; i < end; ++i)
		{
			std::swap(vec[start], vec[i]);
			permu(start + 1, end);
			std::swap(vec[start], vec[i]);
		}
	}
}

int main()
{
	vec.resize(8);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> vec[i];

	permu(0, N);
	cout <<maxValue<<endl;


	return 0;
}