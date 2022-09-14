#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <limits>
#include <algorithm>
using namespace std;

int N;
int S[21][21]{};

int minDiff = std::numeric_limits<int>::max();

list<int> st;

void dfs(int n, int depth)
{
	if (depth == 0)
	{
		vector<int> startTeam(st.begin(), st.end());
		vector<int> linkTeam;
		for (int i = 1; i <= N; ++i)
		{
			auto itr = std::find(startTeam.begin(), startTeam.end(), i);
			if (itr == startTeam.end())
				linkTeam.push_back(i);
		}

		int startStat = 0;
		for (size_t i = 0; i < startTeam.size(); ++i)
		{
			for (size_t j = 0; j < startTeam.size(); ++j)
			{
				if (startTeam[i] == startTeam[j]) continue;
				startStat += S[startTeam[i]][startTeam[j]];
			}
		}

		int linkStat = 0;
		for (size_t i = 0; i < linkTeam.size(); ++i)
		{
			for (size_t j = 0; j < linkTeam.size(); ++j)
			{
				if (linkTeam[i] == linkTeam[j]) continue;
				linkStat += S[linkTeam[i]][linkTeam[j]];
			}
		}

		if (minDiff > abs(startStat - linkStat))
			minDiff = abs(startStat - linkStat);

		return;
	}

	for (int i = n ; i <= N; ++i)
	{
		st.push_back(n);
		dfs(i + 1, depth - 1);
		st.pop_back();
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> S[i][j];
		}
	}

	dfs(1, N / 2);
	cout << minDiff << endl;

	return 0;
}
