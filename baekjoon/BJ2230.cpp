#include <iostream>
#include <algorithm>
using namespace std;
int N, M, A[100001];
int main(void)
{
	int tmp, start=1, end=1, res = 2'100'000'000;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	sort(&A[1], &A[N+1]);
	for (start = 1, end = 2; end <= N; ++end) {
		tmp = A[end] - A[start];
		//cout << "start: " << A[start] << ", end:" << A[end] << ", Â÷ÀÌ:" << tmp << endl;
		if (tmp == M) {
			cout << M << "\n";
			return 0;
		}
		else if (tmp > M) {
			if (res > tmp) res = tmp;
			if (res > M) {
				++start;
				end--;
			}
		}
	}
	cout << res << "\n";
	return 0;
}