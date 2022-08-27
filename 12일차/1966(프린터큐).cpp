#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Node
{
	bool bTarget = false;
	int Priority = 0;
	Node(bool bTarget, int Priority) : bTarget(bTarget), Priority(Priority) {}
};

list<Node> Q;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		Q.clear();
		for (int i = 0; i < N; ++i)
		{
			int p;
			cin >> p;
			Q.push_back({ M == i, p });
		}

		int order = 0;

		while (true)
		{
			Node poped = Q.front();
			Q.pop_front();

			bool bCheck = false;
			for (auto& node : Q)
			{
				if (poped.Priority < node.Priority)
				{
					bCheck = true;
					break;
				}
			}
			if (bCheck)
			{
				Q.push_back(poped);
				continue;
			}

			++order;
			if (poped.bTarget)
			{
				cout << order << endl;
				break;
			}
		}
	}


	return 0;
}