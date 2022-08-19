#pragma warning(disable:4996)
#include<iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 999999999
using namespace std;
int N, M;
vector <int> oper;
int num[13], num_tmp[13];
void inputOper(int i, int tmp) {
	switch (i) {
	case 0: for (int j = 0; j < tmp; ++j) oper.push_back(0); break; // +
	case 1: for (int j = 0; j < tmp; ++j) oper.push_back(1); break; // -
	case 2: for (int j = 0; j < tmp; ++j) oper.push_back(2); break; // *
	case 3: for (int j = 0; j < tmp; ++j) oper.push_back(3); break; // /
	}
}
void calc(int idx, int n1, int op, int n2) {
	switch (op) {
	case 0: num_tmp[idx] = n1 + n2; //cout << "num[" << idx << "]:" << num_tmp[idx] << endl;  
		break;// +
	case 1: num_tmp[idx] = n1 - n2; //cout << "num[" << idx << "]:" << num_tmp[idx] << endl
		break; // -
	case 2: num_tmp[idx] = n1 * n2; //cout << "num[" << idx << "]:" << num_tmp[idx] << endl; 
		break; // *
	case 3: num_tmp[idx] = n1 / n2;// cout << "num[" << idx << "]:" << num_tmp[idx] << endl; 
		break;// /
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case, T, tmp, res, max_res=-(MAX), min_res = MAX;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case, max_res = -MAX, min_res = MAX)
	{
		cin >> N; //사용 숫자수
		for (int i = 0; i < 4; ++i) {
			cin >> tmp;
			inputOper(i, tmp); // '+', '-', '*', '/' 순서대로
		}
		for (int i = 0; i < N; ++i) {
			cin >> num[i];
		}
		// int size = oper.size();

		do {
			/*for (int i = 0; i < size; ++i) {
				calc(i + 1, num[i], oper[i], num[i + 1]);
				cout << oper[i] << " ";
			}
			cout << endl;*/
			memcpy(num_tmp, num, sizeof(int) * 13);
			for (int i = 1; i < N; ++i) {
				calc(i, num_tmp[i - 1], oper[i-1], num_tmp[i]);
			}
			res = num_tmp[N - 1];
			//cout << "res:" << res << endl;
			if (max_res < res) max_res = res;
			if (min_res > res) min_res = res;
		} while (next_permutation(oper.begin(), oper.end()));

		//cout << "max:" << max_res << ", min:" << min_res << endl;
		cout << "#"<<test_case <<" "<< max_res-(min_res) << "\n";

		oper.clear();
	}
	return 0;
} 