#include <iostream>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i, cout << "\n") {
		for(int j=1; j<=i; ++j) cout << "*";
	}
	return 0;
}