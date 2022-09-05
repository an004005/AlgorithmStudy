#include <iostream>
#include <cmath>
using namespace std;

int order = 0;

int main()
{
	int N, r, c;
	cin >> N >> r >> c;

	for (int i = N; i >= 1; --i)
	{
		int half = (int)pow(2, i) / 2;
		int oneSqr = (int)pow(2, i) * pow(2, i) / 4;

		if (r >= half && c >= half)
		{
			r -= half;
			c -= half;
			order += 3 * oneSqr;
		}
		else if (r >= half && c < half)
		{
			r -= half;
			order += 2 * oneSqr;
		}
		else if (c >= half && r < half)
		{
			c -= half;
			order += oneSqr;
		}
	}

	cout << order << endl;


	return 0;
}