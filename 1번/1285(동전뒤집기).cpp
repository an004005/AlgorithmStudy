#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
// 뒷면 최소
int N;
bool coins[20][20]; // true : 앞면, false : 뒷면

int main()
{
	cin >> N;
	const bool bEven = N % 2 == 0;

	string tmp;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		for (int j = 0; j < tmp.size(); ++j)
			coins[i][j] = tmp[j] == 'H';
	}

	// 열 도는 행에 뒷면의 개수가 앞면과 같거나 크면 뒤집는다.

	int minBackCnt = std::numeric_limits<int>::max();

	while (true)
	{
		for (int i = 0; i < N; ++i) // row 확인
		{
			int backCnt = 0;
			for (int j = 0; j < N; ++j)
			{
				if (coins[i][j] == false) ++backCnt;
			}

			if (bEven && backCnt >=  N / 2) // 짝수면 절반 이상일 때 뒤집기
			{
				for (int j = 0; j < N; ++j)
					coins[i][j] = !coins[i][j];
				continue;
			}

			if (!bEven && backCnt > N / 2) // 홀수면 절반 보다 클때 뒤집기
			{
				for (int j = 0; j < N; ++j)
					coins[i][j] = !coins[i][j];
				continue;
			}
		}

		for (int i = 0; i < N; ++i) // col 확인
		{
			int backCnt = 0;
			for (int j = 0; j < N; ++j)
			{
				if (coins[j][i] == false) ++backCnt;
			}

			if (bEven && backCnt >=  N / 2) // 짝수면 절반 이상일 때 뒤집기
			{
				for (int j = 0; j < N; ++j)
					coins[j][i] = !coins[j][i];
				continue;
			}

			if (!bEven && backCnt > N / 2) // 홀수면 절반 보다 클때 뒤집기
			{
				for (int j = 0; j < N; ++j)
					coins[j][i] = !coins[j][i];
				continue;
			}
		}

		int curbackCnt = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				if (coins[i][j] == false) ++curbackCnt;
		}

		if (curbackCnt < minBackCnt)
			minBackCnt = curbackCnt;
		else
			break;
	}

	cout << minBackCnt << endl;

	return 0;
}