#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, Onum[5];
vector<char> O;
vector<int> A;
int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int tmp;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    for(int i=0; i<4; i++) {
        cin >> Onum[i];
    }
    for(int i=0; i<Onum[0]; i++) O.push_back('+');
    for(int i=0; i<Onum[1]; i++) O.push_back('-');
    for(int i=0; i<Onum[2]; i++) O.push_back('*');
    for(int i=0; i<Onum[3]; i++) O.push_back('/');
    int resMin = 2100000000;
    int resMax = -2100000000;
    sort(O.begin(), O.end()); // 연산자 정렬
    do {
        // 사칙연산 순서대로 계산
        tmp = A[0];
        for(int i=0; i<O.size(); i++) {
            switch(O[i]) {
            case '+':
                tmp += A[i+1];
                break;
            case '-' :
                tmp -= A[i+1];
                break;
            case '*':
                tmp *= A[i+1];
                break;
            case '/':
                tmp /= A[i+1];
            }
        }
        resMin = min(resMin, tmp);
        resMax = max(resMax, tmp);
    } while(next_permutation(O.begin(), O.end()));
    cout << resMax << "\n" << resMin << "\n";
    return 0;
}