#include <iostream>
using namespace std;
int n, m;
int parent[500'001];
int getParent(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getParent(parent[a]); // 경로압축
}
bool unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true; // 부모 같음 => acyclic!! (종료조건)
	else if (a < b) parent[b] = a; // a, b 둘 중 더 작은 애가 부모됨
	else parent[a] = b;
	return false;
}
int main(void)
{
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) parent[i] = i;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		if (unionParent(a, b)) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
	return 0;
}