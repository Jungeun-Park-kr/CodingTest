#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, crain[51]; vector<int> box;
int main(void)
{
    int tmp;
    cin >> N; // 크레인 개수
    for(int i=0; i<N; ++i) cin >> crain[i]; // 각 크레인 별 최대 무게
    cin >> M; // 박스 개수
    for(int i=0; i<M; ++i) { 
        cin >> tmp;
        box.push_back(tmp);
    } // 각 박스별 무게
    sort(box.begin(), box.end()); // 오름차순 정렬
    sort(crain, &crain[N]);

    int targetBox, cnt = 0, adjust;
    bool isAvailable;
    while(true) {
        if(box.size() == 0) { // 더이상 옮길 박스 없으면 프로그램 종료
            cout << cnt << "\n";
            return 0;
        }
        ++cnt;
        isAvailable = false; // 옮길 수 있는 박스 없음
        for(int i=0; i<N; ++i) {
            targetBox = -1;
            adjust = 999999999;
           // cout << i << "번 크레인 ) ";
            for(int j=0; j<box.size(); ++j) {
                if(box[j] <= crain[i] && abs(crain[i]-box[j]) < adjust) { //가장 딱맞게 들 수 있는 박스 선택
                    adjust = abs(crain[i]-box[j]);
                    targetBox = j; // 박스 들 수 있는 경우
                }
            }
            if(targetBox != -1) { 
                //cout <<targetBox<<"번째 상자 옮김\n";
                box.erase(box.begin()+targetBox); // 벡터에서 삭제
                isAvailable =true;
            }
        }
        if(!isAvailable) { // 박스 못 옮기는 경우
            cout << -1 << "\n";
            return 0;
        }
    }
    return 0;
}