#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool btn[10]{};
int minCnt = 0;
string ch = "";

void dfs(int depth)
{
	if (depth == 0)
		return;

	for (int i = 0; i < 10; ++i)
	{
		if (btn[i]) continue;

		ch.push_back(i + 48);
		int chnum = stoi(ch);
		int chsize = 0;
		for (size_t j = 0; j < ch.size(); ++j)
			if (ch[j] != 0) chsize++;
		minCnt = std::min(minCnt, abs(chnum - N) + chsize);
		dfs(depth - 1);
		ch.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int m;
		cin >> m;
		btn[m] = true;  // broken
	}
	minCnt = abs(N - 100);

	int normalBtn = 0;
	for (int i = 0; i < 10; ++i)
		if (!btn[i]) normalBtn++;
	if (normalBtn == 0)
	{
		cout << minCnt << endl;
		exit(0);
	}

	// N <= 500000

	string chstr = to_string(N);
	//dfs(chstr.size());
	dfs(6);

	cout << minCnt << endl;
	return 0;
}