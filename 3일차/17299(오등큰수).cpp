#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int A[1'000'001]{};
int F[1'000'001]{};
int NGF[1'000'001]{};

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
		++F[A[i]];
	}

	stack<int> s;
	for (int i = N; i >= 1; --i)
	{
		while (!s.empty() && F[A[i]] >= F[s.top()])
			s.pop();

		if (s.empty())
		{
			NGF[i] = -1;
			s.push(A[i]);
			continue;
		}

		NGF[i] = s.top();
		s.push(A[i]);
	}

	for (int i = 1; i <= N; ++i)
		cout << NGF[i] << " ";
	cout << endl;

	return 0;
}