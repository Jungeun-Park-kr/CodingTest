#include <iostream>
#include <set>
using namespace std;
int N, M, parent[101]; // 부모 담음
set <int> result;
int findParent(int a) {
    if(parent[a] == a) return a;
    return findParent(parent[a]);
}
void unionParent(int a, int b) { // a, b 부모 합치기
    a = findParent(a);
    b = findParent(b);
    if(a < b) parent[b] = a;
    else if (a > b) parent[a] = b;
    return;
}
int main(void)
{
    int test_case, T, tmp1, tmp2;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        result.clear();
        cin >> N >> M;
        for(int i=1; i<=N; ++i) parent[i] = i; //초기 값은 자기자신 뿐(자기가 부모)
        for(int i=0; i<M; ++i) {
            cin >> tmp1 >> tmp2;
            unionParent(tmp1, tmp2);
        }
        for(int i=1; i<=N; ++i) result.insert(findParent(i));
        cout <<"#"<< test_case<<" " << result.size() << "\n";
    }
    return 0;
}