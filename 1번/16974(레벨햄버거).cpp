#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
using uint64 = unsigned long long;

uint64 N, X;

uint64 bCnt[51];
uint64 pCnt[51];
/*
 * 0 : 1, p     1
 * 1 : 5, bpppb 01233
 * 2 : 13 B BPPPB P BPPPB B 0 01233 4 45677 7
 * 3 : 26 + 3, b BBPPPBPBPPPBB pBBPPPBPBPPPBBb, 0 0012334456777 8 888
 *
 *  burger cnt[i] = 3 + burger cnt[i - 1] * 2
 *
 */

uint64 dfs(uint64 n, uint64 x)
{
	if (x == 0) return 0;

	if (bCnt[n] == x)
	{
		return pCnt[n];
	}

	if (n == 0)
		return x ? 1 : 0;

	if (x <= bCnt[n] / 2)  // ex) 13 -> 6 
	{
		return dfs(n - 1, x - 1);
	}
	else if (x == bCnt[n] / 2 + 1) // 가운데
	{
		return pCnt[n - 1] + 1;
	}
	else // 중간 이상
	{
		return 1 + pCnt[n - 1] + dfs(n - 1, x - (bCnt[n] / 2 + 1));
	}
}

int main()
{
	cin >> N >> X;

	bCnt[0] = 1;
	bCnt[1] = 5;

	pCnt[0] = 1;
	pCnt[1] = 3;

	for (uint64 i = 2; i <= N; ++i)
	{
		bCnt[i] = bCnt[i - 1] * 2 + 3;
		pCnt[i] = pCnt[i - 1] * 2 + 1;
	}

	cout << dfs(N, X) << endl;

	return 0;
}