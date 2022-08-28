#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<pair<int, int>> moves;

void moveTower(int n, int from, int by, int to)
{
	++cnt;

	if (n == 1)
	{
		moves.push_back({ from, to }); // move one plate
	}
	else
	{
		moveTower(n - 1, from, to, by); // move n-1 plate
		moves.push_back({ from, to });
		moveTower(n - 1, by, from, to);
	}
}

int main()
{
	int K;
	cin >> K;

	moveTower(K, 1, 2, 3);

	cout << cnt << endl;
	for (auto& move : moves)
		printf("%d %d\n", move.first, move.second);
	return 0;
}