#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T;



int main()
{

	cin >> T;

	cin.ignore();
	for (int i = 0; i < T; ++i)
	{
		string str;
		getline(cin, str);


		int s = 0;
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (str[i] == ' ')
			{
				string sub;
				for (size_t j = s; j < i; ++j)
				{
					sub += str[j];
				}

				std::reverse(sub.begin(), sub.end());
				cout << sub << ' ';

				s = i + 1;
			}
	
		}

		string sub;
		for (size_t j = s; j < str.size(); ++j)
		{
			sub += str[j];
		}

		std::reverse(sub.begin(), sub.end());
		cout << sub << ' ';

		cout << endl;
	}


	return 0;
}