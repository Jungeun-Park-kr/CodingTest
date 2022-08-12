#include <cstring>
#include <iostream>
using namespace std;
int N=100, num;
int ary1[100], ary2[100];
bool visited[100][100], res;
void dfs(int s, int e) { 
    if (visited[s][e]) return;
    visited[s][e] = true;
    if (e == 99) {
        res = true;
        return;
    }
    if (!visited[e][ary1[e]] && (ary1[e] != -1))    dfs(e, ary1[e]);
    if (!visited[e][ary2[e]] && (ary2[e] != -1))    dfs(e, ary2[e]);
}
int main(int argc, char** argv)
{
    int test_case;
    int T = 10, t, tmp1, tmp2;
    for (test_case = 1; test_case <= T; ++test_case, res = false)    {
        cin >> t >> num;
        memset(ary1, -1, sizeof(int) * 100);
        memset(ary2, -1, sizeof(int) * 100);
        memset(visited, 0, sizeof(visited));
 
        for (int i = 0; i < num; ++i) {
            cin >> tmp1 >> tmp2;
            if (ary1[tmp1] != -1) ary2[tmp1] = tmp2;
            else    ary1[tmp1] = tmp2;
        }
        if (ary1[0] != -1) dfs(0, ary1[0]); 
        if (!res && (ary2[0] != -1)) dfs(0, ary2[0]); // 이미 경로가 있으면 더 탐색할 필요가 없음
        cout << "#" << test_case << " " << res << "\n";
    }
    return 0;
}