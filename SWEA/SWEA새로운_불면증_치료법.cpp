#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv)
{
	bool number[10];
	bool hasAllNumber = true;
	string str;
	int test_case, T, k, N;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(number, false, sizeof(int) * 10);
		cin >> N;
		for (k = 1; ; ++k) {
			hasAllNumber = true;
			str = to_string(N*k);
			cout <<"k:"<<k<< ", str:" << str << endl;
			int size = str.length();
			for (int i = 0; i < size; ++i) {
				number[str[i] - '0'] = true;
			}
			for (int i = 0; i < 10; ++i) {
				if (!number[i]) {
					hasAllNumber = false;
					break;
				}
			}
			if (hasAllNumber) break;
		}
		cout << "#" << test_case << " " << N*k << "\n";
	}
	return 0;
}
