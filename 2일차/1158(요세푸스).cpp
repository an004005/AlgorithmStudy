#include<iostream>
#include<queue>
#include<list>
using namespace std;

int main()
{
	queue<int> circle;
	list<int> out;
	
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		circle.push(i);

	while (!circle.empty())
	{
		for (int i = 0; i < K-1; ++i)
		{
			circle.push(circle.front());
			circle.pop();
		}
		out.push_back(circle.front());
		circle.pop();
	}
	cout << '<';
	for (auto& e : out)
	{
		if (e == out.front())
		{
			cout << e;
		}
		else
		{
			cout << ", " << e;
		}

	}

	cout << '>';

	return 0;
}