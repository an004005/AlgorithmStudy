#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
using ullong = unsigned long long;
ullong trees[1000000];

int main()
{
	ullong N, M;
	cin >> N >> M;

	ullong upper = 0;
	ullong lower = 0;
	for (int i = 0; i < N; ++i)
	{
		//scanf("%d", &trees[i]);
		cin >> trees[i];
		if (trees[i] > upper)
			upper = trees[i];
	}

	ullong ret;
	while (lower <= upper)
	{
		ullong mid = (upper + lower) / 2;

		ullong sum = 0;
		for (int i = 0; i < N; ++i)
		{
			if (trees[i] > mid)
				sum += trees[i] - mid;
		}

		if (sum >= M) // sum�� ũ�� -> ������ ���� �߶� -> mid�� ���� -> mid�� ũ���Ѵ�.
		{
			ret = mid;
			lower = mid + 1;
		}
		else
		{
			upper = mid - 1;
		}
	}

	cout << ret << endl;


	return 0;
}