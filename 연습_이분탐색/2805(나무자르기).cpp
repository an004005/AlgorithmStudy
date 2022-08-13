#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

using ullong = unsigned long long;

int N; // 나무 개수
ullong M; // 필요 나무 길이

ullong trees[1000000]; // 각 나무 길이

ullong upper = 0;
ullong lower = 0;
ullong mid = 0;

ullong sum = 0;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> trees[i];
		upper = std::max(upper, trees[i]);
	}

	ullong ret;
	while (lower <= upper)
	{
		mid = (upper + lower) /2;

		sum = 0;
		for (int i = 0; i < N; ++i)
		{
			long long cut = trees[i] - mid;
			if (cut > 0)
				sum += cut;
		}

		if (sum >= M) // sum이 M 보다 작다 : 너무 조금 잘름 : mid가 크가->작게 만든다.
		{
			ret = mid;
			lower = mid + 1;
		}
		else // 크게
		{
			upper = mid- 1;
		}
	}

	cout << ret << endl;



	return 0;
}