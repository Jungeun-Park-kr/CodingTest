#pragma warning(disable:4996)
#include<iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int N = 100;
int ary[100][100];
int sumx[100];
int sumy[100];
int sumleftd;
int sumrightd;
int main(int argc, char** argv)
{
	int test_case;
	int T = 10, t;
	freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> t;
		memset(sumx, 0, sizeof(int) * 100);
		memset(sumy, 0, sizeof(int) * 100);
		sumleftd = sumrightd = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> ary[i][j];
				sumy[i] += ary[i][j]; // ���� ��
				sumx[j] += ary[i][j]; // ���� ��
				if (i == j)	sumrightd += ary[i][j]; // ������ �밢��
				if (i + j == N) sumleftd += ary[i][j]; //���� �밢�� (���� for������ ary[i][99-i]�ε���
			}
		}
		int check[4] = { *max_element(sumx, sumx + N), *max_element(sumy, sumy+N), sumrightd, sumleftd };
		for (int i = 0; i < 4; ++i) {
			cout << check[i] << " ";
		}
		cout << endl;
		cout << "#" << test_case << " " << *max_element(check, check+4) << "\n";
	}
	return 0;
}