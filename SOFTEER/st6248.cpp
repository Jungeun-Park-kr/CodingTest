#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> map[100001];
vector<int> rev_map[100001];
int check[100001];
int n, m, S, T;
bool visited[100001];

void bfs(int start, int end) {
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    visited[end] = true;
    q.push(start);
    int cur, next;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        ++check[cur];
        //cout << start << "->" << end << " - bfs cur :"<< cur<<endl;
        for(int i=0; i<map[cur].size(); i++) {
            next = map[cur][i];
            //cout << "next :" << next <<", size :"<< map[cur].size() << endl;
            if(visited[next]) continue;
            q.push(next);
            visited[next] = true;
            
        }
    }
}
void rev_bfs(int start) { // 역간선 그래프를 위한 bfs
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    q.push(start);
    int cur, next;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        ++check[cur];
        //cout << start << "->" << end << " - bfs rev cur :"<< cur << endl;
        for(int i=0; i<rev_map[cur].size(); i++) {
            next = rev_map[cur][i];
            if(visited[next]) continue;
            q.push(next);
            visited[next] = true;
        }
    }
}
int main(int argc, char** argv)
{
    int s, e, res = 0;
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        cin >> s >> e;
        map[s].push_back(e);
        rev_map[e].push_back(s);
    }
    cin >> S >> T;
    //cout << "S:"<<S<<", T:"<<T<<endl;
    // for(int i=1; i<n; i++) {
    //     cout << i << ": ";
    //     for(int j=0; j<map[i].size(); j++) {
    //         cout << map[i][j] << ", ";
    //     }
    //     cout << endl;
    // }

    bfs(S, T); // 출근길 확인
    bfs(T, S); // 퇴근길 확인
    rev_bfs(S); // 출근길 reverse 확인
    rev_bfs(T); // 퇴근길 reverse 확인
    
    for(int i=1; i<=n; ++i) {
        if(i == S || i == T) continue;
        if(check[i] == 4) ++res; // 4가지 모두 방문한 경우에만 카운트
    }

    cout << res << "\n";
    
   return 0;
}
