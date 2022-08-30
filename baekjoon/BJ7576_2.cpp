#include <iostream>
#include <queue>
using namespace std;
int M, N, tomato[1000][1000];
bool visited[1000][1000];
queue<pair<int, int>> raped;
void bfs() {
	int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 }, new_y, new_x;
	pair<int, int> tmp;
	while (!raped.empty()) {
		tmp = raped.front(); raped.pop();
		visited[tmp.first][tmp.second] = true;
		for (int i = 0; i < 4; ++i) {
			new_y = tmp.first + dy[i]; new_x = tmp.second + dx[i];
			if (new_y < N && new_x < M && new_x >= 0 && new_y >= 0 && tomato[new_y][new_x] == 0 && !visited[new_y][new_x]) {
				tomato[new_y][new_x] = tomato[tmp.first][tmp.second]+1; // �ʹ� �ϼ� �����ֱ�
				raped.push({ new_y, new_x });
			}
		}
	}
}
int main(void)
{
	int zero_cnt = 0;
	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) raped.push({ i,j }); // ���� �丶�� �־�α�
			else if (tomato[i][j] == 0) ++zero_cnt;
		}
	}

	if (zero_cnt == 0) { // ó������ ��� �丶�䰡 �;�����
		cout << "0\n"; 
		return 0;
	}
	bfs();
	int day = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (tomato[i][j] == 0) { // �丶�� ��� ������
				cout << "-1\n";
				return 0;
			}
			if (tomato[i][j] > day) day = tomato[i][j]; // ��� �丶�䰡 ���� �� ã��
		}
	}
	cout << day-1 << "\n";
	return 0;
}