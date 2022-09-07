#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int N = 100;
int main(void)
{
	int test_case;
	int T = 10;
	int tmp, dump;
	// freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector <int> box;
		cin >> dump;
		for (int i = 0; i < N; ++i) {
			cin >> tmp;
			box.push_back(tmp);
		}

		for (int i = 0; i < dump; ++i) { // dump È½¼ö¸¸Å­ ¹Ýº¹
			sort(box.begin(), box.end()); // Á¤·Ä
			box[0]++; // ÃÖ¼Ú°ª+1
			box[N - 1]--; // ÃÖ´ñ°ª-1
		}
		sort(box.begin(), box.end());
		cout << "#" << test_case << " " << box[N - 1] - box[0] << "\n"; // ÃÖ´ñ°ª-ÃÖ¼Ú°ª Ãâ·Â

	}
	return 0;
}