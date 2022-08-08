#include<iostream>
#include<cstring>
int student[1001];
int cnt[101];
using namespace std;

int main(int argc, char** argv)
{
	int test_case, max_score = -1, answer = -1;
	int T;
	freopen("input2.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case, max_score = -1, answer = -1)
	{
        memset(student, 0, sizeof(int)*1001);
        memset(cnt, 0, sizeof(int)*101);
        for(int i=0; i<1001; ++i) {
            cin >> student[i];
            cnt[student[i]] += 1;
        }

        for(int i=0; i<101; ++i) {
            if(max_score <= cnt[i]) {
                max_score = cnt[i];
                answer = i;
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}