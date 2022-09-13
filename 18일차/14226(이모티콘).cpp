#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
using namespace std;

int S;
int visit[1001][1001]{};// visit[cnt][clip] = time

int main()
{
	cin >> S;
	for (int i = 0; i < 1001; ++i)
	{
		for (int j = 0; j < 1001; ++j)
		{
			visit[i][j] = std::numeric_limits<int>::max();
		}
	}

	priority_queue<pair<int, pair<int, int>>> Q; // time, cnt, clip
	Q.push({0, {1, 0}});
	visit[1][0] = 0;

	while (Q.empty() == false)
	{
		int time = -Q.top().first;
		int cnt = Q.top().second.first;
		int clip = Q.top().second.second;
		Q.pop();

		if (cnt == S)
		{
			cout << time << endl;
			break;
		}

		int ntime = time + 1;
		for (int i = 0; i < 3; ++i)
		{
			int ncnt = cnt;
			int nclip = clip;
			if (i == 0) // 복사
			{
				if (ncnt == nclip)
					continue;
				nclip = ncnt;
			}
			else if (i == 1) // 붙여넣기
			{
				ncnt += nclip;
				if (ncnt > 1000) continue;
			}
			else if (i == 2) // 1빼기
			{
				ncnt -= 1;
				if (ncnt < 1) continue;
			}

			if (visit[ncnt][nclip] > ntime)
			{
				visit[ncnt][nclip] = ntime;
				Q.push({-ntime, {ncnt, nclip}});
			}
			
		}
	}

	return 0;
}
