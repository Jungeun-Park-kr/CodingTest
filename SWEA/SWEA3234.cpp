#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int N, weight[1000], cnt, sum;
bool selected[1000];
int expo[]={1,2,4,8,16,32,64,128,256,512};
int facto[]={0,1,2,6,24,120,720,5040,40320,362880};

void check(int idx, int left, int right) {
    if(idx == N) { ++cnt; return; } // 종료조건

    if(left > (sum/2)) { // left가 절반 이상이면 나머지 값들은 그냥 아무자리나 가면 됨
        cnt += (expo[N-idx] * facto[N-idx]);
        return;
    }
    for(int i=0; i<N; ++i) {
        if(selected[i]) continue;
        selected[i] = true;
        check(idx+1, left+weight[i], right); // 왼쪽에 넣었을 경우 확인   
        if(right+weight[i] <= left) { // 오른쪽에 올려도 되는 경우
            check(idx+1, left, right+weight[i]); // 오른쪽에 넣었을 경우 확인
        }
        selected[i] = false;
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int test_case, T;
	freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case, sum = 0, cnt = 0)
	{
        cin >> N;
        memset(selected, 0, sizeof(bool)*N);
        for(int i=0; i<N; ++i)  {
            cin >> weight[i];
            sum += weight[i];
        }
        check(0, 0, 0);
        cout << "#"<< test_case << " " << cnt << "\n";
	}
	return 0;
}