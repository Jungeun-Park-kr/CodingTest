#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;
int T, N;
map <string, pair<string, int> > friends;
string getParent(string a) { // 최상위 이름 리턴
    auto iter = friends.find(a);
    if(iter == friends.end()) { // 없을경우 삽입
        friends.insert(make_pair(a, make_pair(a, 1)));
        return a;
    }
    if (a == friends[a].first) return a;
    return friends[a].first = getParent(friends[a].first); // 경로압축
}

int unionParent(string a, string b) { // 합친 후 집합 크기 리턴
    a = getParent(a);
    b = getParent(b);
    if(a == b) return friends[a].second;
    if(friends[a].second > friends[b].second) {
        friends[b].first = a;
        friends[a].second += friends[b].second;
        friends[b].second = friends[a].second;
    } else {
        friends[a].first = b;
        friends[b].second += friends[a].second;
        friends[a].second = friends[b].second;
    }
    return friends[a].second;
}

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    string f1, f2;
    int fi1, fi2;
    for(int t=0; t<T; ++t) {
        cin >> N;
        friends.clear();
        for(int i=0; i<N; i++) {
            cin >> f1 >> f2;
            cout << unionParent(f1, f2) << "\n"; // 부모 합치기
        }
    }
    return 0;
}