#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define NUM 105
using namespace std;
int T, N, homeX, homeY, destX, destY; // -32768 ≤ x, y ≤ 32767
bool visited[NUM];
pair <int, int> location[NUM]; // 편의점 위치

bool check() {
	queue <pair<int, int>> q; pair<int, int> tmp; int newY, newX;
	q.push({ homeY, homeX });
	while (!q.empty()) {
		tmp = q.front(); q.pop();
		if (abs(destY - tmp.first) + abs(destX - tmp.second) <= 1000) { // 맥주 20개인 시점부터 1000미터 이내 도착 가능 => 정답
			return true;
		}
		for (int i = 0; i < N; ++i) {
			newY = location[i].first; newX = location[i].second;
			if (!visited[i] && (abs(newY-tmp.first)+abs(newX-tmp.second) <= 1000)) {
				q.push({ newY, newX });
				visited[i] = true;
			}
		}
	}
	return false;
}
int main(void) {
	int y, x;
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		memset(visited, false, sizeof(visited));
		cin >> N >> homeX >> homeY;
		for (int i = 0; i < N; ++i) { // 편의점 좌표
			cin >> x >> y;
			location[i] = { y, x };
		}
		cin >> destX >> destY;
		if (check()) cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}