#include <iostream>
#include <vector>
using namespace std;
int n, m, a, b, res = -1;
vector<int> ary[101];
bool visited[101];

void dfs(int depth, int cur, int end) {
    visited[cur] = true;
    if(cur == end) { // 도착함
        res = depth;
    }
    int size = ary[cur].size();
    for(int i=0; i<size; ++i) {
        if(!visited[ary[cur][i]]) { // 아직 방문 안한경우
            dfs(depth+1, ary[cur][i], end);
        }
    }
    
}
int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;

    cin >> n >> a >> b >> m;
    for(int i=0; i<m; ++i) {
        cin >> x >> y;
        ary[x].push_back(y);
        ary[y].push_back(x);
    }

    dfs(0, a, b);
    cout << res << "\n";
    return 0;
}
