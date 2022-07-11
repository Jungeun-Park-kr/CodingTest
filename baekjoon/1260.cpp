#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
#define INF 999999
int n;
queue <int> q;

void dfs(bool **graph, bool *visited, int v) {
    if (visited[v])
        return;
    visited[v] = true;
    cout << v << " ";
    for (int i=1; i<=n; ++i) {
        if (!visited[i] && graph[v][i])
            dfs(graph, visited, i);
    }
}

void bfs(bool **graph, bool *visited, int v) {
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        cout << v << " ";
        for (int i=1; i<=n; ++i) {
            if (!visited[i] && graph[v][i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(void) 
{
    int m, v, a, b;

    cin >> n >> m >> v;

    bool **graph = new bool*[(n+1)];
    for(int i=1; i<=n; ++i) {
        graph[i] = new bool[(n+1)];
        memset(graph[i], false, sizeof(bool)*(n+1));
    }

    bool *visited = new bool[n+1];
    memset(visited, false, sizeof(bool)*(n+1));
    
    for (int i=1; i<=n; ++i) {
        graph[i][i] = true;
    }
    for (int i=0; i<m; ++i) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    dfs(graph, visited, v);
    cout << "\n";
    memset(visited, false, sizeof(bool)*(n+1));
    bfs(graph, visited, v);
    cout << "\n";

    for (int i=0; i<=n; ++i) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] visited;
    
    return 0;
}