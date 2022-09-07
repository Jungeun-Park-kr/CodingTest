#include<iostream>
#include <cstring>
#define LENGTH 56
using namespace std;
int N, M;
bool num[10][8]={{0,0,0,1,1,0,1}, {0,0,1,1,0,0,1},{0,0,1,0,0,1,1}, {0,1,1,1,1,0,1}, 
{0,1,0,0,0,1,1},{0,1,1,0,0,0,1},{0,1,0,1,1,1,1},{0,1,1,1,0,1,1},{0,1,1,0,1,1,1},{0,0,0,1,0,1,1}};
int main(int argc, char** argv)
{
	int test_case, T, startIdx = 0, endIdx = 0, idx = 0;
    string str, tmp;
    bool check[LENGTH];
    freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M;
        for(int i=0; i<N; ++i) {
            cin >> tmp;
            for(int j=0; j<M; ++j) {
                if(tmp[j] == '1') { // 1있는 경우 : 확인할 암호문이 있는 문자열
                    str = tmp;
                    endIdx = j; // 1이 있는 가장 끝 번호 체크
                }
            }
        }

       //cout << "edxIdx: "<<endIdx << ", str: "<<str<<endl;
        
        int sumOdd = 0, sumEven = 0;
        bool isOdd = true;
         // 암호문이 담겨있는 str 문자열을 bool형의 check 배열로 옮기기
        for(int i=endIdx-LENGTH+1, j=0; i<=endIdx; ++i, ++j) {
            if(str[i] == '1') check[j] = 1;
            else check[j] = 0;
        }
        // cout << "뽑아낸 암호문: ";
        // for(int i=0; i<LENGTH; ++i) {
        //     cout <<check[i] ;
        // }
        // cout << "\n";

        for(int i=0; i<LENGTH; i+=7) { // 총 8개의 숫자를 비교
            for(int j=0; j<10; ++j) { // 0~9 숫자와 비교
                if(memcmp(&check[i], num[j], 7) == 0) {
                    if(isOdd) sumOdd += j; // 홀수인 경우
                    else sumEven += j; // 짝수인 경우
                    break;
                }
            }
            isOdd = !isOdd; // 홀짝 전환
        }
        if((sumOdd*3 + sumEven)%10 == 0) 
            cout << "#" << test_case << " "<<sumOdd+sumEven << "\n";
        else cout << "#" << test_case << " 0\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}