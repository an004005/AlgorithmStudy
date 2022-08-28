#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int P[1001]{};
	int cost = 0;

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> P[i];
	sort(P, P + N + 1);

	int sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		sum += P[i];
		cost += sum;
	}

	cout << cost << endl;
	return 0;
}