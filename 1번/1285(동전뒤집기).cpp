#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
// �޸� �ּ�
int N;
bool coins[20][20]; // true : �ո�, false : �޸�

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

	// �� ���� �࿡ �޸��� ������ �ո�� ���ų� ũ�� �����´�.

	int minBackCnt = std::numeric_limits<int>::max();

	while (true)
	{
		for (int i = 0; i < N; ++i) // row Ȯ��
		{
			int backCnt = 0;
			for (int j = 0; j < N; ++j)
			{
				if (coins[i][j] == false) ++backCnt;
			}

			if (bEven && backCnt >=  N / 2) // ¦���� ���� �̻��� �� ������
			{
				for (int j = 0; j < N; ++j)
					coins[i][j] = !coins[i][j];
				continue;
			}

			if (!bEven && backCnt > N / 2) // Ȧ���� ���� ���� Ŭ�� ������
			{
				for (int j = 0; j < N; ++j)
					coins[i][j] = !coins[i][j];
				continue;
			}
		}

		for (int i = 0; i < N; ++i) // col Ȯ��
		{
			int backCnt = 0;
			for (int j = 0; j < N; ++j)
			{
				if (coins[j][i] == false) ++backCnt;
			}

			if (bEven && backCnt >=  N / 2) // ¦���� ���� �̻��� �� ������
			{
				for (int j = 0; j < N; ++j)
					coins[j][i] = !coins[j][i];
				continue;
			}

			if (!bEven && backCnt > N / 2) // Ȧ���� ���� ���� Ŭ�� ������
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