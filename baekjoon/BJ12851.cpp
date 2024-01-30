#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;
int N, K, result, cnt=0;
bool visited[MAX];
int main(void) {
    cin >> N >> K;
    queue<pair<int, int> > q; pair<int,int>tmp; // < 횟수, 좌표 >
    q.push(make_pair(0, N));
    while(!q.empty()) {
        tmp = q.front(); q.pop();
        //cout << "방문: "<< tmp.second <<", 횟수: "<<tmp.first<< "\n";
        if(result != 0 && tmp.first > result) break;  // 종료 조건
        visited[tmp.second] = true;
        if(tmp.second == K ) {
            //cout << "동생 찾음!! 횟수:" << tmp.first <<endl;
            if(result == 0) {
                //cout << "동생 최초 찾음\n";
                result = tmp.first;
                cnt = 1;
            } else if (tmp.first == result) ++cnt; // 방법 개수는 같은 depth에서밖에 안나옴
        }
        if(tmp.second -1 >= 0 && !visited[tmp.second-1]) { // 걷는경우 X-1
            q.push(make_pair(tmp.first+1, tmp.second-1));
        }
        if(tmp.second + 1 < MAX && !visited[tmp.second+1]) { // 걷는경우 X+1
            q.push(make_pair(tmp.first+1, tmp.second+1));
        }
        if(tmp.second * 2 < MAX && !visited[tmp.second*2]) { // 순간이동 하는경우 2*X
            q.push(make_pair(tmp.first+1, tmp.second*2)); 
        }
    }

    cout << result << "\n" << cnt << "\n";

    return 0;
}
