#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int n, r;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i *= 10)
		r += n - i + 1;
	printf("%d", r);
	return 0;

}