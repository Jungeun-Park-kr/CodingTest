#include <iostream>
#include <cstring>
using namespace std;
int N, M;
char map[51][51];
char black[8][8] = { 
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'} },
white[8][8] = {
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'} };
int main(void)
{
    string str;
    int blackCnt = 0, whiteCnt = 0, answer = 999999999;
    cin >> N >> M;
    int rowCnt = N - 8, colCnt = M-8; // 확인할 세로, 가로 횟수
    for(int i=0; i<N; ++i) {
        cin >> str;
        for(int j=0; j<M; ++j) map[i][j] = str[j];
    }

    for(int r=0; r<=rowCnt; ++r) {
        for(int c=0; c<=colCnt; ++c) {
           blackCnt = 0, whiteCnt = 0; // 시작 지점마다 색칠 수 0으로 초기화
           for(int i=0; i<8; ++i) {
               for(int j=0; j<8; ++j) {
                   if(map[i+r][j+c] != black[i][j]) ++blackCnt;
                   if(map[i+r][j+c] != white[i][j]) ++whiteCnt;
               }
           }
            if(blackCnt < answer) answer = blackCnt; // 최소 색칠수 갱신
            if(whiteCnt < answer) answer = whiteCnt;
            if(answer == 0) { // 0 나오면 바로 정답
                cout << "0\n";
                return 0;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}