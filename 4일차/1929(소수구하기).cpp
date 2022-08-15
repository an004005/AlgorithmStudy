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

	for (int i = 3; i <= N; i += 2) //2씩 더해 굳이 짝수를 검색하지 않아도 된다.
		if (prime[i] == true) {
			int j = i*i;
			if (j >= MAX) break;
			for (i *= 2; j<MAX; j += i) {//i를 2배로 하여 i의 짝수곱을 굳이 검색하지 않게 한다.
				prime[j] = false;
			}
			i /= 2;//i 원상복구
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