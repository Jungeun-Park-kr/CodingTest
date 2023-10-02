#include <iostream>
using namespace std;
int N, M;
int parent[201], plan[1001];

int getParent(int a) {
    if(parent[a] == a) return a;
    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool compareParent(int a, int b) {
    if(getParent(a) == getParent(b)) return true;
    else return false;
}

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N; i++) parent[i] = i;
    int connected;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> connected;
            if(i!=j && connected == 1) {
                unionParent(i+1, j+1);
            }
        }
    }
    for(int i=0; i<M; i++) {
        cin >> plan[i];
    }
    for(int i=1; i<M; i++) {
        if(compareParent(plan[i-1], plan[i])) continue;
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}