#include <iostream>
using namespace std;

int main(void)
{ //for (int j=1; j<=4*num+1; ++j)
    int num;
    cin >> num;
    int *ary[4*num+1][4*num+1];
    for (int i=0; i<5; i++) { // 5줄 출력
        if (i==0 || i==4) { // 1, 5 번째줄
            for (int j=1; j<=num; j++) {
                cout << ".";
            }
        } else if (i==1||i==3) { // 2, 4 번째 줄
            ;
        }else {//문쟈ㅏ출력
            ;
        }
        for(int j=0; j<num; j++) {
            cout << ".";
        }
    }

    for (int i=1; i<5; i++) {
        if (i)
    }
}