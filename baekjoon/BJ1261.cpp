#pragma warning(disable:4996)
#include <iostream>
#include <deque>
#define MAX 9999
using namespace std;
int N, M, visited[100][100];
bool map[100][100];
void bfs(int y, int x) {
	int dx[4] = { 0,1,-1,0 }, dy[4] = { 1,0,0,-1 }, new_y, new_x;
	pair<int, int> tmp;  deque<pair<int, int>> q; // �Ϲ� queue���� �޸� �ʰ��� ��
	q.push_front({ y, x });
	while (!q.empty()) {
		tmp = q.front(); q.pop_front();
		if (tmp.first == N - 1 && tmp.second == M-1) return; // �������� üũ
		for (int i = 0; i < 4; ++i) {
			new_y = tmp.first + dy[i]; new_x = tmp.second + dx[i];
			if (new_y < 0 || new_x < 0 || new_y >= N || new_x >= M || visited[new_y][new_x]!= MAX) continue; //���� üũ

			if (map[new_y][new_x]) { // �� �ν��� �ϴ� ���
				visited[new_y][new_x] = visited[tmp.first][tmp.second] + 1; // �ڿ� �־���
				q.push_back({ new_y, new_x });
			}
			else { // ���� ���� ���
				visited[new_y][new_x] = visited[tmp.first][tmp.second];
				q.push_front({ new_y, new_x }); // �տ� �־��� (���� Ž���ϵ���)
			}

		}
	}
}
int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> M >> N;
	string line;
	for (int i = 0; i < N; ++i) {
		cin >> line;
		for (int j = 0; j < M; ++j) {
			map[i][j] = line[j] == '1' ? true : false;
			visited[i][j] = MAX;
		}
	}
	visited[0][0] = 0;
	bfs(0, 0);

	/*cout << "---- ��� Ȯ�� ----\n";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << visited[N - 1][M - 1] << "\n";
	return 0;
}