#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dy[4]{ 0,0,1,-1 };
int dx[4]{ 1,-1,0,0 };

int N;
int map[25][25]{};

vector<int> clusters;
int curCnt = 0;

void dfs(int y, int x)
{
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;
		if (map[ny][nx] != 1)
			continue;

		map[ny][nx] = 2;
		++curCnt;
		dfs(ny, nx);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string row;
		cin >> row;
		for (int j = 0; j < row.size(); ++j)
			map[i][j] = row[j] - 48;
	}


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == 1)
			{
				map[i][j] = 2;
				curCnt = 1;
				dfs(i, j);
				clusters.push_back(curCnt);
			}
		}
	}

	cout << clusters.size() << endl;
	sort(clusters.begin(), clusters.end());
	for (auto& e : clusters)
		cout << e << endl;


	return 0;
}