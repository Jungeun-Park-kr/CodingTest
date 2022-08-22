#pragma warning(disable: 4996)
#include <iostream>
#include <algorithm>
using namespace std;
int N, A[1002], DP[1002];
int main(void)
{
	int tmp = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) 
		cin >> A[i];

	DP[0] = 1;
	for (int i = 1; i < N; ++i, tmp = 0) {
		for (int j = 0; j < i; ++j) {
			if (A[i] > A[j]) {
				if (tmp < DP[j]) {
					tmp = DP[j];
				}
			}
		}
		DP[i] = tmp + 1;
	}
	cout << *max_element(DP, DP + N) << "\n";
	return 0;
}