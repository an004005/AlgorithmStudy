#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dy[4]{0,0,1,-1};
int dx[4]{1,-1,0,0};

int N, L, R;
int A[50][50]{};

bool visit[50][50]{};

int MoveDays = 0;
vector<vector<pair<int, int>>> unionCounties; // y, x


void MakeUnions(int y, int x)
{
	vector<pair<int, int>> unionCountry;
	queue<pair<int, int>> Q;

	Q.push({y, x});
	visit[y][x] = true;
	unionCountry.push_back({y, x});

	while (!Q.empty())
	{
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (visit[ny][nx])
				continue;

			const int populationDiff = abs(A[ny][nx] - A[cy][cx]);
			if (populationDiff < L || populationDiff > R)
				continue;


			visit[ny][nx] = true;
			unionCountry.push_back({ny, nx});
			Q.push({ny, nx});
		}
	}


	if (unionCountry.size() > 1)
		unionCounties.push_back(unionCountry);
}


int main()
{
	unionCounties.reserve(20);

	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
	}

	while (true)
	{
		memset(visit, 0, sizeof(visit));
		unionCounties.clear();

		for (int i = 0; i <	N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visit[i][j]) continue;
				MakeUnions(i, j);
			}
		}

		// 연합생성이 안되면 break;
		if (unionCounties.empty())
			break;

		++MoveDays;

		// 생성된 연합 인구수 재조절
		for (auto& unionCounty : unionCounties)
		{
			int population = 0;
			for (const auto& c : unionCounty)
				population += A[c.first][c.second];

			population /= static_cast<int>(unionCounty.size());

			for (const auto& c : unionCounty)
			{
				A[c.first][c.second] = population;
			}
		}
	}

	cout << MoveDays << endl;

	return 0;
}