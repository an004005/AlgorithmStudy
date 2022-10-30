#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <queue>
using namespace std;

const int MAX = 100000 + 1;
int N, K;
bool visit[MAX]{};

int main()
{
	cin >> N >> K;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;

	Q.push({0, N});
	visit[N] = true;

	int answer = 0;

	while (Q.empty() == false)
	{
		int curTime = Q.top().first;
		int curLoc = Q.top().second;
		Q.pop();

		if (curLoc == K)
		{
			answer = curTime;
			break;
		}


		if (curLoc + 1 < MAX && visit[curLoc + 1] == false)
		{
			visit[curLoc + 1] = true;
			Q.push({(curTime + 1), curLoc + 1});
		}

		if (curLoc - 1 >= 0 && visit[curLoc - 1] == false)
		{
			visit[curLoc - 1] = true;
			Q.push({(curTime + 1), curLoc - 1});
		}

		if (curLoc * 2 < MAX && visit[curLoc * 2] == false)
		{
			visit[curLoc * 2] = true;
			Q.push({curTime, curLoc * 2});
		}

	}

	cout << answer << endl;

	return 0;
}
