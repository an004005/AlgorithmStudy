#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int T;
int M, N; //  40,000 under

int main()
{
	cin >> T;
	while (T--)
	{
		int x, y;
		cin >> M >> N >> x >> y;

		int cx = 1;
		int cy = 1;
		int year = 1;
		bool bFind = false;

		while (cx != M || cy != N)
		{
			++cx;
			++cy;
			++year;
			if (cx > M)
				cx = 1;
			if (cy > N)
				cy = 1;

			if (x == cx && y == cy)
			{
				bFind = true;
				break;
			}
		}

		if (bFind)
			cout << year << endl;
		else
			cout << -1 << endl;
	}


	return 0;
}