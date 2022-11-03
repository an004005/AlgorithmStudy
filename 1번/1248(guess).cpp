#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int n;
string out;
char mat[10][10];
// -10 ~ 10 사이의 숫자 시퀀스
// 개수는 n개

vector<int> vec;
vector<int> vecType;

bool check(int N)
{
	for (int i = 0; i < N; ++i)
	{
		int sum = 0;
		for (int j = i; j < N; ++j)
		{
			sum += vec[j];

			switch (mat[i][j])
			{
			case '+':
				if (sum <= 0) return false;
				break;
			case '-':
				if (sum >= 0) return false;
				break;
			case '0':
				if (sum != 0) return false;
				break;
			}
		}
	}

	return true;
}

void dfs(int idx)
{
	if (idx == n)
	{
			for(auto e : vec)
			{
				cout << e << " ";
			}
			cout <<endl;
			exit(0);
		

		return;
	}

	if (vecType[idx] != 0)
	{
		for (int i = 1; i <= 10; ++i)
		{
			if (vecType[idx] == 1)
				vec[idx] = i;
			else
				vec[idx] = -i;

			if (check(idx + 1))
				dfs(idx + 1);
			else
				continue;
		}
	}
	else
	{
		dfs(idx + 1);
	}
}

int main()
{
	cin >>n;
	cin >> out;
	vec.resize(n, 0);
	vecType.resize(n, 0);

	int center = 0;
	int j = n;
	for (int i = 0; i < n; ++i)
	{
		switch (out[center])
		{
		case '+':
			vecType[i] = 1;
			break;
		case '-':
			vecType[i] = -1;
			break;
		case '0':
			vecType[i] = 0;
			break;
		}

		center += j;
		--j;
	}

	int OutIdx = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			mat[i][j] = out[OutIdx];
			++OutIdx;
		}
	}


	dfs(0);



	return 0;
}