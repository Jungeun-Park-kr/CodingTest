#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main(void)
{
    int N, T, cnt[31], res = 1, category_num = 0;
    vector <string> clothes;
    string name, category;
    cin >> T;
    for(int t=0; t<T; ++t) {
        cin >> N;
        if(N==0) { // 옷개수 0이면 결과 0
            cout << 0 << "\n";
            continue;
        }
        clothes.clear();
        memset(cnt, 0, N*sizeof(int));
        res = 1; category_num = 0;
        for(int i=0; i<N; ++i) {
            cin >> name >> category;
            clothes.push_back(category); // 옷 이름은 안넣어도 됨.. 필요X
        }
        sort(clothes.begin(), clothes.end()); // 옷 이름 순으로 정렬
        category = clothes[0];
        cnt[0] = 1;
        for(int i=1; i<N; ++i) {
            if(category.compare(clothes[i])==0) cnt[category_num]++; // 같은 옷 종류면 개수 증가
            else { // 다른 옷 종류면 인덱스 증가
                cnt[++category_num]++;
                category = clothes[i];
            }
        }
        for(int i=0; i<=category_num; ++i) res = res * (cnt[i]+1); // 각 카테고리별 개수의 곱
		cout << res - 1 << "\n";
    }
    return 0;
}