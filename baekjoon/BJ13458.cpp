#include <iostream>
#include <vector>
using namespace std;
int N, B, C;
vector<pair<int, int> > A;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tmp;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        A.push_back(make_pair(tmp, 1)); // 응시자 수, 감독관 수 (총감독 필수)
    }
    cin >> B >> C; // 총감독, 부감독 감시 수
    unsigned long long res = 0;
    for(int i=0; i<N; i++) { // 
        A[i].first -= B; // 총감독관 수 만큼 빼기
        if(A[i].first > 0) { // 남은 인원 부감독 수만큼
            int quot = A[i].first/C;
            int rem = A[i].first%C;
            rem > 0 ? A[i].second += (quot+1) : A[i].second += quot;
        }
        res += A[i].second;
    }
    cout << res << "\n";
    return 0;
}