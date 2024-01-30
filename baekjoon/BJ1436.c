#include <stdio.h>
#include <string.h>
int main(void) {
    int N, cnt = 0;
    long long num = 666;
    char six[4] = "666", buf[256];
    scanf("%d", &N);
    for(num = 666; cnt<N; ++num) {
        sprintf(buf, "%lld", num); // 숫자 -> 문자 변환
        int len = strlen(buf); // 문자열 길이 확인
        for(int j=0; j<=len-3; ++j) {  // 문자열 길이만큼 6 3연속 확인
            if(strncmp(buf+j, six, 3) == 0) { // // 6이 3연속 있는 숫자인지 검사
                ++cnt;
                break;
            }
        }
        if(cnt == N) break; // 정답이면 빠져나가기
    }
    printf("%lld\n", num);
    return 0;
}