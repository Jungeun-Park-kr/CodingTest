#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, M, T, A[21], B[21];
    int diff = 0, sum = 0, tmp = 0; 
    cin >> T;
    for (int i=1; i<=T; ++i, sum=0, tmp=0) {
        cin >> N >> M; // N: Ai배열 크기, M: Bj배열 크기
        for(int j=0; j<N; ++j) 
            cin >> A[j];
        for(int j=0; j<M; ++j) 
            cin >> B[j];

        diff = abs(N-M)+1; // A,B 길이 차이
        if (N == M) { // A, B 길이 동일
            for(int k=0; k<N; ++k) 
                sum += A[k]*B[k];
        } else if (N < M) { // A가 더 짧은 경우
            for(int k=0, tmp=0; k<diff; ++k, tmp=0) { // 차이만큼 이동 가능
                for (int l=0; l<N; ++l) // 각 자릿수 곱셈 더하기
                    tmp += A[l]*B[l+k];
                if (tmp >= sum) sum = tmp; //결과 값 저장
            }
        } else { // B가 더 짧은 경우
            for(int k=0; k<diff; ++k, tmp=0) { // 차이만큼 이동 가능
                for (int l=0; l<M; ++l) // 각 자릿수 곱셈 더하기
                    tmp += A[l+k]*B[l];
                if (tmp >= sum) sum = tmp; //결과 값 저장
            }
        }
        // 정답 출력
        cout << "#" << i << " " << sum << "\n";
    }

    return 0;
}