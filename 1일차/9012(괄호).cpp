#include <iostream>
#include <string>
#include <stack>
using namespace std;

void check(string& str)
{
	stack<int> s;
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			s.push(0);
		}
		else if (str[i] == ')')
		{
			if (!s.empty())
				s.pop();
			else
			{
				cout << "NO" << endl;
				return;
			}
		}
	}
	if (!s.empty())
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}

int main()
{
	int T;
	cin >> T;


	for (int i = 0; i < T; ++i)
	{
		string str;
		cin >> str;
		check(str);
	}

	return 0;
}