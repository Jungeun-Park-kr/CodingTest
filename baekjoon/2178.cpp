#include <iostream>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;

int main(void)
{
    int n, m;
    queue <pair<int, int> > q;
    cin >> n >> m;
    int **maze = new int*[(n+1)];
    bool **visited = new bool*[(n+1)];

    for (int i=0; i<=n+1; ++i) {
        maze[i] = new int[(m+1)];
        visited[i] = new bool[(m+1)];
        memset(maze[i], false, sizeof(int)*(m+2));
        memset(visited[i], false, sizeof(bool)*(m+2));
    }
    char tmp;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            scanf("%1d", &maze[i][j]);
        }
    }
    
    q.push(make_pair(1,1));
    pair<int, int>start;
    int x, y;
    while(!q.empty()) {
        start = q.front();
        q.pop();
        x = start.first; y = start.second;
        visited[x][y] = true;
        
        if (maze[x+1][y] && !visited[x+1][y]) { // 우
            q.push(make_pair(x+1, y));
            visited[x+1][y] = true;
            maze[x+1][y] = maze[x][y]+1;
        }
        if (maze[x-1][y] && !visited[x-1][y]) { // 좌
            q.push(make_pair(x-1,y));
            visited[x-1][y]=true;
            maze[x-1][y] = maze[x][y]+1;
        }
         if (maze[x][y+1] && !visited[x][y+1]) { // 상
            q.push(make_pair(x, y+1));
            visited[x][y+1] = true;
            maze[x][y+1] = maze[x][y]+1;
        }
        if (maze[x][y-1] && !visited[x][y-1]) { // 하
            q.push(make_pair(x,y-1));
            visited[x][y-1]=true;
            maze[x][y-1] = maze[x][y]+1;
        }
    }
    cout << maze[n][m]<< "\n";

    return 0;
}