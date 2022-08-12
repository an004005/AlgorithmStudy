#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N, K;
int dp[101][100001]; // dp[물건번호][무게] = 최대 가치
pair<int, int> items[101];// 무게, 가치

int main()
{
	cin >> N >> K;
	int W, V;
	for (int i = 1; i <= N; ++i)
	{
		cin >> W >> V;
		items[i] = { W, V }; 
	}

	for (int i = 0; i <= N; ++i)// 물건 번호(i번 까지 물건을 사용하여 넣는다.)
	{
		for (int w = 0; w <= K; ++w) // 버틸 수 있는 무게
		{
			int itemW = items[i].first;
			int itemV = items[i].second;

			if (w == 0 || i == 0)
				dp[i][w] = 0;
			else if (itemW > w) // 아이템의 무게가 현 무게 보다 무거우면 같은 무게의 이전 아이템 사용
				dp[i][w] = dp[i - 1][w];
			else if (itemW <= w) // 아이템의 무게가 현 무게와 같거나 가벼우면, 같은 무게의 이전 아이템 사용값과 이전 dp에서 현 아이템 무게를 뻰 가치에 현 아이템을 넣은 값 비교
				dp[i][w] = std::max(itemV + dp[i - 1][w - itemW], dp[i - 1][w]);
		}
	}

	cout << dp[N][K] << endl;



	return 0;
}