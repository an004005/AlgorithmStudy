#include <iostream>
#include<algorithm>
using namespace std;

int gcd(int maxNum, int minNum)
{
	int mod = maxNum % minNum;
	if (mod == 0)
		return minNum;
	else
		return gcd(minNum, mod);
}

int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	int GCD = gcd(std::max(n1, n2), std::min(n1, n2));

	cout << GCD << endl;
	cout << n1*n2 / GCD  << endl;

	return 0;
}