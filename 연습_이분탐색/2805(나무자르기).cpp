#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

using ullong = unsigned long long;

int N; // ���� ����
ullong M; // �ʿ� ���� ����

ullong trees[1000000]; // �� ���� ����

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

		if (sum >= M) // sum�� M ���� �۴� : �ʹ� ���� �߸� : mid�� ũ��->�۰� �����.
		{
			ret = mid;
			lower = mid + 1;
		}
		else // ũ��
		{
			upper = mid- 1;
		}
	}

	cout << ret << endl;



	return 0;
}