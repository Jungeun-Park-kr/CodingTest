#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int N, M, flies[15][15]={0}, max=-999, diff=0, tmp=0;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case, max=-999)
	{
        cin >> N >> M;
        for (int i=0; i<N; ++i) { // 파리 수 입력
            for (int j=0; j<N; ++j)
                cin >> flies[i][j];
        }
        diff = N-M+1; // 파리 맵 내에서 움직일 수 있는 수
        for (int i=0; i<diff; ++i) {
            for (int j=0; j<diff; ++j, tmp=0) {
                for (int k=i; k<i+M; ++k) {
                    for (int l=j; l<j+M; ++l) {
                        tmp += flies[k][l];
                    }
                }
                if (max < tmp)  max = tmp;
                    
            }
                
        }
        cout << "#"<<test_case<<" "<<max<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}