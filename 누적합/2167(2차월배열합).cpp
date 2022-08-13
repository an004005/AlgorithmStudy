#include <iostream>
using namespace std;

int N, M;
int K;

int arr[301][301]{};
long long sum[301][301]{};

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			//scanf_s("%d", &arr[i][j]);
			scanf("%d", &arr[i][j]);
		}
	}

	// row 방향 누적합
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			sum[i][j] = sum[i][j - 1] + arr[i][j];
		}
	}
	// col 방향 누적합
	for (int j = 1; j <= M; ++j)
	{
		for (int i = 1; i <= N; ++i)
		{
			sum[i][j] += sum[i - 1][j];
		}
	}


	cin >> K;
	for (int k = 0; k < K; ++k)
	{
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1] << endl;
	}

	return 0;
}