#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
int arr[1'000'001]{};
int nge[1'000'001]{};

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];

	stack<int> s;

	for (int i = N ; i > 0; --i)
	{
		while (!s.empty() && arr[i] >= s.top())
			s.pop();

		if (s.empty())
		{
			nge[i] = -1;
			s.push(arr[i]);
			continue;
		}

		nge[i] = s.top();
		s.push(arr[i]);
	}

	for (int i = 1; i <= N; ++i)
		cout << nge[i] << " ";
	cout << endl;

	return 0;
}