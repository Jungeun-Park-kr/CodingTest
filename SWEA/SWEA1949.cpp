#pragma warning(disable:4996)
#include<iostream>
using namespace std;
int N, K, mountain[9][9], max_height, max_len;
bool visited[9][9];
void dfs(int y, int x, bool used_k, int len) {
	if (len > max_len) max_len = len;
	int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 }, new_y, new_x;
	for (int i = 0; i < 4; ++i) {
		new_y = y + dy[i];	new_x = x + dx[i];
		if (new_y >= N || new_y < 0 || new_x >= N || new_x < 0)	continue;
		if (!visited[new_y][new_x] && mountain[new_y][new_x] < mountain[y][x]) { // 더 작은 길로만 등산로 가능
			visited[new_y][new_x] = true;
			dfs(new_y, new_x, used_k, len+1);
			visited[new_y][new_x] = false; // backtracking
		} else if (!visited[new_y][new_x] && mountain[new_y][new_x] >= mountain[y][x] && used_k == false && ((mountain[new_y][new_x]-K) < mountain[y][x])) { // k만큼 깎기 한번 사용가능
			int sub;
			for (int j = 1; j <= K; ++j) { // 깎을 수 있는 최대 높이가 K 이므로 최소만큼 깎아야 함
				if (mountain[y][x] > mountain[new_y][new_x] - j) {
					sub = j;
					break;
				}
			}
			mountain[new_y][new_x] -= sub;
			visited[new_y][new_x] = true;
			dfs(new_y, new_x, true, len+1);
			visited[new_y][new_x] = false; // backtracking
			mountain[new_y][new_x] += sub; // backtracking
		}
	}
}
int main(int argc, char** argv)
{
	int test_case, T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case, max_height = 0, max_len = 0)
	{
		cin >> N >> K;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> mountain[i][j];
				if (mountain[i][j] > max_height) max_height = mountain[i][j];
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (!visited[i][j] && mountain[i][j] == max_height) {
					visited[i][j] = true;
					dfs(i, j, false, 1);
					visited[i][j] = false; // backtracking
				}
			}
		}
		
		cout << "#" << test_case << " " << max_len << "\n";
	}
	return 0;
}