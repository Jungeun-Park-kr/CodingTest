#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> a[11]; // 간선 정보 
vector<int > pop; // 선거구, 인구 수 정보
vector<int> city; // 도시 번호 부여

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tmp, tmp2;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        pop.push_back(tmp);
        city.push_back(i+1);
    }
    for(int i=1; i<=N; i++) { // 간선 정보 저장
        cin >> tmp;
        for(int j=0; j<tmp; j++) {
            cin >> tmp2;
            a[i].push_back(tmp2);
            a[tmp2].push_back(i);
        }
    }
    vector<int> ind; // nCnum
    vector<int> sec1; // 1지역구
    vector<int> sec2; // 2지역구
    for(int num=1; num<N; num++) { // 지역구 나누는 개수
        sort(city.begin(), city.end());
        ind = vector<int> (); // 초기화
        for(int i=0; i<num; i++) ind.push_back(1); // 1지역구
        for(int i=num; i<N; i++) ind.push_back(2); // 2지역구
        do {
            sec1 = vector<int>();
            sec2 = vector<int>(); // 선거구 초기화
            for(int i=0; i<ind.size(); i++) {
                if(ind[i]==1) {
                    city[i]; // city[i] 지역 1지역구에 담기
                    sec1.push_back(city[i]);
                }else if(ind[i]==2) {
                    city[i]; // 2지역구에 담기
                    sec2.push_back(city[i]);
                }
            }
            // 각 지역구가 인접한지 확인
            for(int i=0; i<sec1.size(); i++) {
                if(a[i])
            }
            for(int j=0; j<sec2.size(); j++) {

            }
        } while(next_permutation(ind.begin(), ind.end()));

    }


    return 0;
}