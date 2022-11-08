#include <iostream>
using namespace std;
int N, M, k;
int A[10001], parent[10001];
void unionParent(int a, int b);
int getParent(int a);
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (A[a] < A[b]) {
		parent[b] = a; // 더 싼 애가 부모되기
		A[b] = 0;
	}
	else {
		parent[a] = b;
		A[a] = 0;
	}
}
int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]);
}
int main(void) {
	int tmp1, tmp2;
	cin >> N >> M >> k;
	for (int i = 1; i <= N; ++i) parent[i] = i;
	for (int i = 1; i <= N; ++i) cin >> A[i];
	for (int i = 0; i < M; ++i) {
		cin >> tmp1 >> tmp2;
		unionParent(tmp1, tmp2);
	}
	tmp1 = 0;
	for (int i = 1; i <= N; ++i) tmp1 += A[i];
	if (tmp1 > k) cout << "Oh no\n";
	else cout << tmp1 << "\n";
	return 0;
}