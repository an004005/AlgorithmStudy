#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int M, N;

constexpr int MAX = 1'000'001;
bool prime[MAX]{};
void eratosthenes() 
{
	prime[2] = true;
	for (int i = 3; i<MAX; i += 2)
		prime[i] = true;

	for (int i = 3; i <= N; i += 2) //2�� ���� ���� ¦���� �˻����� �ʾƵ� �ȴ�.
		if (prime[i] == true) {
			int j = i*i;
			if (j >= MAX) break;
			for (i *= 2; j<MAX; j += i) {//i�� 2��� �Ͽ� i�� ¦������ ���� �˻����� �ʰ� �Ѵ�.
				prime[j] = false;
			}
			i /= 2;//i ���󺹱�
		}
}

int main()
{
	cin >> M >> N;
	eratosthenes();
	if (M % 2 == 0)
		++M;

	for (int i = M; i <= N; i += 2)
	{
		if (prime[i])
			cout << i << endl;
	}


	return 0;
}