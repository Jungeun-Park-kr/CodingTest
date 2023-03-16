#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;
int N, K, res;
bool visited[MAX];
int main(void) {
    cin >> N >> K;
    queue<pair<int, int> > q; pair<int,int> tmp;
    q.push(make_pair(N, 0));
    visited[N] = true;
    while(!q.empty()) {
        tmp = q.front(); q.pop();
        //cout << "방문: "<<tmp.first<<", 횟수: "<<tmp.second<<endl;
        if(tmp.first == K || tmp.first*2 == K) { // 정답인 경우
            res = tmp.second;
            break;
        }
        if(tmp.first * 2 < MAX && !visited[tmp.first*2]) {
            visited[tmp.first] = true;
            q.push(make_pair(tmp.first*2, tmp.second));
        }
        if(tmp.first - 1 > -1 && !visited[tmp.first-1]) {
            visited[tmp.first-1] = true;
            q.push(make_pair(tmp.first-1, tmp.second+1));
        }
        if(tmp.first + 1 < MAX && !visited[tmp.first+1]) {
            visited[tmp.first+1] = true;
            q.push(make_pair(tmp.first+1, tmp.second+1));
        }
    }
    cout << res << "\n";
    return 0;
}
