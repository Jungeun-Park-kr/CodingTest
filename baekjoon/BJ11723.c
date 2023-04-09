#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int M;
bool S[21];
int main(void) {
    char cmd[20];
    int num;
    scanf("%d", &M);
    for(int i=0; i<M; ++i) {
        scanf("%s", cmd);
        if(strcmp(cmd, "add")==0) {
            scanf("%d", &num);
            S[num] = true;
        }else if (strcmp(cmd, "remove") == 0) {
            scanf("%d", &num);
            S[num] = false;
        } else if (strcmp(cmd, "check")==0) {
            scanf("%d", &num);
            if(S[num]) printf("1\n");
            else printf("0\n");
        }else if (strcmp(cmd, "toggle") == 0) {
            scanf("%d", &num);
            if(S[num]) S[num] = false;
            else S[num] = true;
        }else if (strcmp(cmd, "empty") == 0) {
            for(int j=1; j<=20; ++j) S[j] = false;
        } else if (strcmp(cmd, "all") == 0) {
            for(int j=1; j<=20; ++j) S[j] = true;
        }
        //printf("cmd :%s, S[%d]:%d\n", cmd, num, S[num]);
    }
    return 0;
}
