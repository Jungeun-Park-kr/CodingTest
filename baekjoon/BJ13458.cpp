#include <iostream>
using namespace std;
int A[1000001], N, B, C;
int main(void) {
    unsigned long long answer = 0;
    cin >> N; // 고사장 수
    for(int i=0; i<N; ++i) cin >> A[i]; // 시험 인원
    cin >> B >> C; // 총감독 감시인원, 부감독 감시인원

    for(int i=0; i<N; ++i) {
        A[i]-=B;
        ++answer;
        if(A[i] > 0) {
            int quot = A[i]/C, rem = A[i]%C;
            if(rem != 0) answer += quot+1;
            else answer += quot;
        }
    }
    

    cout << answer << "\n";
}
