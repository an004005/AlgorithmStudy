#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <utility>
using namespace std;

stack<pair<char, int>> s;

int main()
{
	string str;
	cin >> str;

	int total = 0;

	for (size_t i = 0; i < str.size(); ++i)
	{
		if (str[i] == ')') 
		{
			if (s.top().first == '(' && s.top().second == i - 1)// 발사
			{
				s.pop();
				total += s.size();
			}
			else// 스틱 종료
			{
				total++;
				s.pop();
			}
		}
		else
		{
			s.push(make_pair(str[i], i));
		}
	}

	cout << total << endl;

	return 0;
}