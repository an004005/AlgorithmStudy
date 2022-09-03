#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
char chs[15];
vector<char> s;

int moum = 0;
int jaum = 0;

void push(char c)
{
	switch (c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		++moum;
		break;
	default:
		++jaum;
		break;
	}
	s.push_back(c);
}

void pop()
{
	char c = s.back();
	s.pop_back();
	switch (c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		--moum;
		break;
	default:
		--jaum;
		break;
	}
}

void combination(int cur, int depth)
{
	if (depth == 0)
	{
		if (moum >= 1 && jaum >= 2)
		{
			for (auto& e : s)
				cout << e;
			cout << endl;
		}

		return;
	}

	for (int i = cur; i < C; ++i)
	{
		push(chs[i]);
		combination(i + 1, depth - 1);
		pop();
	}
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; ++i)
		cin >> chs[i];
	sort(chs, chs + C);

	combination(0, L);

	return 0;
}