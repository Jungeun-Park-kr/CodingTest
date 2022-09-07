#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int V, E;
bool graph[1'001][1'001];
int res[1'001];
bool res_check[1'001];
int select_victim() { // 진입차수가 없는 vertex 찾기
    int dgr_sum = 0;
    for (int i = 1; i <= V; ++i, dgr_sum = 0) {
        for (int j = 1; j <= V; ++j) {
            dgr_sum += graph[j][i];
        }
        if (dgr_sum == 0 && !res_check[i]) { // 삭제할 Vertex
            return i;
        }
    }
    return 0;
}
 
void delete_edge(int v) { // v와 관련된 모든 간선들 삭제
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (i == v || j == v)   graph[i][j] = 0;
        }
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        memset(graph, 0, sizeof(graph));
        memset(res_check, 0, sizeof(res_check));
        memset(res, 0, sizeof(res));
        int tmp1, tmp2, idx = 0, victim;
        cin >> V >> E;
        for (int i = 0; i < E; ++i) {
            cin >> tmp1 >> tmp2;
            graph[tmp1][tmp2] = true;
        }
 
        // input degree(진입 차수)이용
        for(int i=0; i<V; ++i) {
            victim = select_victim();
            res[idx++] = victim;
            res_check[victim] = true; // 또 찾지 않도록 체크
            delete_edge(victim);
        }
        cout << "#" << test_case << " ";
        for (int i = 0; i < V; ++i) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}