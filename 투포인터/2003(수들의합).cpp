#include<iostream>
using namespace std;

int N, M;
int arr[10000];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int s = 0; // start
	int e = 0; // end
	int curSum = arr[0];
	int cnt = 0;

	while (e < N)
	{
		if (curSum < M)
			curSum += arr[++e];
		else if (curSum > M)
			curSum -= arr[s++];
		else
		{
			cnt++;
			curSum -= arr[s++];
		}
	}

	cout << cnt << endl;
	return 0;
}