#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, ary[7][7], ary90[7][7], ary180[7][7], ary270[7][7];
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i=0; i<N; ++i) { // 배열 입력
			for (int j=0; j<N; ++j) {
				cin >> ary[i][j];
			}
		}

		// 90도 회전
		for(int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				ary90[j][N-i-1]=ary[i][j];
			}
		}

		// 180도 회전
		for(int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				ary180[j][N-i-1]=ary90[i][j];
			}
		}

		// 270도 회전
		for(int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				ary270[j][N-i-1]=ary180[i][j];
			}
		}
		// 결과출력
		cout << "#" << test_case << "\n";
		for (int i=0; i<N; ++i, cout<<"\n") {
			for(int j=0; j<N; ++j)
				cout << ary90[i][j];
			cout << " ";
			for (int j=0; j<N; ++j)
				cout << ary180[i][j];
			cout << " ";
			for (int j=0; j<N; ++j)
				cout << ary270[i][j];
		}
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}