#include <iostream>
using namespace std;
int n, m;
int parent[1000001]; // 각 원소의 부모를 저장

int getParent(int a) {
    if(parent[a] == a) return a;
    return parent[a] = getParent(parent[a]);
}

void unionParent(int a, int b) { // 부모 합치기
    a = getParent(a);
    b = getParent(b);
    if(a <= b) parent[b] = a;
    else       parent[a] = b;
    
}

bool compareParent(int a, int b) { // 같은 부모인지 확인
    if(getParent(a) == getParent(b)) return true;
    else return false;
}
int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<=n; i++) parent[i] = i; // 초기 : 각자가 부모
    int cmd, a, b;
    for(int i=0; i<m; i++) {
        cin >> cmd >> a >> b;
        if(cmd == 0) { // 합집합
            unionParent(a, b);
        } else { // a, b가 같은 부모인지 확인
            if(compareParent(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}