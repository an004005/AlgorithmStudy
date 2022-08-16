#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
using namespace std;

int Set = 0;

/*
00000000'00000000'00000000'00000001 : 1
00000000'00000000'00000000'00000010 : 2
00000000'00000000'00000000'00000100 : 3
....
*/

int main()
{
	int M;
	scanf("%d", &M);

	char buf[8];
	int x = 0;
	while (M--)
	{
		scanf("%s", buf, sizeof(buf));

		if (strcmp(buf, "add") == 0)
		{
			scanf("%d", &x);
			Set |= (1 << x);
		}
		else if (strcmp(buf, "remove") == 0)
		{
			scanf("%d", &x);
			Set &= ~(1 << x);
		}
		else if (strcmp(buf, "check") == 0)
		{
			scanf("%d", &x);
			if (Set & (1 << x)) printf("%d\n", 1);
			else printf("%d\n", 0);
		}
		else if (strcmp(buf, "toggle") == 0)
		{
			scanf("%d", &x);
			Set ^= (1 << x);
		}
		else if (strcmp(buf, "all") == 0)
		{
			Set = ~0; // 4byte
		}
		else if (strcmp(buf, "empty") == 0)
		{
			Set = 0;
		}
	}
	return 0;
}