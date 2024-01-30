#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;
int N, K, answer, parent[MAX], depth[MAX];
vector <pair<int,int>> path;
bool visited[MAX];
void bfs() {
	queue <pair<int, int> > q;
	int time, cur;
	q.push({ N, 0 });
	depth[N] = 0;
	parent[N] = -1;
	visited[N] = true;
	while (!q.empty()) {
		cur = q.front().first; time = q.front().second; q.pop();
		//cout << "cur :" << cur << ", depth: "<<time << ", parent: "<< parent[cur] << endl;
		if (cur == K) {
			answer = time;
			return;
		}
		for (int i : {cur - 1, cur + 1, cur * 2}) {
			if (i < 0 || i >= MAX) continue;
			if (!visited[i]) {
				visited[i] = true;
				q.push({ i, time + 1 });
				if (depth[i] > time+1) { // 더 최단경로일때만 경로 저장
					depth[i] = time + 1;
					parent[i] = cur;
				}
			}
		}
	}
}
int main(void) {
	cin >> N >> K;
	fill(&depth[0], &depth[MAX], 9999999);
	bfs();
	cout << answer << "\n"; // 최단거리
	// 경로 출력
	vector <int> path;
	int cur = parent[K];
	while (cur != -1) { // 도착지부터 출발지 까지 역으로 벡터에 넣기
		path.push_back(cur);
		cur = parent[cur];
	}
	for (int i = path.size()-1; i > -1; --i) cout << path[i] << " "; // 역순 출력
	cout << K << "\n";
	return 0;
}
