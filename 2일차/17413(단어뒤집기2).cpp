#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

void printStack(stack<char>& s)
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	string str;
	getline(cin, str);

	stack<char> s;

	for (int i = 0; i < str.size(); ++i)
	{
		char c = str[i];

		if (c == ' ')
		{
			printStack(s);
			cout << ' ';
		}
		else if (c == '<')
		{
			printStack(s);
			while (true)
			{
				cout << str[i];
				if (str[i] == '>')
					break;
				++i;
			}
		}
		else
			s.push(c);
	}

	printStack(s);


	return 0;
}