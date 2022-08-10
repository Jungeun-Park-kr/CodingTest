#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int test_case;
	int T=10, t;
	freopen("input.txt", "r", stdin);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int cnt = 0;
		char str[1000], search[10];
		scanf("%d\n%s\n%s\n", &t, search, str);
		//printf("%d\n%s\n%s\n", t, search, str);
		
		char *ptr = strstr(str, search);
		while (ptr != NULL) {
			++cnt;
			ptr = strstr(ptr+1, search);
		}
		printf("#%d %d\n", test_case, cnt);
	}
	return 0;
}