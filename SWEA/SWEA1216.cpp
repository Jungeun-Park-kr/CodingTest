#pragma warning (disable:4996)
#include<iostream>
#include <cstdio>
using namespace std;
char words[100][100];
int N = 100, word_length, max_length;
bool checkHorizontal(int y, int x) { // ���� ��
	int lidx = 0;	int ridx = word_length - 1; int hidx = word_length / 2;
	for (; lidx <= hidx; ++lidx, --ridx) { // ���������� ���ϸ鼭 ���� ���� ������ Ȯ��(1/2���̱���)
		// cout << "��:" << words[y][x + lidx] << ", ��:" << words[y][x + lidx];
		if (words[y][x + lidx] != words[y][x + ridx]) {
			//cout << "Ʋ��) ";
			//cout << "��:" << words[y][x + lidx] << ", ��:" << words[y][x + ridx];
			return false;
		}
	}
	return true;
}
bool checkVertical(int y, int x) {
	int uidx = 0;	int didx = word_length - 1; int hidx = word_length / 2;
	for (; uidx <= hidx; ++uidx, --didx) { // ���������� ���ϸ鼭 ���� ���� ������ Ȯ��(1/2���̱���)
		if (words[y + uidx][x] != words[y + didx][x]) {
			return false;
		}
	}
	return true;
}
int main(void)
{
	int test_case;
	int T = 10, res = 0, t;
	freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= T; ++test_case, res = 0)
	{
		scanf("%d\n", &t); // tc ��ȣ (�ʿ�X)

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				words[i][j] = getchar();
			}
			getchar();
		}

		bool isexists = false;
		// ȸ�� ���� �ִ� ���ϱ�
		for (word_length = N; word_length > 0; --word_length) {
			int check_num = N - word_length; // Ȯ���ؾ� �ϴ� Ƚ��
			for (int i = 0; i < N; ++i) { // ����Ȯ��
				for (int j = 0; j <= check_num; ++j) {
					if (checkHorizontal(i, j)) {
						isexists = true;
						break;
					}
				}
				if (isexists) break;
			}
			for (int i = 0; i <= check_num; ++i) { // ����Ȯ��
				for (int j = 0; j < N; ++j) {
					if (checkVertical(i, j)) {
						isexists = true;
						break;
					}
				}
				if (isexists) break;
			}
			if (isexists) break;
		}
		cout << "#" << test_case << " " << word_length << "\n";
	}
	return 0;
}