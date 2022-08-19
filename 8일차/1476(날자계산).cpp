#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int year = 1;

int main()
{
	int E, S, M;
	cin >> E >> S >> M;

	int initE = 1;
	int initS = 1;
	int initM = 1;

	while (true)
	{
		if (E == initE && S == initS && M == initM)
			break;

		++initE;
		++initS;
		++initM;
		++year;

		if (initE == 16)
			initE = 1;
		if (initS == 29)
			initS = 1;
		if (initM == 20)
			initM = 1;
	}
	cout << year << endl;


	return 0;
}