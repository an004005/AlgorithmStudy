#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N, K;
int dp[101][100001]; // dp[���ǹ�ȣ][����] = �ִ� ��ġ
pair<int, int> items[101];// ����, ��ġ

int main()
{
	cin >> N >> K;
	int W, V;
	for (int i = 1; i <= N; ++i)
	{
		cin >> W >> V;
		items[i] = { W, V }; 
	}

	for (int i = 0; i <= N; ++i)// ���� ��ȣ(i�� ���� ������ ����Ͽ� �ִ´�.)
	{
		for (int w = 0; w <= K; ++w) // ��ƿ �� �ִ� ����
		{
			int itemW = items[i].first;
			int itemV = items[i].second;

			if (w == 0 || i == 0)
				dp[i][w] = 0;
			else if (itemW > w) // �������� ���԰� �� ���� ���� ���ſ�� ���� ������ ���� ������ ���
				dp[i][w] = dp[i - 1][w];
			else if (itemW <= w) // �������� ���԰� �� ���Կ� ���ų� �������, ���� ������ ���� ������ ��밪�� ���� dp���� �� ������ ���Ը� �u ��ġ�� �� �������� ���� �� ��
				dp[i][w] = std::max(itemV + dp[i - 1][w - itemW], dp[i - 1][w]);
		}
	}

	cout << dp[N][K] << endl;



	return 0;
}