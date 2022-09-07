#pragma warning(disable:4996)
#include<iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int N = 16;
pair<int, int> mstart; pair<int, int> mend;
bool visited[16][16], mirror[16][16];
bool bfs(int y, int x) {
	queue<pair<int, int>> q; pair<int, int> tmp;
	int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 }, new_y, new_x;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	while (!q.empty()) {
		tmp = q.front(); q.pop();
		//cout << tmp.first << "," << tmp.second << endl;
		if (tmp.first == mend.first && tmp.second == mend.second) { return true; }
		for (int i = 0; i < 4; ++i) {
			new_y = tmp.first + dy[i];	new_x = tmp.second + dx[i];
			//cout << "new_y: " << new_y << ", new_x: " << new_x << endl;
			if (new_y >= 0 && new_x >= 0 && new_y < N && new_x < N && !visited[new_y][new_x] && mirror
				[new_y][new_x] == 0) {
				
				q.push(make_pair(new_y, new_x));
				visited[new_y][new_x] = true;
			}
		}
	}
	return false;
}
int main(void)
{
	int test_case;
	int T = 10, t;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d\n", &t);
		//cout << "t:" << t << endl;
		char tmp;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				tmp = getchar();
				//cout << tmp << endl;
				if (tmp == '1') mirror[i][j] = true;
				else if (tmp == '0') mirror[i][j] = false;
				else if (tmp == '2') { mstart.first = i; mstart.second = j; mirror[i][j] = false; }
				else if (tmp == '3') { mend.first = i, mend.second = j; mirror[i][j] = false; }
			}
			getchar();
		}
		/*cout << "start: (" << mstart.first << "," << mstart.second << "), end: (" << mend.first << "," << mend.second << ")\n";
		cout << "-----------\n";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << mirror[i][j] << " ";
			}
			cout << endl;
		}
		cout << "-----------\n";*/
		cout << "#" << test_case << " " << bfs(mstart.first, mstart.second) << "\n";
		memset(mirror, 0, sizeof(mirror));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}