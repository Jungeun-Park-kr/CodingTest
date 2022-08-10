#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N = 100;
int ladder[100][100];
bool visited[100][100];
int res;
void search(int y, int x) { // ��ٸ��� �Ʒ������� ���� Ž���ذ�
	if (visited[y][x]) return ;
	if (y == 0 && ladder[y][x] == 1) { 
		res = x;
		return;
	}
	visited[y][x] = true; // �Դ��� ���� �ȵ�
	if (x - 1 >= 0 && (ladder[y][x - 1] == 1 && !visited[y][x - 1])) { // ��ٸ� ���ʺ��� Ȯ�� (����)
		search(y, x - 1);
	} else if (x + 1 < N && (ladder[y][x + 1] == 1 && !visited[y][x + 1])) { // (������)
		search(y, x + 1);
	} else if (y-1 >= 0 && (ladder[y - 1][x] == 1 && !visited[y-1][x])) { // ���� ������ ����
		search(y - 1, x);
	}
}
int main(void)
{
	int test_case;
	int T = 10, t;
	pair<int, int> goal;
	// freopen("input.txt", "r", stdin);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> t;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				visited[i][j] = false;
				cin >> ladder[i][j];
				if (i==N-1 && ladder[i][j] == 2) { // �������� ����ص�
					goal.first = i;
					goal.second = j;
				}
			}
		}
		search(goal.first, goal.second); // �������κ��� ���� �ö�
		cout << "#" << test_case << " " << res << "\n";
	}
	return 0;
}