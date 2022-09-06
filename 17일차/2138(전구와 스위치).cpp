#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
bool switches[100000]{};
bool switches2[100000]{};

/*
 * 0 : 짝수 번 변경
 * 1 : 홀수 번 변경
 *
 * xor 연산 후 000으로 만들기 0인 경우 짝수번, 1인경우 홀수번 연산이 들어간다.
 *  [0][1][2][3][N-1][N][N+1]
 *	[0][1 ~ N][N + 1]
 * 
 */

int main()
{
	string from, to;

	cin >> N;
	cin >> from;
	cin >> to;
	for (size_t i = 0; i < from.size(); ++i)
	{
		if (from[i] != to[i])
		{
			switches[i] = true;
			switches2[i] = true;
		}
	}

	int cnt = 0;


	for (int i = 1; i < N; ++i) // 맨 처음 안누르고 시작
	{
		if (i == N - 1) // 뒤
		{
			if (switches[i] ^ switches[i - 1])
			{
				cnt = -1;
				break;
			}
			else if (switches[i] && switches[i - 1])
				cnt++;
		}
		else
		{
			if (switches[i - 1])
			{
				switches[i - 1] = !switches[i - 1];
				switches[i] = !switches[i];
				switches[i + 1] = !switches[i + 1];
				++cnt;
			}
		}
	}

	if (cnt == -1)
	{
		cnt = 1;
	}
	else
	{
		cout << cnt << endl;
		return 0;
	}

	switches2[0] = !switches2[0];
	switches2[1] = !switches2[1];

	for (int i = 1; i < N; ++i) // 맨 처음 누르고 시작
	{
		if (i == N - 1) // 뒤
		{
			if (switches2[i] ^ switches2[i - 1])
			{
				cnt = -1;
				break;
			}
			else if (switches2[i] && switches2[i - 1])
				cnt++;
		}
		else
		{
			if (switches2[i - 1])
			{
				switches2[i - 1] = !switches2[i - 1];
				switches2[i] = !switches2[i];
				switches2[i + 1] = !switches2[i + 1];
				++cnt;
			}
		}
	}


	cout << cnt << endl;


	return 0;
}
