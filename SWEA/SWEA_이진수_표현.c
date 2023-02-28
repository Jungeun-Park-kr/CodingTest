#pragma warning(disable:4996)
#include <stdio.h>
int main(int argc, char** argv){
	int test_case, T, N, M;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d %d", &N, &M);
		int lastNBit = (1 << (N)) - 1;  // 111...1 (±æÀÌ N)
		//printf("N: %d, M:%d\npow[N]:%30x\nM&pow[N]:%30x", N, M, pow[N], (M&pow[N]));
		if ((M & lastNBit) == lastNBit) printf("#%d ON\n", test_case);
		else printf("#%d OFF\n", test_case);
	}
	return 0;
}