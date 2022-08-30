#include <iostream>
#include <queue>
using namespace std;
int M, N, tomato[1000][1000], day, raped_cnt;
queue<pair<int, int>> raped; queue<pair<int, int>> next_raped;
void bfs() {
	int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 }, new_y, new_x;
	pair<int, int> tmp;
	while (true) {
		raped = next_raped;
		next_raped = queue<pair<int, int>>();
		if (raped.size() == 0) break;
		++day;
		while (!raped.empty()) {
			tmp = raped.front(); raped.pop();
			for (int i = 0; i < 4; ++i) {
				new_y = tmp.first + dy[i]; new_x = tmp.second + dx[i];
				if (new_y < N && new_x < M && new_x >= 0 && new_y >= 0 && tomato[new_y][new_x] == 0) {
					tomato[new_y][new_x] = 1;
					next_raped.push({ new_y, new_x });
					++raped_cnt; //토마토 익는 개수 카운트
				}
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
			if (tomato[i][j] == 1) next_raped.push({ i,j }); // 익은 토마토 넣어두기
			else if (tomato[i][j] == 0) ++zero_cnt;
		}
	}

	if (zero_cnt == 0) cout << "0\n"; // 처음부터 모든 토마토가 익어있음
	else {
		bfs();
		if (raped_cnt == zero_cnt) cout << day-1 << "\n";
		else cout << "-1\n"; // 토마토가 모두 익지 못함
	}
	return 0;
}