#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int N, K, cnt=0;
    bool check=true, puzzle[17][17] = {0,};
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case, cnt=0)
	{
        cin >> N >> K;

        for (int i=1; i<=N; ++i) { // 문제입력
            for (int j=1; j<=N; ++j) 
                cin >> puzzle[i][j]; // 흰:1 검 0
        }
        bool emptyr[K+2];
        memset(emptyr, true, sizeof(bool)*(K+2));
        emptyr[0] = emptyr[K+1] = false; // 가장 끝은 검정색(0)

        // 가로줄 확인
        for (int i=0; i<=N; ++i) {
            for (int j=0; j<=N-K+1; ++j) {
                if(equal((puzzle[i]+j), (puzzle[i]+K+j+2), emptyr)) {
                    ++cnt;
                }
            }
        }
        // 세로줄 확인
        for (int i=0; i<=N; ++i) {
            for (int j=0; j<=N-K+1; ++j, check=true) {
                for (int k=0; k<K; ++k) { // K만큼 흰색
                    if (!puzzle[j+k][i])
                        check = false;
                }
                if (check&&(!puzzle[j-1][i] && !puzzle[j+K][i])) { // 양 끝 검정색
                    ++cnt;
                }
            
            }
        }
        
        cout <<"#" << test_case << " " << cnt << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}