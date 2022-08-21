#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1001]{};
int dp[1001]{}; //dp[i]: 길이가 i 인 증가하는 부분 수열 중 끝점의 최솟값
int len = 0;// 수열 길이

int bisearch(int n)
{
	int lower = 0;
	int upper = len - 1;
	int ret;

	while (lower <= upper)
	{
		int mid = (upper + lower) / 2;
		if (dp[mid] >= arr[n])
		{
			ret = mid;
			upper = mid - 1;
		}
		else
		{
			lower = mid + 1;
		}
	}

	return ret;
}
/*
7
3 2 5 2 3 1 4
*/

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] > dp[len - 1])
		{
			dp[len] = arr[i]; // 마지막 배열값보다 크다. 못찾기 때문에 새로 추가
			++len;
			continue;
		}

		dp[bisearch(i)] = arr[i]; // 최소값 갱신
	}

	cout << len << endl;


	return 0;
}