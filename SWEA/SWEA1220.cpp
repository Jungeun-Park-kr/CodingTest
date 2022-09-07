#include<iostream>
#include <algorithm>
using namespace std;
int N;
int table[100][100];
int main(int argc, char** argv)
{
	int test_case;
    int num = 0;
    bool new_cnt = true, two_counted = false;
    int T = 10;
	freopen("input4.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case, num=0)
	{
        cin >> N;
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                cin >> table[j][i]; // 0:empty, 1:N, 2:S 
            }
        }
        for(int i=0; i<N; ++i) {
            //int cnt = 0;
            new_cnt = false;    two_counted = false;
            for(int j=0; j<N; ++j) {
                if (table[i][j] == 1) { // 1이 나온 경우 : 세로운 카운트 시작
                    new_cnt = true;
                    two_counted = false;
                } 
                else if(new_cnt && table[i][j] == 2) { // 1이 이미 나온 후 처음 2 나오면 카운트, 그 후에 나오는 2는 무시, 1되면 다시 초기화
                    if(!two_counted) { 
                        ++num;  
                        two_counted = true;
                    }
                } 
            }
        }
        cout << "#" << test_case << " " << num << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}