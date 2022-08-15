#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAX = 100000;

int N, M;
int num[MAX];

int findNumber(int i)
{
	int upper = N - 1;
	int lower = 0;

	while (lower <= upper)
	{
		int mid = (upper + lower) / 2;

		if (num[mid] < i)
		{
			lower = mid + 1;
		}
		else if (num[mid] > i)
		{
			upper = mid - 1;
		}
		else
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &num[i]);

	sort(num, num + N);

	cin >> M;
	for (int i = 1; i <= M; ++i)
	{
		int tosearch;
		scanf_s("%d", &tosearch);
		printf("%d\n", findNumber(tosearch));
	}
	
	return 0;
}