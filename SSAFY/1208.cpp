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

		for (int i = 0; i < dump; ++i) { // dump Ƚ����ŭ �ݺ�
			sort(box.begin(), box.end()); // ����
			box[0]++; // �ּڰ�+1
			box[N - 1]--; // �ִ�-1
		}
		sort(box.begin(), box.end());
		cout << "#" << test_case << " " << box[N - 1] - box[0] << "\n"; // �ִ�-�ּڰ� ���

	}
	return 0;
}