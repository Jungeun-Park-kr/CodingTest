#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, k, cnt;
long long randN;
vector<bool> used;
vector<int> A, randA;
long long fact[21];
int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> k;
    long long res = 0;
    vector<int> resA;
    fact[0] = 1;
    for(int i=1; i<21; i++) {
        fact[i] = i*fact[i-1];
    }
    if(k==1) { // randN 번째 수열 리턴
        cin >> randN;
        for(int i=0; i<N; i++) {
            used.push_back(false);
        }
        // (N-i-1)! 중 rand보다 크지 않은 가장 가까운 값 찾기
        for(int i=0; i<N; i++) {
            for(int j=1; j<=N; ++j) {
                if(used[j]) continue;
                if(randN > fact[N-i-1]) {
                    randN -= fact[N-i-1];
                } else {
                    resA.push_back(j);
                    used[j] = true;
                    break;
                }
            }
        }
        for(int i=0; i<resA.size(); i++) {
            cout << resA[i] << " ";
        }
        cout << endl;
    } else { // randA 수열이 몇 번째인지 리턴
        long long tmp;
        for(int i=0; i<N; i++) {
            cin >> tmp;
            randA.push_back(tmp);
            used.push_back(false);
        }
        for(int i=0; i<N; i++) {
            for(int j=1; j<randA[i]; j++) {
                if(used[j]) continue;
                res += fact[N-i-1];
            }
            used[randA[i]] = true;
        }
        cout << res+1 << "\n";
        return 0;
    }
    return 0;
}