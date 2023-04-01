#include<iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i, cout << "\n") {
		for (int j = 1; j <= n - i; ++j) cout << " ";
		for (int j = 1; j <= i; ++j) cout << "*";
	}
	return 0;
}
