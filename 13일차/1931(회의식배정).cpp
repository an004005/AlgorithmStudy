#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using Room = pair<unsigned int, unsigned int>; // end, start

int main()
{
	int N;
	vector<Room> reserver;
	vector<Room> select;

	cin >> N;
	int s, e;
	for (int i = 0; i < N; ++i)
	{
		cin >> s >> e;
		reserver.push_back({e, s});
	}

	sort(reserver.begin(), reserver.end());

	select.push_back(reserver[0]);
	for (size_t i = 1; i < reserver.size(); ++i)
	{
		Room& cur = reserver[i];
		Room& lastSelect = select.back();

		if (lastSelect.first <= cur.second)
			select.push_back(cur);
	}

	cout << select.size() << endl;

	//for (auto& e : reserver)
	//	cout << e.second << " " << e.first << endl;


	return 0;
}

//1 4
//3 5
//0 6
//5 7
//3 8
//5 9
//6 10
//8 11
//8 12
//2 13
//12 14
