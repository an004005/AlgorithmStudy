#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num[100];
long long sum = 0;
int N;
vector<int> s;

int gcd(int max, int min)
{
	if (max % min == 0)
		return min;
	else
		return gcd(min, max % min);
}

void combination(int n, int depth)
{
	if (depth == 0)
	{	
		int max = std::max(s[0], s[1]);
		int min = std::min(s[0], s[1]);
		sum += gcd(max, min);
		return;
	}

	for (int i = n; i < N; ++i)
	{
		s.push_back(num[i]);
		combination(i + 1, depth - 1);
		s.pop_back();
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &num[i]);

		sum = 0;
		combination(0, 2);
		cout << sum << endl;
	}
	return 0;
}