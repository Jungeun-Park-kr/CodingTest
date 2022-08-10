#pragma warning (disable:4996)
#include <iostream>
#include <cstring>
using namespace std;
int N, M;
int iceberg[300][300];
bool isexist[300][300];
bool visited[300][300];

void checkIceberg(int y, int x) {
	if (visited[y][x])	return;
	visited[y][x] = true;
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };
	int new_y, new_x;
	for (int i = 0; i < 4; ++i) {
		new_y = y + dy[i];
		new_x = x + dx[i];
		if (!visited[new_y][new_x] && iceberg[new_y][new_x] != 0) {
			checkIceberg(new_y, new_x);
		}
	}
}
void melt(int y, int x) {
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };
	int new_y, new_x;
	for (int i = 0; i < 4; ++i) {
		new_y = y + dy[i];
		new_x = x + dx[i];
		if (!isexist[new_y][new_x] && (iceberg[y][x] > 0) && (iceberg[new_y][new_x] == 0)) {
			iceberg[y][x]--;
		}
	}
}
int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> iceberg[i][j];
			if (iceberg[i][j] != 0) isexist[i][j] = true;
		}
	}

	int year;
	int iceberg_cnt = 0;
	for(year = 1; ; ++year){
		iceberg_cnt = 0;
		// 녹는것 확인
		for (int i = 1; i < N - 1; ++i) {
			for (int j = 1; j < M - 1; ++j) {
				if (isexist[i][j] && iceberg[i][j]!=0) {
					//cout << i << "," << j << "녹이기\n";
					melt(i, j);
				}
			}
		}
		// 분리된 것 확인
		iceberg_cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (iceberg[i][j] != 0 && !visited[i][j]) {
					checkIceberg(i, j);
					++iceberg_cnt;
				}
				if (iceberg_cnt > 1) break;
			}
			if (iceberg_cnt > 1) break;
		}
		if (iceberg_cnt == 0) { // 다 녹아도 분리안됨
			cout << 0 << "\n";
			return 0;
		} else if (iceberg_cnt > 1) { // 분리됨
			break;
		} else { // isexist, visited 갱신
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (iceberg[i][j] != 0) isexist[i][j] = true;
					else isexist[i][j] = false;
					visited[i][j] = false;
				}
			}
		}

		//cout << "------------------------------\n";
		//cout << "개수:" << iceberg_cnt << "\n";
		//for (int i = 0; i < N; ++i, cout << endl)
		//	for (int j = 0; j < M; ++j)
		//		cout << iceberg[i][j] << " ";
	}

	//cout << "------------------------------\n";
	//cout << "개수:" << iceberg_cnt << "\n";
	//for (int i = 0; i < N; ++i, cout << endl)
	//	for (int j = 0; j < M; ++j)
	//		cout << iceberg[i][j] << " ";
	cout <<  year << "\n";

	return 0;
}