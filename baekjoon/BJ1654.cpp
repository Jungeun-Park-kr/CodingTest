#include <iostream>
#include <algorithm>
using namespace std;
int K, N, lan[10001];
int main(void) {
    cin >> K >> N;
    for(int i=0; i<K; ++i) cin >> lan[i];
    sort(&lan[0], &lan[K]);
    long long min = 1, max = lan[K-1], mid = (min+max)/2; 
    int num = 0, answer = 0;
    while(min <= max) { // 이분 탐색
        mid = (min+max)/2; 
        num = 0;
        for(int i=0; i<K; ++i) num += lan[i]/mid; // 자를 수 있는 랜선 개수 구하기
        if(num < N) max = mid-1;  // 더 작게 잘라야 함
        else { // 더 크게 잘라야 함 (num >= N)
            min = mid+1;
            if(answer < mid) answer = mid;
        }
    }
    cout << answer << "\n";
    return 0;
}