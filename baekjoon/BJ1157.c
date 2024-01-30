#include <stdio.h>
#include <string.h>
int main(void) {
    char str[1000001], maxChar;
    int cnt[27], maxCnt = 0;
    scanf("%s", str);
    int len = strlen(str);

    char idx = 0;
    for(int i=0; i<len; ++i) {
        char c = str[i];
        if(c > 'Z') { //소문자 -> 대문자로 바꾸기
            c -= 32;
        }
        idx = c-'A';
        ++cnt[idx];
        if(cnt[idx] > maxCnt) {
            maxCnt = cnt[idx];
            maxChar = c;
        }
    }
    int duplicate = 0;
    for(int i=0; i<27; ++i) {
        if(cnt[i] == maxCnt) ++duplicate;
    }
    if(duplicate > 1) printf("?\n");
    else printf("%c\n", maxChar);
    return 0;
}
