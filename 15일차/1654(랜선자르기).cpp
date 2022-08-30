#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

unsigned int K, N;
unsigned int lan[10000]{};

int main()
{
	cin >> K >> N;
	unsigned int upper = 0;

	for (unsigned int i = 0; i < K; ++i)
	{
		scanf("%d", &lan[i]);
		if (upper < lan[i])
			upper = lan[i];
	}

	unsigned int lower = 1;
	unsigned int mid; // cut size
	unsigned int ret = 0;

	while (lower <= upper)
	{
		mid = (upper + lower) / 2;

		unsigned int sum = 0;
		for (unsigned int i = 0; i < K; ++i)
		{
			if (lan[i] >= mid)
				sum += lan[i] / mid;
		}
		
		if (sum < N) // 개수가 적음-> mid가 크다 -> upper 감소
		{
			upper = mid - 1;
		}
		else
		{
			ret = mid;
			lower = mid + 1;
		}
	}

	cout << ret << endl;

	return 0;
}