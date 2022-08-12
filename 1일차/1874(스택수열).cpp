#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n;
int list[100000];

/*
나온 숫자 다음은 그 숫자보다 크다
만약 작은 숫자라면 스택의 top과 같아야 한다.

*/

int main()
{
	cin >> n;

	int last = -1;
	for (int i = 0; i < n; ++i)
		cin >> list[i];

	stack<int> s;
	int num = 1;
	vector<char> clist;
	clist.reserve(n + 1);

	for (int i = 0; i < n; ++i)
	{
		int cur = list[i];

		while (true)
		{
			if (s.empty())
			{
				s.push(num++);
				clist.push_back('+');
			}
			else if (s.top() < cur)
			{
				s.push(num++);
				clist.push_back('+');
			}
			else if (s.top() == cur)
			{
				s.pop();
				clist.push_back('-');
				break;
			}
			else if (s.top() > cur)
			{
				cout << "NO" << endl;
				exit(0);

			}
		}
	}


	for (auto& c : clist)
		printf("%c\n", c);


	return 0;
}