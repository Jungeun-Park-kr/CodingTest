#include <stdio.h>
int pow[31] = { 0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607, 16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823};
int main(int argc, char** argv){
	int test_case, T, N;
	unsigned int M;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d %d", &N, &M);
		if ((M & pow[N]) == pow[N]) printf("#%d ON\n", test_case);
		else printf("#%d OFF\n", test_case);
	}
	return 0;
}