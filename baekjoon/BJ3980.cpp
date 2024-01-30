#include <iostream>
#define PLAYER_NUM 11
using namespace std;
int ability[PLAYER_NUM][PLAYER_NUM], res = -1;
bool used[PLAYER_NUM];
void check(int p, int a, int sum){ // 현재 선수 번호p, 능력치 a, 능력치 총합Sum
    for(int i=0; i<PLAYER_NUM; ++i) {
        if(ability[p+1][i]!=0 && !used[i]) {
            used[i] = true;
            check(p+1, i, sum+ability[p+1][i]);
            used[i] = false; //backtracking
        }
    }
    if(p == 10 && sum > res) res = sum;
}
int main(void) {
    int T, test_case;
    cin >> T;
    for(int t=1; t<=T; ++t, res = -1) {
        for(int i=0; i<PLAYER_NUM; ++i) {
            for(int j=0; j<PLAYER_NUM; ++j) cin >> ability[i][j];
        }
        for(int i=0; i<PLAYER_NUM; ++i) {
            if(ability[0][i]) {
                used[i] = true;
                check(0, i, ability[0][i]);
                used[i] = false;
            }
        }
        cout << res << "\n";
    }
    return 0;
}