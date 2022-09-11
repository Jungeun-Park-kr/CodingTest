#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int N, K, n;
set <long, greater<long> > numbers; //내림차순 중복제거
string tmp;
void makeNum() { // tmp에 있는 숫자를 n개씩 4등분 해서 벡터에 넣기
    char tmp_num[30];
    
    strncpy(tmp_num, tmp.c_str(), sizeof(char)*n);
    numbers.insert(strtol(tmp_num, NULL, 16));

    strncpy(tmp_num, &tmp[n*1], n);
    numbers.insert(strtol(tmp_num, NULL, 16));

    strncpy(tmp_num, &tmp[n*2], n);
    numbers.insert(strtol(tmp_num, NULL, 16));

    strncpy(tmp_num, &tmp[n*3], n);
    numbers.insert(strtol(tmp_num, NULL, 16));

}
int main(int argc, char** argv)
{
	int test_case, T;
	freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> K;
        n = N / 4;
        numbers.clear();
        cin >> tmp;
        for(int i=0; i<=n; ++i) { // rotate 횟수
            // 4등분 해서 만들어진 숫자를 벡터에 넣기
            makeNum();
            // 다음 rotate      
            rotate(tmp.rbegin(), tmp.rbegin()+1, tmp.rend()); // string을 오른쪽으로 한칸 밀기
        }
        set<long> :: iterator iter;
       cout << "#" << test_case <<" " << *next(numbers.begin(), K-1) << "\n"; // K번째 큰 수 출력
	}
	return 0;
}