#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
bool contact[101][101];
int visited[101];
int N, start;
int max_v, max_d;
void bfs(int v) {
	queue<int> q;
	int tmp;
	q.push(v);
	visited[v] = 0;
	while (!q.empty()) {
		tmp = q.front(); q.pop();
		for (int i = 1; i < 101; ++i) {
			if (visited[i]==0 && contact[tmp][i]) {
				//cout << i << " ";
				q.push(i);
				visited[i] = visited[tmp]+1;
				if (visited[i] > max_d) max_d = visited[i];
			}
		}
		//cout << endl;
	}
}
int main(void)
{
	int test_case;
	int T = 10, tmp1, tmp2;
	freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= T; ++test_case, max_v = 0, max_d = 0)
	{
		//cin >> N >> start;
		scanf("%d %d\n", &N, &start);
		memset(visited, 0, sizeof(visited));
		memset(contact, false, sizeof(contact));
		int half = N / 2;
		for (int i = 0; i < half; ++i) {
			//cin >> tmp1 >> tmp2;
			scanf("%d%d", &tmp1, &tmp2);
			//cout << tmp1 << ", "<<tmp2<<endl;
			contact[tmp1][tmp2] = true;
		}

		//cout << "start:" << start << endl;
		bfs(start);
		/*for (int i = 1; i < 101; ++i) {
			cout << visited[i] << " ";
		}
		cout << endl;*/

		for (int i = 1; i < 101; ++i) {
			if (visited[i] == max_d && i > max_v)	max_v = i;
		}
		//cout << "max_depth:" << max_d << endl;
		cout << "#" << test_case << " " << max_v << "\n";
	}
	return 0;
}