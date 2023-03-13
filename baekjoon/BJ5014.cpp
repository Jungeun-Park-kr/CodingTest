#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int F, S, G, U, D; // 총 층 수, 시작 , 목표 , Up, Down
bool visited[1000001];
bool bfs() {
    queue<pair<int, int> > q; pair<int,int>tmp; // 현재 층, 움직인 횟수
    q.push(make_pair(S, 0));
    visited[S] = true;
    while(!q.empty()) {
        tmp = q.front(); q.pop();
        //cout << "현재 층:"<<tmp.first << ", cnt:"<<tmp.second<<endl;
        if(tmp.first == G) {
            cout << tmp.second << "\n";
            return true;
        }
        if(tmp.first-D > 0 && !visited[tmp.first-D]) {
            q.push(make_pair(tmp.first-D, tmp.second+1));
            visited[tmp.first-D] = true;
        }
        if (tmp.first+U <= F && !visited[tmp.first+U]) {
            q.push(make_pair(tmp.first+U, tmp.second+1));
            visited[tmp.first+U] = true;
        }
    }
    return false;
}
int main(void) {
    cin >> F >> S >> G >> U >> D;
    if(!bfs()) cout << "use the stairs\n";
    return 0;
}