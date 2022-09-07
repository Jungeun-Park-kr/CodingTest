#include <stdio.h>
int mypow(int n, int m) {
    if(m==1)    return n; // 종료 조건
    return n*mypow(n, m-1);
}
int main(void) {
	int test_case;
	int T = 10, t, N, M;
	freopen("input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case) {   
        scanf("%d\n%d %d\n", &t, &N, &M);
        printf("#%d %d\n", test_case, mypow(N,M));
	}
	return 0;
}