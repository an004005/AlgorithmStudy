#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N, K;
int coin[10]{};


int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
		cin >> coin[i];

	int cnt = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		if (K / coin[i])
		{
			cnt += K / coin[i];
			K = K % coin[i];
		}
	}
	cout << cnt << endl;

	return 0;
}