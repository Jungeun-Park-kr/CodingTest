#include <iostream>
using namespace std;
int G, P, parent[100001];
int getParent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = getParent(parent[a]);
}
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    parent[a] = b;
}
int main(void)
{
    int cnt = 0, cur;
    cin >> G >> P;
    for (int i = 1; i <= G; ++i) parent[i] = i;
    for (int i = 0; i < P; ++i) {
        cin >> cur;
        int tmp = getParent(cur);
        if(tmp != 0) {
            unionParent(tmp, tmp-1);
            ++cnt;
        } else break;
    }
    cout << cnt << "\n";
    return 0;
}