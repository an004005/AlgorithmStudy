#include<iostream>
#include<list>
#include <string>
using namespace std;



int main()
{
	string init;
	cin >> init;

	list<char> line(init.begin(), init.end());

	auto cursor = line.end();

	int n;
	cin >> n;

	char input;
	char add;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		switch (input)
		{
		case 'L':
			if (cursor != line.begin())
				cursor--;
			break;
		case 'D':
			if (cursor != line.end())
				cursor++;
			break;
		case 'B':
			if (cursor != line.begin())
			{
				cursor--;
				cursor = line.erase(cursor);
			}
			break;
		case 'P':
			cin >> add;
			cursor = line.insert(cursor, add);
			cursor++;
			break;
		default:
			break;
		}
	}


	for (auto& c : line)
		cout << c;

	return 0;
}