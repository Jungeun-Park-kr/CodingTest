#include <iostream>
#include <vector>
using namespace std;
int N, res;
vector<pair<int,int> > schedule; // <작업시간 t, 수익 p>
void dfs(int curDay, int money) {
    if(curDay >= N) { // 종료조건
        if(money > res) res = money; // 최대 이익 갱신
        return;
    }
    if(curDay+schedule[curDay].first <= N) { // 오늘 일 하는 경우
        dfs(curDay + schedule[curDay].first, (money + schedule[curDay].second));
    }
    dfs(curDay+1, money); // 오늘 일 안하는 경우
}
int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int t, p;
    for(int i=1; i<=N; i++) {
        cin >> t >> p;
        schedule.push_back(make_pair(t, p));
    }
    dfs(0, 0); // 1일차부터 확인
    cout << res << "\n";
    return 0;
}